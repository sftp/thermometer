EESchema Schematic File Version 5
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "jeu. 02 avril 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 7000 2100 0    60   ~ 0
1(Tx)
Text Label 7000 2000 0    60   ~ 0
0(Rx)
Text Label 9300 2100 2    60   ~ 0
Reset
Text Label 7000 2200 0    60   ~ 0
2
Text Label 7000 2300 0    60   ~ 0
3(**)
Text Label 7000 2400 0    60   ~ 0
4
Text Label 7000 2500 0    60   ~ 0
5(**)
Text Label 7000 2600 0    60   ~ 0
6(**)
Text Label 7000 2700 0    60   ~ 0
7
Text Label 7000 2800 0    60   ~ 0
8
Text Label 7000 2900 0    60   ~ 0
9(**)
Text Label 7000 3000 0    60   ~ 0
10(**/SS)
Text Label 7000 3100 0    60   ~ 0
11(**/MOSI)
Text Label 7000 3200 0    60   ~ 0
12(MISO)
Text Label 9300 2600 2    60   ~ 0
A0
Text Label 9300 2700 2    60   ~ 0
A1
Text Label 9300 2800 2    60   ~ 0
A2
Text Label 9300 2900 2    60   ~ 0
A3
Text Label 9300 3000 2    60   ~ 0
A4
Text Label 9300 3100 2    60   ~ 0
A5
Text Label 9300 3200 2    60   ~ 0
A6
Text Label 9300 3300 2    60   ~ 0
A7
Text Label 9300 2400 2    60   ~ 0
AREF
Wire Wire Line
	7650 2100 7000 2100
Wire Wire Line
	7000 2000 7650 2000
Wire Wire Line
	7650 2300 7000 2300
Wire Wire Line
	7000 2400 7650 2400
Wire Wire Line
	7650 2500 7000 2500
Wire Wire Line
	7000 2600 7650 2600
Wire Wire Line
	7650 2700 7000 2700
Wire Wire Line
	7000 2800 7650 2800
Wire Wire Line
	7650 2900 7000 2900
Wire Wire Line
	7000 3000 7650 3000
Wire Wire Line
	7650 3100 7000 3100
Wire Wire Line
	7000 3200 7650 3200
Wire Wire Line
	8650 3300 9300 3300
Wire Wire Line
	9300 3200 8650 3200
Wire Wire Line
	9300 3100 8650 3100
Wire Wire Line
	8650 3000 9300 3000
Wire Wire Line
	9300 2900 8650 2900
Wire Wire Line
	9300 2800 8650 2800
Wire Wire Line
	8650 2700 9300 2700
Wire Wire Line
	9300 2600 8650 2600
Wire Wire Line
	9300 2400 8650 2400
Wire Wire Line
	7000 3300 7650 3300
$Comp
L Sensor_Temperature:DS18B20 U1
U 1 1 5B7060FA
P 5200 2000
F 0 "U1" H 4970 2046 50  0000 R CNN
F 1 "DS18B20" H 4970 1955 50  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Wide" H 4200 1750 50  0001 C CNN
F 3 "http://datasheets.maximintegrated.com/en/ds/DS18B20.pdf" H 5050 2250 50  0001 C CNN
	1    5200 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5B706248
P 5600 1750
F 0 "R1" H 5670 1796 50  0000 L CNN
F 1 "4.7k" H 5670 1705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5530 1750 50  0001 C CNN
F 3 "~" H 5600 1750 50  0001 C CNN
	1    5600 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2300 5200 2450
$Comp
L power:GND #PWR05
U 1 1 5B7069E7
P 5200 2450
F 0 "#PWR05" H 5200 2200 50  0001 C CNN
F 1 "GND" H 5205 2277 50  0000 C CNN
F 2 "" H 5200 2450 50  0001 C CNN
F 3 "" H 5200 2450 50  0001 C CNN
	1    5200 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1700 5200 1500
Wire Wire Line
	5600 1600 5600 1500
Wire Wire Line
	5600 1500 5200 1500
Connection ~ 5200 1500
Wire Wire Line
	5200 1500 5200 1400
Wire Wire Line
	5500 2000 5600 2000
