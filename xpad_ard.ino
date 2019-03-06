#include <LiquidCrystal.h>


//display pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int rgbypin [4] = {9,8,6,7};
unsigned long rgbyrefr [4] = {0,0,0,0};

//for serial comms
int serin;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (Serial.available()>0){
    serin = Serial.read();
  }
  lcd.begin(16, 2);
  lcd.leftToRight();
  lcd.setCursor(0,0);
  lcd.print("Signal received:");
  lcd.setCursor(0,1);
  for(int i = 0; i < 4; i++){
    pinMode(rgbypin[i], OUTPUT);
  }
  
  /*pinMode(rgbypin[0], OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(yellowpin, OUTPUT);*/
}

void loop() {
  if (Serial.available()>0){
    serin = Serial.read();
    lcd.print(char(serin));
    if (char(serin) == 'B'){
      digitalWrite(rgbypin[0], HIGH);
      rgbyrefr[0] = millis();
    }
    if (char(serin) == 'A'){
      digitalWrite(rgbypin[1], HIGH);
      rgbyrefr[1] = millis();
    } 
    if (char(serin) == 'X'){
      digitalWrite(rgbypin[2], HIGH);
      rgbyrefr[2] = millis();
    } 
    if (char(serin) == 'Y'){
      digitalWrite(rgbypin[3], HIGH);
      rgbyrefr[3] = millis();
    }
  } 
  //led resets
  led_resets(rgbypin, rgbyrefr);
  lcd.setCursor(0,1);
}

void led_resets(int pins[], unsigned long refr[]){
  for(int i = 0; i < 4; i++){
    if(millis() - refr[i] > 100){
      digitalWrite(pins[i], LOW);
    }
  }
}
  
