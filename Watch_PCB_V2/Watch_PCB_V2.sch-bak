EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU MCU1
U 1 1 62008335
P 4150 2750
F 0 "MCU1" H 4150 1161 50  0000 C CNN
F 1 "ATmega328P-AU" H 4150 1070 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 4150 2750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 4150 2750 50  0001 C CNN
	1    4150 2750
	1    0    0    -1  
$EndComp
$Comp
L power:VDD #PWR0101
U 1 1 6200A2B8
P 6050 1250
F 0 "#PWR0101" H 6050 1100 50  0001 C CNN
F 1 "VDD" H 6065 1423 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 6050 1250 50  0001 C CNN
F 3 "" H 6050 1250 50  0001 C CNN
	1    6050 1250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 6200A6F7
P 6500 1250
F 0 "#PWR0102" H 6500 1000 50  0001 C CNN
F 1 "GND" H 6505 1077 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 6500 1250 50  0001 C CNN
F 3 "" H 6500 1250 50  0001 C CNN
	1    6500 1250
	-1   0    0    1   
$EndComp
Text GLabel 6050 1400 3    50   Input ~ 0
Vin
Text GLabel 6500 1400 3    50   Input ~ 0
GND
Wire Wire Line
	6050 1250 6050 1300
Wire Wire Line
	6500 1250 6500 1300
$Comp
L Device:C C1
U 1 1 6200E0C1
P 6300 1300
F 0 "C1" V 6552 1300 50  0000 C CNN
F 1 "1uF" V 6461 1300 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H 6338 1150 50  0001 C CNN
F 3 "~" H 6300 1300 50  0001 C CNN
	1    6300 1300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 1300 6050 1300
Connection ~ 6050 1300
Wire Wire Line
	6050 1300 6050 1400
Wire Wire Line
	6450 1300 6500 1300
Connection ~ 6500 1300
Wire Wire Line
	6500 1300 6500 1400
Text GLabel 4150 1100 1    50   Input ~ 0
Vin
Wire Wire Line
	4150 1250 4150 1200
Wire Wire Line
	4250 1250 4250 1200
Wire Wire Line
	4250 1200 4150 1200
Connection ~ 4150 1200
Wire Wire Line
	4150 1200 4150 1100
Text GLabel 4850 4250 2    50   Input ~ 0
GND
Wire Wire Line
	4150 4250 4850 4250
$Comp
L Device:R R1
U 1 1 6200FED2
P 5500 3200
F 0 "R1" V 5293 3200 50  0000 C CNN
F 1 "10k" V 5384 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5430 3200 50  0001 C CNN
F 3 "~" H 5500 3200 50  0001 C CNN
	1    5500 3200
	0    1    1    0   
$EndComp
Text GLabel 5750 3200 2    50   Input ~ 0
Vin
Wire Wire Line
	5750 3200 5650 3200
Wire Wire Line
	4850 3050 4750 3050
Text GLabel 5400 2350 2    50   Input ~ 0
SDA
Wire Wire Line
	4850 3050 4850 3200
Wire Wire Line
	4850 3200 5350 3200
Text GLabel 5200 2950 2    50   Input ~ 0
SCL
Wire Wire Line
	4750 2850 4900 2850
Wire Wire Line
	4900 2350 5100 2350
Wire Wire Line
	4750 2950 5150 2950
$Comp
L Device:R R2
U 1 1 6201599F
P 5250 2100
F 0 "R2" V 5043 2100 50  0000 C CNN
F 1 "4.7k" V 5134 2100 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 2100 50  0001 C CNN
F 3 "~" H 5250 2100 50  0001 C CNN
	1    5250 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 2350 5100 2100
Connection ~ 5100 2350
Wire Wire Line
	5100 2350 5400 2350
Wire Wire Line
	5150 2750 5150 2950
Connection ~ 5150 2950
Wire Wire Line
	5150 2950 5200 2950
Text GLabel 5400 2100 2    50   Input ~ 0
Vin
Text GLabel 5450 2750 2    50   Input ~ 0
Vin
Wire Wire Line
	4900 2350 4900 2850
$Comp
L Device:R R3
U 1 1 62014EEF
P 5300 2750
F 0 "R3" V 5093 2750 50  0000 C CNN
F 1 "4.7k" V 5184 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5230 2750 50  0001 C CNN
F 3 "~" H 5300 2750 50  0001 C CNN
	1    5300 2750
	0    1    1    0   
$EndComp
$Comp
L Connector:Conn_01x04_Female OLED_screen1
U 1 1 6200B415
P 4900 850
F 0 "OLED_screen1" V 4838 562 50  0000 R CNN
F 1 " " V 4747 562 50  0000 R CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x04_P2.00mm_Vertical" H 4900 850 50  0001 C CNN
F 3 "~" H 4900 850 50  0001 C CNN
	1    4900 850 
	0    -1   -1   0   
