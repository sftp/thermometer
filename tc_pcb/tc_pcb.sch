EESchema Schematic File Version 5
LIBS:tc_pcb-cache
EELAYER 29 0
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
L Sensor_Temperature:DS18B20 U1
U 1 1 5D59724C
P 5600 3850
F 0 "U1" H 5370 3896 50  0000 R CNN
F 1 "DS18B20" H 5370 3805 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_W4.0mm_StaggerEven_Horizontal_FlatSideDown" H 4600 3600 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 5450 4100 50  0001 C CNN
	1    5600 3850
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J1
U 1 1 5D597F97
P 3500 3850
F 0 "J1" H 3418 3425 50  0000 C CNN
F 1 "Conn_01x05" H 3418 3516 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x05_P2.54mm_Vertical" H 3500 3850 50  0001 C CNN
F 3 "~" H 3500 3850 50  0001 C CNN
	1    3500 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5600 3550 5600 3500
Wire Wire Line
	5600 3500 5150 3500
Wire Wire Line
	5150 3500 5150 3750
Wire Wire Line
	5150 3750 3700 3750
Wire Wire Line
	5300 3850 3700 3850
Wire Wire Line
	3700 3950 5150 3950
Wire Wire Line
	5150 3950 5150 4200
Wire Wire Line
	5150 4200 5600 4200
Wire Wire Line
	5600 4200 5600 4150
Wire Wire Line
	6250 3650 6150 3650
Wire Wire Line
	6150 3650 6150 3400
Wire Wire Line
	6150 3400 4750 3400
Wire Wire Line
	4750 3400 4750 3650
Wire Wire Line
	4750 3650 3700 3650
Wire Wire Line
	6250 4050 6150 4050
Wire Wire Line
	6150 4050 6150 4300
Wire Wire Line
	6150 4300 4750 4300
Wire Wire Line
	4750 4300 4750 4050
Wire Wire Line
	4750 4050 3700 4050
Text Label 3900 4050 0    50   ~ 0
TC+
Text Label 3900 3750 0    50   ~ 0
+5v
Text Label 3900 3850 0    50   ~ 0
DQ
Text Label 3900 3950 0    50   ~ 0
GND
Text Label 3900 3650 0    50   ~ 0
TC-
$Comp
L power:+5V #PWR0101
U 1 1 5D59EA42
P 3900 2500
F 0 "#PWR0101" H 3900 2350 50  0001 C CNN
F 1 "+5V" H 3915 2673 50  0000 C CNN
F 2 "" H 3900 2500 50  0001 C CNN
F 3 "" H 3900 2500 50  0001 C CNN
	1    3900 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5D59F141
P 3450 2600
F 0 "#PWR0102" H 3450 2350 50  0001 C CNN
F 1 "GND" H 3455 2427 50  0000 C CNN
F 2 "" H 3450 2600 50  0001 C CNN
F 3 "" H 3450 2600 50  0001 C CNN
	1    3450 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 2500 3450 2600
Wire Wire Line
	3900 2500 3900 2600
Wire Wire Line
	3900 2600 4250 2600
Wire Wire Line
	4250 2600 4250 2500
Text Label 4050 2600 0    50   ~ 0
+5v
Text Label 3450 2550 0    50   ~ 0
GND
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5D59F427
P 3450 2500
F 0 "#FLG0102" H 3450 2575 50  0001 C CNN
F 1 "PWR_FLAG" H 3450 2673 50  0000 C CNN
F 2 "" H 3450 2500 50  0001 C CNN
F 3 "~" H 3450 2500 50  0001 C CNN
	1    3450 2500
	1    0    0    -1  
$EndComp
$Comp
L dm_logo:dm_logo SYM1
U 1 1 5D645762
P 850 1350
F 0 "SYM1" H 850 1250 50  0001 C CNN
F 1 "dm_logo" H 850 1450 50  0001 C CNN
F 2 "dm_logo:dm_logo" H 850 1350 50  0001 C CNN
F 3 "" H 850 1350 50  0001 C CNN
	1    850  1350
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D59ED4A
P 4250 2500
F 0 "#FLG0101" H 4250 2575 50  0001 C CNN
F 1 "PWR_FLAG" H 4250 2673 50  0000 C CNN
F 2 "" H 4250 2500 50  0001 C CNN
F 3 "~" H 4250 2500 50  0001 C CNN
	1    4250 2500
	1    0    0    -1  
$EndComp
$Comp
L tc_screws:tc_screws TC1
U 1 1 5D59ADFE
P 6450 3850
F 0 "TC1" H 6578 3901 50  0000 L CNN
F 1 "tc_screws" H 6578 3810 50  0000 L CNN
F 2 "tc_screws:tc_screws" H 6450 3850 50  0001 C CNN
F 3 "" H 6450 3850 50  0001 C CNN
	1    6450 3850
	1    0    0    -1  
$EndComp
$Comp
L Graphic:Logo_Open_Hardware_Small LOGO1
U 1 1 5D64A3FC
P 850 850
F 0 "LOGO1" H 850 1125 50  0001 C CNN
F 1 "Logo_Open_Hardware_Small" H 850 625 50  0001 C CNN
F 2 "Symbol:OSHW-Symbol_6.7x6mm_SilkScreen" H 850 850 50  0001 C CNN
F 3 "~" H 850 850 50  0001 C CNN
	1    850  850 
	1    0    0    -1  
$EndComp
$EndSCHEMATC