Wire Wire Line
	5600 2000 5600 1900
Wire Wire Line
	8600 4900 9300 4900
Wire Wire Line
	8600 5000 9300 5000
Wire Wire Line
	8600 5200 9300 5200
Text Label 9300 5100 2    60   ~ 0
11(**/MOSI)
Text Label 9300 5200 2    60   ~ 0
12(MISO)
NoConn ~ 8600 4800
Wire Wire Line
	8150 4400 8150 4300
$Comp
L power:GND #PWR012
U 1 1 5B71D7F9
P 8150 5700
F 0 "#PWR012" H 8150 5450 50  0001 C CNN
F 1 "GND" H 8155 5527 50  0000 C CNN
F 2 "" H 8150 5700 50  0001 C CNN
F 3 "" H 8150 5700 50  0001 C CNN
	1    8150 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 5700 8150 5600
Wire Wire Line
	8600 5100 9300 5100
NoConn ~ 7700 5200
Text Label 7000 4800 0    50   ~ 0
AIN1+
Text Label 7000 4900 0    50   ~ 0
AIN1-
Text Label 7000 5000 0    50   ~ 0
AIN2+
Text Label 7000 5100 0    50   ~ 0
AIN2-
Wire Wire Line
	7000 4800 7700 4800
Wire Wire Line
	7000 4900 7700 4900
Wire Wire Line
	7000 5000 7700 5000
Wire Wire Line
	7000 5100 7700 5100
Wire Wire Line
	3150 3750 3450 3750
Wire Wire Line
	3150 3850 3450 3850
Wire Wire Line
	3150 3950 3450 3950
Wire Wire Line
	3150 4050 3450 4050
Text Label 3450 3750 2    50   ~ 0
AIN1+
Text Label 3450 3850 2    50   ~ 0
AIN1-
Text Label 3450 3950 2    50   ~ 0
AIN2+
Text Label 3450 4050 2    50   ~ 0
AIN2-
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5B794E8C
P 2950 2850
F 0 "J1" H 2950 2550 50  0000 C CNN
F 1 "POWER_IN" H 3000 2650 50  0000 C CNN
F 2 "TerminalBlock_MetzConnect:TerminalBlock_MetzConnect_Type055_RT01502HDWU_1x02_P5.00mm_Horizontal" H 2950 2850 50  0001 C CNN
F 3 "~" H 2950 2850 50  0001 C CNN
	1    2950 2850
	-1   0    0    1   
$EndComp
Text Label 3250 2550 0    60   ~ 0
Vin
$Comp
L power:GND #PWR01
U 1 1 5B799F9F
P 3250 2950
F 0 "#PWR01" H 3250 2700 50  0001 C CNN
F 1 "GND" H 3250 2800 50  0000 C CNN
F 2 "" H 3250 2950 50  0000 C CNN
F 3 "" H 3250 2950 50  0000 C CNN
	1    3250 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2750 3250 2750
Wire Wire Line
	3250 2850 3150 2850
Wire Wire Line
	3250 2850 3250 2950
$Comp
L Connector_Generic:Conn_01x04 J5
U 1 1 5B79F7BB
P 2950 5400
F 0 "J5" H 2950 5000 50  0000 C CNN
F 1 "DISP" H 2950 5100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 2950 5400 50  0001 C CNN
F 3 "~" H 2950 5400 50  0001 C CNN
	1    2950 5400
	-1   0    0    1   
$EndComp
Wire Wire Line
	3250 5100 3250 5200
Wire Wire Line
	3250 5200 3150 5200
$Comp
L power:GND #PWR03
U 1 1 5B7A127E
P 3250 5600
F 0 "#PWR03" H 3250 5350 50  0001 C CNN
F 1 "GND" H 3250 5450 50  0000 C CNN
F 2 "" H 3250 5600 50  0000 C CNN
F 3 "" H 3250 5600 50  0000 C CNN
	1    3250 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 5300 3250 5300
Wire Wire Line
	3250 5300 3250 5600
Wire Wire Line
	3150 5400 3950 5400
Wire Wire Line
	3150 5500 3950 5500
