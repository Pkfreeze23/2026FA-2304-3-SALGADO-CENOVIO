int ledPin = 8;

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, LOW);
  
  Serial.println("Rocket Launch Simulation");
  Serial.println("Countdown starting...");
  delay(1000);

  
  for (int count = 10; count >= 0; count--) {
    Serial.print("Countdown: ");
    Serial.println(count);

    delay(1000);
  }
  
    Serial.println("Countdown Complete!");
    Serial.println("Simulation Finished!");

    digitalWrite(ledPin, HIGH);
  }

  void loop() {
  }
