#include "Screen.h"
static uint16_t displayWidth;
static uint16_t displayHeight;

#define SCREEN_WIDTH  displayWidth  // 128 px
#define SCREEN_HEIGHT displayHeight // 64  px

namespace graphics
{

/* Llamado y declaracion del constructor*/
Screen::Screen(uint8_t address, int sda, int scl) : dispdev(address, sda, scl), ui(&dispdev){};

void drawBootScreen(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // draw an xbm image.
  // Please note that everything that should be transitioned
  // needs to be drawn relative to x and y

  display->drawXbm((((SCREEN_WIDTH-NaNo_Logo_width))/2), ((SCREEN_HEIGHT-NaNo_Logo_height-Roboto_Light_Italic_16_height)/2), 
                      NaNo_Logo_width, NaNo_Logo_height, NaNo_Logo_bits);
  // The coordinates define the center of the text
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->setFont(Roboto_Light_Italic_16);
  display->drawString(64 + x, SCREEN_HEIGHT - Roboto_Light_Italic_16_height, "NaNo");

   // Draw version in upper right
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(Custom_ArialMT_Plain_10);
  char buf[16];
  snprintf(buf, sizeof(buf), "%s%s", "v ", xstr(APP_VERSION));
  display->drawString(x + SCREEN_WIDTH - display->getStringWidth(buf), y + SCREEN_HEIGHT - 10, buf);

}

void Screen::setup()
{
    // Initialising the UI will init the display too.
    ui.init();

    // The ESP is capable of rendering 60fps in 80Mhz mode
    // but that won't give you much time for anything else
    // run it in 160Mhz mode or just set it to 30 fps
    ui.setTargetFPS(60);

    // Don't show the page swipe dots while in boot screen.
    ui.disableAllIndicators();

    // You can change the transition that is used
    // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
    ui.setFrameAnimation(SLIDE_LEFT);
    
    // Require presses to switch between frames.
    ui.disableAutoTransition();

    // Add frames
    static FrameCallback bootFrames[] = {drawBootScreen};
    static const int bootFrameCount = sizeof(bootFrames) / sizeof(bootFrames[0]);
    ui.setFrames(bootFrames, bootFrameCount);

    // Add overlays
    //ui.setOverlays(overlays, overlaysCount);

    
    displayWidth  = dispdev.width();
    displayHeight = dispdev.height();

#ifdef SCREEN_MIRROR
    dispdev.mirrorScreen();
#elif defined(SCREEN_FLIP_VERTICALLY)
    dispdev.flipScreenVertically();
#endif
}

int32_t Screen::runOnce()
{
    // If we don't have a screen, don't ever spend any CPU for us.
    if (!useDisplay) {
        enabled = false;
        return RUN_SAME;
    }

    // Show boot screen for first 3 seconds, then switch to normal operation.
    static bool showingBootScreen = true;
    if (showingBootScreen && (millis() > 5000)) {
        DEBUG_MSG("Done with boot screen...\n");
        stopBootScreen();
        showingBootScreen = false;
    }

    // Process incoming commands.
    for (;;) {
        ScreenCmd cmd;
        if (!cmdQueue.dequeue(&cmd, 0)) {
            break;
        }
        switch (cmd.cmd) {
        case Cmd::SET_ON:
            handleSetOn(true);
            break;
        case Cmd::SET_OFF:
            handleSetOn(false);
            break;
        case Cmd::ON_PRESS:
            handleOnPress();
            break;
        case Cmd::START_BLUETOOTH_PIN_SCREEN:
            handleStartBluetoothPinScreen(cmd.bluetooth_pin);
            break;
        case Cmd::START_FIRMWARE_UPDATE_SCREEN:
            handleStartFirmwareUpdateScreen();
            break;
        case Cmd::STOP_BLUETOOTH_PIN_SCREEN:
        case Cmd::STOP_BOOT_SCREEN:
            setFrames();
            break;
        case Cmd::PRINT:
            handlePrint(cmd.print_text);
            free(cmd.print_text);
            break;
        default:
            DEBUG_MSG("BUG: invalid cmd\n");
        }
    }

    if (!screenOn) { // If we didn't just wake and the screen is still off, then
                     // stop updating until it is on again
        enabled = false;
        return 0;
    }

    // this must be before the frameState == FIXED check, because we always
    // want to draw at least one FIXED frame before doing forceDisplay
    ui.update();

    // Switch to a low framerate (to save CPU) when we are not in transition
    // but we should only call setTargetFPS when framestate changes, because
    // otherwise that breaks animations.
    if (targetFramerate != IDLE_FRAMERATE && ui.getUiState()->frameState == FIXED) {
        // oldFrameState = ui.getUiState()->frameState;
        DEBUG_MSG("Setting idle framerate\n");
        targetFramerate = IDLE_FRAMERATE;
        ui.setTargetFPS(targetFramerate);
        forceDisplay();
    }

    // While showing the bootscreen or Bluetooth pair screen all of our
    // standard screen switching is stopped.
    if (showingNormalScreen) {
        // standard screen loop handling here
    }

    // DEBUG_MSG("want fps %d, fixed=%d\n", targetFramerate,
    // ui.getUiState()->frameState); If we are scrolling we need to be called
    // soon, otherwise just 1 fps (to save CPU) We also ask to be called twice
    // as fast as we really need so that any rounding errors still result with
    // the correct framerate
    return (1000 / targetFramerate);
}

void Screen::draw()
{
    ui.update();
}
  
} // namespace graphics
