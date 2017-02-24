// include the library code:
#include <LiquidCrystal.h>
#define SRTBTTN_PIN A0
#define UPBTTN_PIN A3
#define DWNBTTN_PIN A2
#define SELBTTN_PIN A1
#define TRANS_PIN 2

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 10, 5, 4, 7, 6);
int timeIndicie = 0;
unsigned short int time_[4] = {0,0,0,150}; // stores seconds, minutes, hours, number of photos
bool backlight_ = true;

void timelapsemode(int,int);
void readA();
void takephoto();
void updateMenu();

void setup() {
  lcd.begin(8, 2);
  Serial.begin(9600);
  pinMode(SRTBTTN_PIN,INPUT);
  pinMode(UPBTTN_PIN,INPUT);
  pinMode(DWNBTTN_PIN,INPUT);
  pinMode(SELBTTN_PIN,INPUT);
  pinMode(TRANS_PIN,OUTPUT);
  digitalWrite(TRANS_PIN,LOW);
  lcd.noBacklight();
}

void loop() {
  if (digitalRead(SRTBTTN_PIN) == HIGH){
    lcd.clear();
    timelapsemode((time_[2]*60*60 + time_[1]*60 + time_[0]),time_[3]);
  }
  else if (digitalRead(SELBTTN_PIN) == HIGH){
    if (timeIndicie < 3)
      timeIndicie++;
    else if(timeIndicie == 3)
      timeIndicie = 0;
  }
  else if (digitalRead(UPBTTN_PIN) == HIGH)
    time_[timeIndicie]++;
  else if ((digitalRead(DWNBTTN_PIN) == HIGH) && (time_[timeIndicie] > 0))
    time_[timeIndicie]--;
  updateMenu();
 // readA();
  
 // if (analogRead(A2) < 100)
   // takephoto();
}

void updateMenu(){
  lcd.print(time_[2]);
  lcd.print(":");
  lcd.print(time_[1]);
  lcd.print(":");
  lcd.print(time_[0]);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print(time_[3]);
  lcd.print(" ");
  lcd.home();
  delay(100);
}

/*void readA(){
  raw1 = analogRead(A0) + 1;
  raw2 = analogRead(A1) + 1;
  secs = (raw1 % 120)/2;
  hrs = (raw1 / 7200);
  mins = (raw1 / 120 - hrs*60);
  lcd.print((int)hrs);
  lcd.print(":");
  lcd.print(mins);
  lcd.print(":");
  lcd.print((int)secs);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print(raw2);
  lcd.print(" ");
  lcd.home();
  delay(100);
}*/

void timelapsemode(int interval, int photos){
  int counter = 1;
  unsigned long int tbegin = millis();
  while(counter <= photos){
    tbegin = millis();
    while ((interval) > (millis()/1000 - tbegin/1000)){
      lcd.print((interval - (millis()/1000 - tbegin/1000)));
      lcd.print(" ");
      lcd.home();
      delay(100);
    }
    takephoto();
    counter++;
    lcd.setCursor(0,1);
    lcd.print(counter-1);
    lcd.print("/");
    lcd.print(photos);
    lcd.home();
  }
  lcd.clear();
  return;
}

void takephoto(){
  digitalWrite(TRANS_PIN,HIGH);
  delay(50);
  digitalWrite(TRANS_PIN,LOW);
}


