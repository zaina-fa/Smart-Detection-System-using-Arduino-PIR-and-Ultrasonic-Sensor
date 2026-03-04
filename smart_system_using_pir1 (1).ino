#define LED 2
#define pezo 13
#define trig 1
#define echo 11
#define temp A0
#define pir 7
long duration;
int distance;
float tempreture;
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(pezo,OUTPUT);
  pinMode(temp,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600);
 
  
}

void loop()
{
  digitalWrite(LED,LOW);
  digitalWrite(pezo,LOW);
  if(digitalRead(pir)==HIGH){
  digitalWrite(LED,HIGH);
  digitalWrite(pezo,HIGH);
  delay(1000);
  }
  else{
     digitalWrite(LED,LOW);
    digitalWrite(pezo,LOW);
  }
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  if(distance>0&&distance<30){
    digitalWrite(LED,HIGH);
    digitalWrite(pezo,HIGH);
    delay(1000);
  }
  else{
     digitalWrite(LED,LOW);
    digitalWrite(pezo,LOW);
  }
  float tempValue=analogRead(temp);
  tempreture=tempValue*(5/1023)*100;
  if(tempreture>35){
    digitalWrite(LED,HIGH);
    digitalWrite(pezo,HIGH);
    delay(1000);
  }
  else{
     digitalWrite(LED,LOW);
    digitalWrite(pezo,LOW);
  }
  Serial.print("distance");
  Serial.print(distance);
  Serial.print("cm,temp");
  Serial.print(tempreture);
  Serial.print("C");
  delay(500);
  
    
}
  