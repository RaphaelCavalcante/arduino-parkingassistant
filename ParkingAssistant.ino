//RGB led pins

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

//Ultrasonic pin

int echoPin = 7;
int trigPin = 6;

//Buzzer pin
int buzzer = 5;
long duration, cm;
unsigned long onDuration = 800;
int periodDuration = 800; 
unsigned long lastPeriodStart;
void setup() {
  // put your setup code here, to run once:
   pinMode(redPin, OUTPUT);
   pinMode(greenPin, OUTPUT);
   pinMode(bluePin, OUTPUT);

   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   pinMode(buzzer, OUTPUT);
   
   Serial.begin(9600);   
}

void loop() {
  // put your main code here, to run repeatedly:

  boolean far = true;
  boolean tooClose = false;
  boolean midClose = false;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  
  if (cm <= 15 && cm > 10) {
   
    
    tone(buzzer, 2000, 10);
    
    analogWrite(redPin, 200);
    analogWrite(greenPin, 200);
    
    far = false;
    midClose = true;
  }
  if (cm <= 10 && cm > 5) {
    
    tone(buzzer, 2000, 25);
    
    analogWrite(redPin, 100);
    analogWrite(greenPin, 100);
    analogWrite(bluePin, 0);
    far = false;
    midClose = true;
  }
  if (cm <= 5){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    tone(buzzer, 2000, 200);
    far = false;
    tooClose = true;
  }  
  if(!tooClose && !midClose){
      noTone(buzzer);   
  }
  if(far){
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  delay(250);
}