Text Label 3300 5400 0    50   ~ 0
DISP_DIO
Text Label 3300 5500 0    50   ~ 0
DISP_CLK
Text Label 3950 5500 2    60   ~ 0
A5
Text Label 3950 5400 2    60   ~ 0
A4
Wire Wire Line
	5600 2000 6550 2000
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5B7C5328
P 4850 3750
F 0 "J3" H 4850 3400 50  0000 C CNN
F 1 "EXT_DS1" H 4850 3500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4850 3950 50  0001 C CNN
F 3 "~" H 4850 3750 50  0001 C CNN
	1    4850 3750
	-1   0    0    1   
$EndComp
Text Label 5750 2000 0    50   ~ 0
SENS_INT_DS
Wire Wire Line
	5050 3850 5200 3850
Wire Wire Line
	5200 3850 5200 4050
$Comp
L power:GND #PWR07
U 1 1 5B7CC812
P 5200 4050
F 0 "#PWR07" H 5200 3800 50  0001 C CNN
F 1 "GND" H 5205 3877 50  0000 C CNN
F 2 "" H 5200 4050 50  0001 C CNN
F 3 "" H 5200 4050 50  0001 C CNN
	1    5200 4050
	1    0    0    -1  
$EndComp
Text Label 5650 3750 0    50   ~ 0
SENS_EXT_DS1
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 5B7D26D8
P 4850 5350
F 0 "J4" H 4850 5000 50  0000 C CNN
F 1 "EXT_DS2" H 4850 5100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4850 5350 50  0001 C CNN
F 3 "~" H 4850 5350 50  0001 C CNN
	1    4850 5350
	-1   0    0    1   
$EndComp
Wire Wire Line
	5050 5450 5200 5450
Wire Wire Line
	5200 5450 5200 5650
$Comp
L power:GND #PWR09
U 1 1 5B7D26EA
P 5200 5650
F 0 "#PWR09" H 5200 5400 50  0001 C CNN
F 1 "GND" H 5205 5477 50  0000 C CNN
F 2 "" H 5200 5650 50  0001 C CNN
F 3 "" H 5200 5650 50  0001 C CNN
	1    5200 5650
	1    0    0    -1  
$EndComp
Text Label 5650 5350 0    50   ~ 0
SENS_EXT_DS2
Connection ~ 5600 2000
Text Label 6550 2000 2    60   ~ 0
2
Text Label 6550 3750 2    60   ~ 0
4
$Comp
L Device:R R2
U 1 1 5B7BC042
P 5400 3400
F 0 "R2" H 5470 3446 50  0000 L CNN
F 1 "4.7k" H 5470 3355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5330 3400 50  0001 C CNN
F 3 "~" H 5400 3400 50  0001 C CNN
	1    5400 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3050 5200 3150
Wire Wire Line
	5400 3250 5400 3150
Wire Wire Line
	5400 3150 5200 3150
Wire Wire Line
	5400 3750 6550 3750
$Comp
L Device:R R3
U 1 1 5B7CE5AD
P 5400 5000
F 0 "R3" H 5470 5046 50  0000 L CNN
F 1 "4.7k" H 5470 4955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5330 5000 50  0001 C CNN
F 3 "~" H 5400 5000 50  0001 C CNN
	1    5400 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 4750 5400 4750
Wire Wire Line
	5200 4750 5200 4650
Wire Wire Line
	5400 5150 5400 5350
Wire Wire Line
	5400 5350 6550 5350
Wire Wire Line
	5200 4750 5200 5250
Wire Wire Line
	5200 5250 5050 5250
Connection ~ 5200 4750
Connection ~ 5400 5350
Wire Wire Line
	5200 3150 5200 3650
Wire Wire Line
	5200 3650 5050 3650
Connection ~ 5200 3150
Connection ~ 5400 3750
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5B81E12F
P 8150 2600
F 0 "A1" H 7850 1650 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 8700 1650 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 8300 1650 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 8150 1600 50  0001 C CNN
	1    8150 2600
	1    0    0    -1  
$EndComp
Text Label 8050 1300 2    60   ~ 0
Vin
Wire Wire Line
	8050 1300 8050 1400
Wire Wire Line
	8350 1400 8350 1600
Wire Wire Line
	7000 2200 7650 2200
