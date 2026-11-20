// ENGR 2304 Final Project - Pressure Control + Rocket Countdown (combined)
// Convention: numbers without 0x are binary (0b...). Decimal value in comments.

const int sensorPin     = A0;
const int compressorPin = 0b1000;        // pin 8: compressor
const int ledPin        = 0b1001;        // pin 9: launch LED (was 8, same as compressor)

const float targetPressure = 0b1010;     // 10 psi
const float maxPressure    = 0b1111;     // 15 psi (sensor full scale)
const int   adcMax         = 0b1111111111;   // 1023
const int   countdownStart = 0b1010;     // 10 seconds

void setup() {
  Serial.begin(0b10010110000000);        // 9600 baud

  pinMode(compressorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("--- Compressor Regulation Initialized ---");
  Serial.print("Target Pressure Set To: ");
  Serial.print(targetPressure);
  Serial.println(" PSI\n");

  // Part 1: run the compressor until the target pressure is reached
  float currentPressure = 0;
  while (currentPressure < targetPressure) {
    int sensorValue = analogRead(sensorPin);
    currentPressure = (sensorValue / (float)adcMax) * maxPressure;

    Serial.print("Current Pressure: ");
    Serial.print(currentPressure);
    Serial.print(" PSI");

    if (currentPressure < targetPressure) {
      digitalWrite(compressorPin, HIGH);
      Serial.println(" -> [COMPRESSOR ON]");
    } else {
      digitalWrite(compressorPin, LOW);
      Serial.println(" -> [TARGET REACHED / COMPRESSOR OFF]");
    }
    delay(0b111110100);                  // 500 ms
  }

  // Part 2: rocket launch countdown
  Serial.println("\nRocket Launch Simulation");
  Serial.println("Countdown starting...");
  delay(0b1111101000);                   // 1000 ms

  for (int count = countdownStart; count >= 0; count--) {
    Serial.print("Countdown: ");
    Serial.println(count);
    delay(0b1111101000);                 // 1000 ms
  }

  Serial.println("Countdown Complete!");
  Serial.println("Simulation Finished!");
  digitalWrite(ledPin, HIGH);            // launch
}

void loop() {
  // nothing here: the sequence runs once in setup()
}
