
2026FA-ENGR-2304-3-SALGADO-CENOVIO-Final Project
Pressure Control and Rocket Countdown System
Project Description
This project combines a pressure control system and a rocket launch countdown using an Arduino Uno R3. The program uses a potentiometer to simulate pressure readings and controls LED indicators, an LCD display, and a simulated compressor output.
Components Used
* 1 Arduino Uno R3
* 1 Small breadboard
* 1 200 Ohm resistor
* 4 220 Ohm resistors
* 5 Red LEDs
* 1 MCP23008-based I2C LCD
* 1 Four-AA battery pack
* 1 Diode
* 2 250 kOhm potentiometers
How the Program Works
1. Pressure Control
* The potentiometer simulates pressure readings.
* The LCD displays the current pressure in PSI.
* Four LEDs indicate increasing pressure levels.
* The compressor output turns ON while pressure is below 10 PSI.
* The compressor output turns OFF when the target pressure is reached.
2. Rocket Countdown
* After reaching the target pressure, the program begins a 10-second countdown.
* The LCD displays the remaining countdown time.
* The countdown runs from 10 to 0.
3. Rocket Launch
* When the countdown finishes, the launch LED turns ON.
* The LCD displays “LAUNCH COMPLETE!”
* The program prints the completion messages to the Serial Monitor.
Arduino Pin Connections
Arduino Pin	Component
A0		Pressure potentiometer
A4		LCD SDA
A5		LCD SCL
D8		Compressor simulation output
D9		Launch LED
D10		Pressure LED 1
D11		Pressure LED 2
D12		Pressure LED 3
D13		Pressure LED 4
Software Requirements
* Arduino IDE or Tinkercad Circuits
* Adafruit_LiquidCrystal library
* Arduino Uno R3
How to Run
1. Open the project in Tinkercad Circuits.
2. Open the Arduino code editor.
3. Paste the project code.
4. Start the simulation.
5. Adjust the pressure potentiometer until it reaches 10 PSI.
6. Watch the LCD and LED indicators.
7. Observe the 10-second rocket countdown.
8. The launch LED turns ON when the countdown finishes.
Project Purpose
The purpose of this project is to demonstrate Arduino programming, analog input, digital output, LCD communication, LED control, and automated countdown sequences.
Note: The compressor is represented by a simulated digital output and does not operate a physical compressor.








