Temperature Controlled Fan System
This project is a temperature-controlled fan system using a PIC16F877A microcontroller, LM35 temperature sensor, 2x16 LCD, 2 motors, L293D motor driver, and a keypad. The system operates as follows:

Temperature Sensing: The LM35 sensor measures temperature. If the temperature exceeds 50°C, an air intake fan turns on. If it exceeds 60°C, both intake and exhaust fans activate.

Keypad Input: A keypad is used to enter a password. The system prompts for a password and verifies it:

If correct, the LCD displays "Correct Password," then shows the current and maximum temperature.
If incorrect, the LCD displays "Wrong Password" and returns to "Enter Password."
EEPROM Storage: The maximum temperature is stored in EEPROM, ensuring data persistence even after a power loss.

Components
PIC16F877A Microcontroller
LM35 Temperature Sensor
2x16 LCD Display
2 Motors (for air intake and exhaust)
L293D Motor Driver
4x4 Keypad
EEPROM (internal to PIC16F877A)
Features
Temperature Monitoring: Real-time temperature display and fan control based on temperature thresholds.
Password Protection: Secure access to temperature information via a keypad.
Persistent Data Storage: Maximum temperature is stored in EEPROM, ensuring data is not lost during power outages.
How to Use
Connect all components as per the provided schematic.
Power up the system.
Enter the password using the keypad:
If correct, the system displays the current and maximum temperatures.
If incorrect, re-enter the password.
The system automatically controls the fans based on the sensed temperature.


Code
The source code is provided in the repository. It includes configuration settings for the PIC16F877A, LCD initialization, EEPROM read/write functions, and fan control logic.