$Comp
L power:GND #PWR010
U 1 1 5B843CFF
P 8150 3800
F 0 "#PWR010" H 8150 3550 50  0001 C CNN
F 1 "GND" H 8150 3650 50  0000 C CNN
F 2 "" H 8150 3800 50  0000 C CNN
F 3 "" H 8150 3800 50  0000 C CNN
	1    8150 3800
	1    0    0    -1  
$EndComp
Text Label 7000 3300 0    60   ~ 0
13(SCK)
NoConn ~ 8250 1600
Wire Wire Line
	8150 3800 8150 3700
Wire Wire Line
	8650 2100 8850 2100
Wire Wire Line
	5400 3550 5400 3750
Wire Wire Line
	5050 3750 5400 3750
Wire Wire Line
	5400 4750 5400 4850
Wire Wire Line
	5050 5350 5400 5350
$Comp
L power:+5V #PWR06
U 1 1 5B84A248
P 5200 3050
F 0 "#PWR06" H 5200 2900 50  0001 C CNN
F 1 "+5V" H 5215 3223 50  0000 C CNN
F 2 "" H 5200 3050 50  0001 C CNN
F 3 "" H 5200 3050 50  0001 C CNN
	1    5200 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 5B84A360
P 3250 5100
F 0 "#PWR02" H 3250 4950 50  0001 C CNN
F 1 "+5V" H 3265 5273 50  0000 C CNN
F 2 "" H 3250 5100 50  0001 C CNN
F 3 "" H 3250 5100 50  0001 C CNN
	1    3250 5100
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR08
U 1 1 5B84A39C
P 5200 4650
F 0 "#PWR08" H 5200 4500 50  0001 C CNN
F 1 "+5V" H 5215 4823 50  0000 C CNN
F 2 "" H 5200 4650 50  0001 C CNN
F 3 "" H 5200 4650 50  0001 C CNN
	1    5200 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5B84A428
P 5200 1400
F 0 "#PWR04" H 5200 1250 50  0001 C CNN
F 1 "+5V" H 5215 1573 50  0000 C CNN
F 2 "" H 5200 1400 50  0001 C CNN
F 3 "" H 5200 1400 50  0001 C CNN
	1    5200 1400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR013
U 1 1 5B84A474
P 8350 1400
F 0 "#PWR013" H 8350 1250 50  0001 C CNN
F 1 "+5V" H 8365 1573 50  0000 C CNN
F 2 "" H 8350 1400 50  0001 C CNN
F 3 "" H 8350 1400 50  0001 C CNN
	1    8350 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3600 8250 3700
Wire Wire Line
	8250 3700 8150 3700
Connection ~ 8150 3700
Wire Wire Line
	8150 3700 8150 3600
Wire Wire Line
	8650 2000 8850 2000
Wire Wire Line
	8850 2000 8850 2100
Connection ~ 8850 2100
Wire Wire Line
	8850 2100 9300 2100
Wire Wire Line
	3250 2550 3250 2750
Text Label 9300 5000 2    60   ~ 0
13(SCK)
Text Label 9300 4900 2    60   ~ 0
10(**/SS)
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5B8B6AA4
P 7800 1350
F 0 "#FLG0101" H 7800 1425 50  0001 C CNN
F 1 "PWR_FLAG" H 7600 1350 50  0000 C CNN
F 2 "" H 7800 1350 50  0001 C CNN
F 3 "~" H 7800 1350 50  0001 C CNN
	1    7800 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 1350 7800 1400
Wire Wire Line
	7800 1400 8050 1400
Connection ~ 8050 1400
Wire Wire Line
	8050 1400 8050 1600
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 5BB065BD
P 2850 1150
F 0 "H1" V 2804 1300 50  0000 L CNN
F 1 "MountingHole_Pad" V 2895 1300 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580_Pad" H 2850 1150 50  0001 C CNN
F 3 "~" H 2850 1150 50  0001 C CNN
	1    2850 1150
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 5BB08E8A
P 2850 1350
F 0 "H2" V 2804 1500 50  0000 L CNN
F 1 "MountingHole_Pad" V 2895 1500 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580_Pad" H 2850 1350 50  0001 C CNN
F 3 "~" H 2850 1350 50  0001 C CNN
	1    2850 1350
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H3
U 1 1 5BB0B4A9
P 2850 1550
F 0 "H3" V 2804 1700 50  0000 L CNN
F 1 "MountingHole_Pad" V 2895 1700 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580_Pad" H 2850 1550 50  0001 C CNN
F 3 "~" H 2850 1550 50  0001 C CNN
	1    2850 1550
	0    1    1    0   
