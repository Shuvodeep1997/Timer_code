
#include <LiquidCrystal.h>
int echoPin = 11;
int trigPin = 12;
long duration;
int distance;
LiquidCrystal lcd(9,8, 5, 4, 3, 2);
void setup() {  

    pinMode (10, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Wash Your Hands");
}
void loop() {
  // This part of the code tells the sensor to measure distance and reads the measured data
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;

  // This "If Statement" detects if there is any object within 30 centimeters
  if (distance > 0 && distance <= 50) {
    ledtimer();
  }
}

void ledtimer() {
  digitalWrite (10, HIGH);
   digitalWrite (13, HIGH);
    digitalWrite (6, HIGH);
     digitalWrite (7, HIGH);
  delay(5000);
  /*for (int i = 6; i >= 2; i--) {
    digitalWrite (i, HIGH);
    if (i == 2) {
      digitalWrite (7, LOW);
    }
    delay(4000);
  }
  for (int i = 7; i >= 2; i--) {
    digitalWrite (i, LOW);

  }*/
  digitalWrite (10, LOW);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Wash Fingers");
  delay(9000);
  
  digitalWrite (13, LOW);
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Wash Hand Palm");
  delay(9000);
  
  digitalWrite (6, LOW);
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Wash Carefully");
  delay(9000);
  
  digitalWrite (7, LOW);
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Wash Again");
  delay(9000);
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Finish!");
  delay(7000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wash Your Hands");
}
