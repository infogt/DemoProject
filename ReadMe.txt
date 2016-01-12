Steps to build the project:

Update state machine diagram and create XML file
- Open the file /scripts/eap/LightModule.eap or any other eap file in this folder
- Update the file
- Export to /scripts/eap/LightModule.xml

Run the perl script
- Run /scripts/perl/XmiToTestCode.pl
- This creates a file /test/test_Led_generated.cpp

Build and run the project
- Open project in eclipse
- Build (Ctrl+B / Strg+B)
- Run (Ctrl+F11 / Strg+B)

Output files
- The executable file is available at Debug/SampleProgram.exe
- The google test output is stored at Debug/GoogleTestOutput.xml
-------------------------------------------------------------------------------
Notes:
In eclipse->Run->Run Configuration->Environment: Create a new variable "GTEST_OUTPUT" with value "xml:./Debug/GoogleTestOutput.xml" to create the GTest output in XML file
Faced an issue where in there was no ouput on the console, so had to add the environment variable "PATH" with value "C:\MinGW\bin" to fix the issue