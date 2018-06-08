const int trigpin = 9;
const int echopin = 4;
long duration;
int distance;
byte valDig = 0;
int valAnalogico = 0;
int hayPersona = 0;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = duration * 0.034 / 2;

  if (hayPersona == 0) {
    if (distance < 80) {
        hayPersona = 1;
      Serial.write(hayPersona);
      //Serial.println(hayPersona);
    }
  }
  
  if (hayPersona == 1) {
    if (distance >= 80) {
       hayPersona = 0;
     Serial.write(hayPersona);
     //Serial.println(hayPersona);
    }
     delay(500);
  }
     // Serial.println(hayPersona);
}
