int push;
int posX;
int posY;
int ledL=8, ledR=10;
int ledU=9, ledD=11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); //조이스틱 푸시버튼을 내부 풀업 저항 사용
  
}

void loop() {
  // put your main code here, to run repeatedly:
  push=digitalRead(2);
  posX=analogRead(A0);
  posY=analogRead(A1);
  Serial.println(String("푸시 버튼 값 : ") + push);
  Serial.println(String("VRX 값 : ") + posX);
  Serial.println(String("VRY 값 : ") + posY);
  delay(1000);
  if(posX<501 && posY<508){ //8
    digitalWrite(ledL, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledU, LOW);
    digitalWrite(ledD, LOW);
  } else if(posX>501 && posY<508){ //9
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledU, HIGH);
    digitalWrite(ledD, LOW);
  } else if(posX>501 && posY>508){ //10
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, HIGH);
    digitalWrite(ledU, LOW);
    digitalWrite(ledD, LOW);
  }else if(posX<501 && posY>508){ //11
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledU, LOW);
    digitalWrite(ledD, HIGH);
  } else if(push==0){
    digitalWrite(ledL, HIGH);
    digitalWrite(ledR, HIGH);
    digitalWrite(ledU, HIGH);
    digitalWrite(ledD, HIGH);
  } else{
    digitalWrite(ledL, LOW);
    digitalWrite(ledR, LOW);
    digitalWrite(ledU, LOW);
    digitalWrite(ledD, LOW);
  }
}
