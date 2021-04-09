#include <Servo.h>
#define TRIG 3
#define ECHO 2
#define RED 11
#define GREEN 10
Servo myServo;
int pos=0;// 서보모터 각도 변수
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long distance=pulseIn(ECHO, HIGH)/58.2;
  Serial.println(distance+String("cm"));
  if(distance<30){
    //차가 가까이 옴
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    if(pos!=90){ //for문의 무한 반복 방지
      for(pos=0; pos<90; pos++){
        myServo.write(pos);
        delay(15);
      }
    }
  } else{
    //차가 멀어짐
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    delay(2000); //차량 통과를 위해 차단기 닫힘을 2초 지연, 보통 뒤에도 초음파 센서를 작창하여 사용
    if(pos!=0){ //for문의 무한 반복 방지
      for(pos=90; pos>0; pos--){
        myServo.write(pos);
        delay(15);
      }
    }
  }
  delay(100);
}
