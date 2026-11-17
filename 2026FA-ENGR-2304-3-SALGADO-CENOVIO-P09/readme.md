### **Pressure Control System \& Rocket Countdown**



#### Program Description:(PCS)

* This program is written to monitor pressure when using a analog pressure sensor that's connected through pin A0. It keeps running simulated compressor output until it reaches desired pressure which I placed at 10 PSI.



#### How the Program Works:(PCS)

1. It reads the pressure sensor which is connected to analog pin A0.
2. Will translate the sensor reading into the estimated pressure in PSI.
3. Then it compares the current pressure with the set pressure of 10 PSI.
4. Next step it turns on the compressor output when below 10 PSI and turns off once the targeted pressure is reached.
5. The pressures reading is displayed including the compressor status in the serial monitor.



#### Hardware Used (Tinkercad):(PCS)

* Arduino Uno R3
* breadboard
* wires
* LED
* Resistor 220 ohm



#### Wire Connections:(PCS)

**(Arduino Uno R3)	(Component)**

Digital pin 8		220 ohm resister

resister other end	LED long leg (+)

GND			LED short leg(-)



#### Serial Monitor:(PCS)

* The program is set to use baud rate of 9600.



#### Target Pressure:(PCS)

* Pressure is set at a target of 10.0 PSI, but can be altered inside the program depending on the situation.



#### Program Description:(RC)

* This code will display a countdown starting from 10 ending at 0 which can be seen inside the serial monitor. Then after the countdown it will display a message that tis complete, and at the same time the LED will turn on indicating the end of simulation.



#### Hardware(Tinkercad):(RC)

* Arduino Uno R3
* Breadboard
* Wires
* LED
* Resistor 220-ohm



#### Wire Connections:(RC)

**(Arduino Uno R3)	(Component)**

Digital pin 8		220 ohm resister

resister other end	LED long leg (+)

GND			LED short leg(-)









