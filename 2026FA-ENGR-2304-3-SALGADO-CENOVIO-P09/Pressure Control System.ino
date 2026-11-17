const int sensorPin = A0;
const int compressorPin = 8;

const float targetPressure = 10.0;

void setup() {

  Serial.begin(9600);

  pinMode(compressorPin, OUTPUT);
  pinMode(sensorPin, INPUT);

  Serial.println("--- Compressor Regulation Initialized ---");
  Serial.print("Target Pressure Set To: ");
  Serial.print(targetPressure);
  Serial.println(" PSI\n");
}

void loop() {

  int sensorValue = analogRead(sensorPin);

  float currentPressure = (sensorValue / 1023.0) * 15.0;

  Serial.print("Current Pressure: ");
  Serial.print(currentPressure);
  Serial.print(" PSI");

  if (currentPressure < targetPressure) {
    digitalWrite(compressorPin, HIGH);
    Serial.println(" -> [COMPRESSOR ON]");
  } else {
    digitalWrite(compressorPin, LOW);
    Serial.println(" -> [TARGET REACHED /COMPRESSOR OFF]");
  }

  delay(500);
}