$EndComp
$Comp
L Mechanical:MountingHole_Pad H4
U 1 1 5BB0DACD
P 2850 1750
F 0 "H4" V 2804 1900 50  0000 L CNN
F 1 "MountingHole_Pad" V 2895 1900 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3_ISO14580_Pad" H 2850 1750 50  0001 C CNN
F 3 "~" H 2850 1750 50  0001 C CNN
	1    2850 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	2750 1150 2650 1150
Wire Wire Line
	2650 1150 2650 1350
Wire Wire Line
	2750 1750 2650 1750
Connection ~ 2650 1750
Wire Wire Line
	2650 1750 2650 1900
Wire Wire Line
	2750 1550 2650 1550
Connection ~ 2650 1550
Wire Wire Line
	2650 1550 2650 1750
Wire Wire Line
	2750 1350 2650 1350
Connection ~ 2650 1350
Wire Wire Line
	2650 1350 2650 1550
$Comp
L power:GND #PWR0101
U 1 1 5BB1D310
P 2650 1900
F 0 "#PWR0101" H 2650 1650 50  0001 C CNN
F 1 "GND" H 2655 1727 50  0000 C CNN
F 2 "" H 2650 1900 50  0001 C CNN
F 3 "" H 2650 1900 50  0001 C CNN
	1    2650 1900
	1    0    0    -1  
$EndComp
Text Label 6550 5350 2    60   ~ 0
8
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5BB3D784
P 2950 3950
F 0 "J2" H 2870 3525 50  0000 C CNN
F 1 "TC_IN" H 2870 3616 50  0000 C CNN
F 2 "TerminalBlock_MetzConnect:TerminalBlock_MetzConnect_Type055_RT01504HDWU_1x04_P5.00mm_Horizontal" H 2950 3950 50  0001 C CNN
F 3 "~" H 2950 3950 50  0001 C CNN
	1    2950 3950
	-1   0    0    1   
$EndComp
$Comp
L dm_logo:dm_logo SYM1
U 1 1 5BC24F37
P 850 1350
F 0 "SYM1" H 928 1395 50  0001 L CNN
F 1 "dm_logo" H 928 1304 50  0001 L CNN
F 2 "dm_logo:dm_logo" H 850 1350 50  0001 C CNN
F 3 "" H 850 1350 50  0001 C CNN
	1    850  1350
	1    0    0    -1  
$EndComp
$Comp
L Graphic:Logo_Open_Hardware_Small LOGO1
U 1 1 5BC28411
P 850 850
F 0 "LOGO1" H 850 1125 50  0001 C CNN
F 1 "Logo_Open_Hardware_Small" H 850 625 50  0001 C CNN
F 2 "Symbol:OSHW-Symbol_6.7x6mm_SilkScreen" H 850 850 50  0001 C CNN
F 3 "~" H 850 850 50  0001 C CNN
	1    850  850 
	1    0    0    -1  
$EndComp
$Comp
L ad7705_module:ad7705_module A2
U 1 1 5D1E92B0
P 8150 4950
F 0 "A2" H 7900 4350 50  0000 C CNN
F 1 "ad7705_module" H 8550 4350 50  0000 C CNN
F 2 "ad7705_module:ad7705_module" H 8800 4350 50  0001 C CNN
F 3 "" H 8200 4950 50  0001 C CNN
	1    8150 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 5B86D9CB
P 8150 4300
F 0 "#PWR011" H 8150 4150 50  0001 C CNN
F 1 "+5V" H 8165 4473 50  0000 C CNN
F 2 "" H 8150 4300 50  0001 C CNN
F 3 "" H 8150 4300 50  0001 C CNN
	1    8150 4300
	1    0    0    -1  
$EndComp
$EndSCHEMATC