$EndComp
Text GLabel 4900 1050 3    50   Input ~ 0
Vin
Text GLabel 4800 1050 3    50   Input ~ 0
GND
Text GLabel 5000 1050 3    50   Input ~ 0
SCL
Text GLabel 5100 1050 3    50   Input ~ 0
SDA
$Comp
L Connector:Conn_01x06_Female ICSP_PORT1
U 1 1 6200FF7D
P 2450 1950
F 0 "ICSP_PORT1" V 2296 2198 50  0000 L CNN
F 1 " " V 2387 2198 50  0000 L CNN
F 2 "Connector_PinHeader_2.00mm:PinHeader_1x06_P2.00mm_Vertical" H 2450 1950 50  0001 C CNN
F 3 "~" H 2450 1950 50  0001 C CNN
	1    2450 1950
	0    1    1    0   
$EndComp
Text GLabel 2250 1750 1    50   Input ~ 0
GND
Text GLabel 2350 1750 1    50   Input ~ 0
SCK
Text GLabel 2450 1750 1    50   Input ~ 0
MISO
Text GLabel 2550 1750 1    50   Input ~ 0
MOSI
Text GLabel 2650 1750 1    50   Input ~ 0
SS
Text GLabel 4750 2050 2    50   Input ~ 0
SCK
Text GLabel 4750 1950 2    50   Input ~ 0
MISO
Text GLabel 4750 1850 2    50   Input ~ 0
MOSI
Text GLabel 4750 1750 2    50   Input ~ 0
SS
$Comp
L Timer_RTC:DS3231M RTC1
U 1 1 62014A69
P 7150 2450
F 0 "RTC1" H 7150 1961 50  0000 C CNN
F 1 "DS3231M" H 7150 1870 50  0000 C CNN
F 2 "Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm" H 7150 1850 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS3231.pdf" H 7420 2500 50  0001 C CNN
	1    7150 2450
	1    0    0    -1  
$EndComp
Text GLabel 7150 2850 2    50   Input ~ 0
GND
Text GLabel 6650 2250 0    50   Input ~ 0
SCL
Text GLabel 6650 2350 0    50   Input ~ 0
SDA
Text GLabel 7050 2050 1    50   Input ~ 0
Vin
Text GLabel 7150 2050 1    50   Input ~ 0
GND
Wire Wire Line
	2150 1200 2150 1750
$Comp
L Connector:Conn_01x01_Female Left_button1
U 1 1 620194B6
P 4950 3550
F 0 "Left_button1" H 4978 3576 50  0000 L CNN
F 1 " " H 4978 3485 50  0000 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 4950 3550 50  0001 C CNN
F 3 "~" H 4950 3550 50  0001 C CNN
	1    4950 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3650 4900 3650
Wire Wire Line
	4900 3650 4900 3900
Wire Wire Line
	4900 3900 5000 3900
$Comp
L Connector:Conn_01x01_Female Right_button1
U 1 1 6201BD84
P 5200 3900
F 0 "Right_button1" H 5228 3926 50  0000 L CNN
F 1 " " H 5228 3835 50  0000 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 5200 3900 50  0001 C CNN
F 3 "~" H 5200 3900 50  0001 C CNN
	1    5200 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female Left_button_input1
U 1 1 6201D4E1
P 5800 3550
F 0 "Left_button_input1" H 5692 3325 50  0000 C CNN
F 1 " " H 5692 3416 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 5800 3550 50  0001 C CNN
F 3 "~" H 5800 3550 50  0001 C CNN
	1    5800 3550
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Female Right_button_input1
U 1 1 62020CB0
P 6050 3900
F 0 "Right_button_input1" H 5942 3675 50  0000 C CNN
F 1 " " H 5942 3766 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 6050 3900 50  0001 C CNN
F 3 "~" H 6050 3900 50  0001 C CNN
	1    6050 3900
	-1   0    0    1   
$EndComp
Text GLabel 6000 3550 2    50   Input ~ 0
GND
Text GLabel 6250 3900 2    50   Input ~ 0
GND
Wire Wire Line
	2150 1200 4150 1200
$Comp
L Connector:Conn_01x01_Female GND1
U 1 1 62029198
P 6700 1300
F 0 "GND1" H 6728 1326 50  0000 L CNN
F 1 " " H 6728 1235 50  0000 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 6700 1300 50  0001 C CNN
F 3 "~" H 6700 1300 50  0001 C CNN
	1    6700 1300
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Female VDD1
U 1 1 62029A6D
P 5850 1300
F 0 "VDD1" H 5742 1075 50  0000 C CNN
F 1 " " H 5742 1166 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x01_P1.00mm_Vertical" H 5850 1300 50  0001 C CNN
F 3 "~" H 5850 1300 50  0001 C CNN
	1    5850 1300
	-1   0    0    1   
$EndComp
$EndSCHEMATC
