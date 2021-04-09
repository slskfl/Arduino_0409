int soundPin=A0;
int value;
int led=9;
boolean onOff=false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(soundPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value=analogRead(soundPin);
  Serial.println(value, DEC);
  delay(100);
  if(value>70){
    onOff=!onOff;
    digitalWrite(led, onOff);
  }
}
