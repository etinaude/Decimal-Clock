/*=====================================================*
* please read the README.md file                       *
*                                                      *
* this file is for the decimal time arduino clock     *
* loops for a 10hr day                                 *
*                                                      *
*======================================================*/
//imports libraries--------------------------------
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16

//reset defaults---------------------------------------
const int hr=0;
const int mins=0;
const int sec=0;

//set up buttons---------------------------------------
const int mode_button=3;
int mode_buttonState = 0;
const int up_button=2;
int up_buttonState = 0;
const int down_button=1;
int down_buttonState = 0;

//declare counters-------------------------------------
int dec_sec=sec;int dec_min=mins;int dec_hr=hr;
int start= millis();int dec_start= millis();int current= millis();
String dec_str ="";

//initalization----------------------------------------
void setup() {
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextColor(WHITE);
    
    //set buttons---------------------------------------
    pinMode(mode_button,INPUT);
    pinMode(up_button,INPUT);
    pinMode(down_button,INPUT);

    //displays starter text------------------------------
    display.setTextSize(1);
    display.println();
    display.setTextSize(2);
    display.println("  DECIMAL");
    display.display();
    delay(1000);
    start= millis();dec_start= millis();current= millis();
}

//resets time-------------------------------------------
void reset(){
    mode_buttonState = digitalRead(mode_button);
    dec_hr=hr;
    dec_min =mins;
    dec_sec=sec;
    dec_start = millis();
}
//------------------------------------------------------

//handle buttons----------------------------------------
void change_sec(){
  while(mode_buttonState == LOW){
      up_buttonState = digitalRead(up_button);
      down_buttonState = digitalRead(down_button);
      mode_buttonState = digitalRead(mode_button);
    if(up_buttonState ==HIGH || down_buttonState ==HIGH){
      dec_sec =0;
    }
    up_buttonState = digitalRead(up_button);
    down_buttonState = digitalRead(down_button);
    mode_buttonState = digitalRead(mode_button);
  }
}

void change_min(){
      up_buttonState = digitalRead(up_button);
      down_buttonState = digitalRead(down_button);
      mode_buttonState = digitalRead(mode_button);
  while(mode_buttonState == LOW){
    if(up_buttonState ==HIGH){
      dec_min++;
    }
    if(down_buttonState == HIGH){
      dec_min--;
    }
    up_buttonState = digitalRead(up_button);
    down_buttonState = digitalRead(down_button);
    mode_buttonState = digitalRead(mode_button);
  }
}

void change_hr(){
  up_buttonState = digitalRead(up_button);
  down_buttonState = digitalRead(down_button);
  mode_buttonState = digitalRead(mode_button);
  while(mode_buttonState == LOW){
    if(up_buttonState ==HIGH){
      dec_hr++;
    }
    if(down_buttonState == HIGH){
      dec_hr--;
    }
      up_buttonState = digitalRead(up_button);
      down_buttonState = digitalRead(down_button);
      mode_buttonState = digitalRead(mode_button);
  }
}

void but(){
  mode_buttonState = digitalRead(mode_button);
  if(mode_buttonState == HIGH){
    change_sec();
    change_min();
    change_hr();
  }
}
//-----------------------------------------------------

//handle display---------------------------------------
void disp(){
    //formats output text------------------------------
    if(dec_min<10){dec_str = String(dec_hr)+":0"+String(dec_min);
    }else{dec_str = String(dec_hr)+":"+String(dec_min);}
    if(dec_sec<10){dec_str = dec_str+":0"+String(dec_sec);
    }else{dec_str = dec_str = dec_str+":"+String(dec_sec);}
    //displays text------------------------------------
    display.setTextSize(1);
    display.setCursor(10,0);
    display.clearDisplay();
    display.println("      Decimal\n");
    display.setTextSize(2);
    display.println("  "+dec_str);
    display.display();
}
//------------------------------------------------------

//increments time---------------------------------------
void incr(){
    if(current-dec_start >=863){
        dec_start = millis();
        if(dec_sec==99){dec_sec=0;
            if(dec_min==99){dec_min=0;
                if(dec_hr==9){dec_hr=0;
                }else{dec_hr++;}
            }else{dec_min++;}
          }else{dec_sec++;}
    }
}
//-----------------------------------------------------

//loops forever----------------------------------------
void loop() {
    //set current time---------------------------------
    current = millis();
    //increment decimal time---------------------------
    incr();
    //displays standard time---------------------------
    disp();
    //test to see if the button is pressed-------------
    but();
}
//-----------------------------------------------------
