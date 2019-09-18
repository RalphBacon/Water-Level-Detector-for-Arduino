/*
	For a complete run through of this project see
	https://www.youtube.com/ralphbacon video #162
	Direct link to video: https://youtu.be/aBkPAgrOHhQ 
*/

#define beepPin 11

void setup() {

  // Serial monitor output
  Serial.begin(9600);

  // Beeper alarm
  pinMode(beepPin, OUTPUT);
  digitalWrite(beepPin, LOW); 

  // All done here
  Serial.println("Setup completed");
}

void loop() {
  // Use a C++ unsigned int to read water levle
  uint16_t waterLevel = analogRead(A0);
  Serial.println(waterLevel);

  // Sound alarm if detected
  if (waterLevel < 100){
    digitalWrite(beepPin,HIGH);
    delay(50);
    digitalWrite(beepPin,LOW);
    delay(50);
    digitalWrite(beepPin,HIGH);
    delay(50);
    digitalWrite(beepPin,LOW);
  }

  // Slow things down or the serial monitor will go mad
  delay(250);
}
