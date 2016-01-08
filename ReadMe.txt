Steps:

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