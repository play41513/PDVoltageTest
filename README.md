# PDVoltageTest
 Test five sets of voltage values for Type-C PD functionality.

## Program

# PDVoltageTest v3.2
- Notices :Copyright(c) 2023 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Added Delay parameter for startup time.
	- Read the power parameters of the E-Mark recognized by the PD board (used for DS-UCK2).

# PDVoltageTest v3.1
- Notices :Copyright(c) 2023 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Changed the log file path to: C:\ASMP\log\PDVotageTool"+INI_Desc.ININame+"\

# PDVoltageTest v3.0
- Notices :Copyright(c) 2022 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Updated UI using asynchronous methods (Message).
	- Optimized program architecture, divided into UI, Access, and Base layers.
	- Modified configuration file format and added detailed parameters for adjustment.

# PDVoltageTest v2.8 -RD
- Notices :Copyright(c) 2022 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Only in this version: Provided additional debugging messages.

# PDVoltageTest v2.8
- Notices :Copyright(c) 2022 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Added Delay parameter for switching from 20V to 5V.

# PDVoltageTest v2.7
- Notices :Copyright(c) 2021 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Only in this version: Restore the full-load test to a single pull to the specified current and read the rise value. 

# PDVoltageTest v2.6
- Notices :Copyright(c) 2021 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Modified the full-load test method:
		- If the full-load current is greater than 1A: Pull the load to "0.7A," then turn on the load and adjust the full-load current to the target value.

# PDVoltageTest v2.5
- Notices :Copyright(c) 2021 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Modified the full-load test method:
		- If the full-load current is greater than 1A: Pull the load to "1A," then turn on the load and adjust the full-load current to the target value.

# PDVoltageTest v2.4
- Notices :Copyright(c) 2020 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Modified the full-load test method (DS-UCE6):
		- If the full-load current is greater than 1A: Pull the load to "full-load current - 1A," then turn on the load and adjust the full-load current to the target value.
		- If the full-load current is less than or equal to 1A: Directly adjust the full-load current to the target value and turn on the load.

# PDVoltageTest v2.3
- Notices :Copyright(c) 2020 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Changed the log file format to CSV.

# PDVoltageTest v2.2-1
- Notices :Copyright(c) 2019 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Added Timeout parameter for switching from 20V to 5V.

# PDVoltageTest v2.2
- Notices :Copyright(c) 2019 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Changed the method of detecting device PlugIn and PlugOut from "Message" to "Polling".
	- Added log file for test records.

# PDVoltageTest v2.1.0
- Notices :Copyright(c) 2018 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Added compensation value for line loss voltage.

# PDVoltageTest v2.0.3
- Notices :Copyright(c) 2018 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Support for the 3310F model of the load generator(150W).

# PDVoltageTest v2.0.2(DS-UCC6)
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Configuration file parameters for DS-UCC6.

# PDVoltageTest v2.0.2(ini)
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Compared to v2.0.1, the program can now read configuration files to specify the voltage range for PASS.

# PDVoltageTest v2.0.2
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Option to check whether to perform full-load testing.

# PDVoltageTest v2.0.1(ini)
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Compared to v2.0.1, the program can now read configuration files to specify the voltage range for PASS.

# PDVoltageTest v2.0.1
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Before sending commands to the load generator, add the "remote" command to exit manual operation mode.

# PDVoltageTest v2.0.0
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- PD voltage values are now obtained from the load generator.
	- Added full-load current test.

# PDVoltageTest v1.2.1
- Notices :Copyright(c) 2018 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Fixture board resistor value changed, program unit voltage values adjusted accordingly.

# PDVoltageTest v1.2.0(ini)
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Compared to v1.2.0, the program can now read configuration files to specify the voltage range for PASS.

# PDVoltageTest v1.2.0
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Added voltage compensation for each voltage.
	- Changed PASS & Fail colors from text to panel.

# PDVoltageTest v1.1.1
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- HID device enumeration: Added "try..catch" mechanism.

# PDVoltageTest v1.1.0
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- UI update.
	- Voltage range for PASS can be configured.

# PDVoltageTest v1.0.0
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Test five sets of voltage values for Type-C PD functionality.

## Other Program

# PDVoltageTest for RD v1.3
- Notices :Copyright(c) 2019 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Translate the program's internal Chinese text to English for use in the English version of the OS. 

# PDVoltageTest for RD v1.2
- Notices :Copyright(c) 2019 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Fixture board resistor value changed, program unit voltage values adjusted accordingly.

# PDVoltageTest for RD v1.1
- Notices :Copyright(c) 2018 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Debug Content.

# PDVoltageTest for RD v1.0.0
- Notices :Copyright(c) 2017 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Continuous measurement TP-voltage.

# PDVoltageTest PDA1
- Notices :Copyright(c) 2018 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Type-C PD Test for IA-PDA1.

# PDVoltageTest Dock180
- Notices :Copyright(c) 2018 Leno
- Compiler :Embarcadero RAD Studio 2010 Version 14.0.3615.26342
- OS :Windows 8 ver6.3 Build 9600
- Desc :
	- Type-C PD Test for DOCK-180.