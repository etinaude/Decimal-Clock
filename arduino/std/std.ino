/*==============================================================================*
* please read the README.md file                                                *
*                                                                               *
* this file is for the standard time arduino clock                              *
*                                                                               *
*===============================================================================*/
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
//reset defaults
const int hr=0;
const int mins=0;
const int sec=0;
const int button=3;
int buttonState = 0;
//declare counters
int std_sec=0;int std_min=0;int std_hr=0;int dec_hr=0;
int start= millis();int std_start= millis();int current= millis();
String std_str ="";
void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  pinMode(button,INPUT);
  display.setTextSize(1);
  display.println();
  display.setTextSize(2);
  display.println("  STANDARD");
  display.display();
  delay(1000);
  start= millis();std_start= millis();current= millis(); 
}
void but(){
  buttonState = digitalRead(button);
  if(buttonState == HIGH){
    std_hr=hr;
    std_min =mins;
    std_sec=sec;
    std_start = millis();
  }
}
void disp(){
  display.setTextSize(1);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println("     Standard\n");
  display.setTextSize(2);
  display.println("  "+std_str);
  display.display();
}
void incr(){
  if(current-std_start >=1000){
    std_start = millis();
    if(std_sec==59){std_sec=0;
      if(std_min==59){std_min=0;
          if(std_hr==24){std_hr=0;
          }else{std_hr++;}
        }else{std_min++;}
    }else{std_sec++;}
  }
}
void form(){
  if(std_min<10){std_str = String(std_hr)+":0"+String(std_min);
  }else{std_str = String(std_hr)+":"+String(std_min);}
  if(std_sec<10){std_str = std_str+":0"+String(std_sec);
  }else{std_str = std_str = std_str+":"+String(std_sec);}   
}
void loop() {
  //set current time
  current = millis();
  //increment standard time
  incr();
  //formats text
  form();
  //displays standard time
  disp();
  //test to see if the button is pressed
  but();
}
