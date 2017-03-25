#include <LiquidCrystal.h>
#define SRTBTTN_PIN A0
#define UPBTTN_PIN A3
#define DWNBTTN_PIN A2
#define SELBTTN_PIN A1
#define TRANS_PIN 2
#define BKLGHT_PIN 3

LiquidCrystal lcd(12, 10, 5, 4, 7, 6);
int timeIndicie = 0; //used in loop to decide which element of the direcly below to edit
unsigned short int time_[4] = {0,0,0,-1}; // stores seconds, minutes, hours, between photos; number of photos
bool screenOn = true;

void timelapseLoop(unsigned short int,unsigned short int);
void takephoto();
void updateMenu();
void toggleScreen();

void setup() {
  lcd.begin(8, 2);
  Serial.begin(9600);
  pinMode(SRTBTTN_PIN,INPUT);
  pinMode(UPBTTN_PIN,INPUT);
  pinMode(DWNBTTN_PIN,INPUT);
  pinMode(SELBTTN_PIN,INPUT);
  pinMode(TRANS_PIN,OUTPUT);
  digitalWrite(TRANS_PIN,LOW);
  digitalWrite(BKLGHT_PIN,HIGH);
}

void loop() {
  if (digitalRead(SRTBTTN_PIN) == HIGH){
    while(digitalRead(SRTBTTN_PIN) == HIGH)
      
    lcd.clear();
    timelapseLoop((time_[2]*60*60 + time_[1]*60 + time_[0]),time_[3]); //convert hours, minutes to seconds and send to the main 
  }
  else if (digitalRead(SELBTTN_PIN) == HIGH){ //if select button pushed, change in the indicie of array to access
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
}

void updateMenu(){ //this function updates the 
  lcd.print(time_[2]);
  lcd.print(":");
  lcd.print(time_[1]);
  lcd.print(":");
  lcd.print(time_[0]);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print(time_[3]);
  lcd.print("     ");
  lcd.home();
  delay(100);
}


void timelapseLoop(unsigned short int interval, unsigned short int photos){
  int counter = 1;
  unsigned long int tbegin = millis();
  while(counter <= photos){
    tbegin = millis();
    while ((interval) > (millis()/1000 - tbegin/1000)){
      lcd.print((interval - (millis()/1000 - tbegin/1000)));
      lcd.print(" ");
      lcd.home();
      if (digitalRead(SRTBTTN_PIN) == HIGH){
        toggleScreen();
      }
      delay(50);
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

void toggleScreen(){
  while(digitalRead(SRTBTTN_PIN) == HIGH){
          //stall infinitely while putton depressed (eliminates accidental double presses)
        }
        screenOn = !screenOn;
        if (screenOn){
          lcd.display();
          digitalWrite(BKLGHT_PIN,HIGH);
        }
        else{
          lcd.noDisplay();
          digitalWrite(BKLGHT_PIN,LOW);
        }
}


