EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "NaNo"
Date "2021-04-13"
Rev "v00"
Comp "Utn FRC"
Comment1 "Navarro Facundo, Nobile Jonathan"
Comment2 "Navarro Facundo, Nobile Jonathan"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Interface_USB:CP2102N-A01-GQFN28 U3
U 1 1 60784563
P 5750 2650
F 0 "U3" H 5750 1261 50  0000 C CNN
F 1 "CP2102N-A01-GQFN28" H 5750 1170 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_5x5mm_P0.5mm_EP3.35x3.35mm" H 6200 1450 50  0001 L CNN
F 3 "https://www.silabs.com/documents/public/data-sheets/cp2102n-datasheet.pdf" H 5800 1900 50  0001 C CNN
	1    5750 2650
	1    0    0    -1  
$EndComp
$Comp
L RF_Module:ESP32-PICO-D4 U4
U 1 1 60786FEC
P 7350 2950
F 0 "U4" H 7350 1261 50  0000 C CNN
F 1 "ESP32-PICO-D4" H 7350 1170 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-48-1EP_7x7mm_P0.5mm_EP5.3x5.3mm" H 7350 1250 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-pico-d4_datasheet_en.pdf" H 7600 1950 50  0001 C CNN
	1    7350 2950
	1    0    0    -1  
$EndComp
$Comp
L Battery_Management:LTC4055-1 U2
U 1 1 60788FE1
P 4550 1950
F 0 "U2" H 4550 2617 50  0000 C CNN
F 1 "LTC4055-1" H 4550 2526 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-16-1EP_4x4mm_P0.65mm_EP2.1x2.1mm_ThermalVias" H 4550 1050 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/4055fb.pdf" H 4550 1450 50  0001 C CNN
	1    4550 1950
	1    0    0    -1  
$EndComp
$Comp
L RF_GPS:NEO-M8M U5
U 1 1 6078AAFA
P 9150 2250
F 0 "U5" H 9150 1261 50  0000 C CNN
F 1 "NEO-M8M" H 9150 1170 50  0000 C CNN
F 2 "RF_GPS:ublox_NEO" H 9550 1400 50  0001 C CNN
F 3 "https://www.u-blox.com/sites/default/files/NEO-M8-FW3_DataSheet_%28UBX-15031086%29.pdf" H 9150 2250 50  0001 C CNN
	1    9150 2250
	1    0    0    -1  
$EndComp
$Comp
L RF:SX1273 U1
U 1 1 6078EABA
P 3300 2300
F 0 "U1" H 3300 1111 50  0000 C CNN
F 1 "SX1273" H 3300 1020 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_6x6mm_P0.65mm_EP4.8x4.8mm" H 3300 2000 50  0001 C CNN
F 3 "https://www.semtech.com/uploads/documents/sx1272.pdf" H 3300 2100 50  0001 C CNN
	1    3300 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 6079391D
P 4450 2750
F 0 "D3" H 4443 2495 50  0000 C CNN
F 1 "LED" H 4443 2586 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Castellated" H 4450 2750 50  0001 C CNN
F 3 "~" H 4450 2750 50  0001 C CNN
	1    4450 2750
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1
U 1 1 60794872
P 2500 1850
F 0 "D1" V 2539 1732 50  0000 R CNN
F 1 "LED" V 2448 1732 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric_Castellated" H 2500 1850 50  0001 C CNN
F 3 "~" H 2500 1850 50  0001 C CNN
	1    2500 1850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D4
U 1 1 607A8CE0
P 4450 2950
F 0 "D4" H 4443 2695 50  0000 C CNN
F 1 "LED" H 4443 2786 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Castellated" H 4450 2950 50  0001 C CNN
F 3 "~" H 4450 2950 50  0001 C CNN
	1    4450 2950
	-1   0    0    1   
$EndComp
$Comp
L Connector:USB_B_Micro J1
U 1 1 607AA40F
P 3050 4550
F 0 "J1" H 3107 5017 50  0000 C CNN
F 1 "USB_B_Micro" H 3107 4926 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex_47346-0001" H 3200 4500 50  0001 C CNN
F 3 "~" H 3200 4500 50  0001 C CNN
	1    3050 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D2
U 1 1 607B137A
P 3550 4500
F 0 "D2" V 3589 4382 50  0000 R CNN
F 1 "LED" V 3498 4382 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric_Castellated" H 3550 4500 50  0001 C CNN
F 3 "~" H 3550 4500 50  0001 C CNN
	1    3550 4500
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x30 J2
U 1 1 6082010F
P 4450 5550
F 0 "J2" H 4530 5542 50  0000 L CNN
F 1 "Conn_01x30" H 4530 5451 50  0000 L CNN
F 2 "lib_fp:OLED-128O064D" H 4450 5550 50  0001 C CNN
F 3 "~" H 4450 5550 50  0001 C CNN
	1    4450 5550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
