#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_SPITFT.h>

#include <Stepper.h>
#include <Adafruit_SSD1306.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 



/*==============================================================================*
* please read the README.md file                                                *
*                                                                               *
* to compile and run use:                                                       *
* clear;g++ decimal.cpp -o decimal; "/home/test/Downloads/clock/"decimal        *
* 
* reference-
* https://create.arduino.cc/projecthub/goveil1/westminster-chiming-clock-with-weather-and-date-8c9b80?ref=platform&ref_id=424_trending___&offset=22
*===============================================================================    */
  //declare counters
    int std_sec=0;int dec_sec=0;int std_min=0;int dec_min=0;int std_hr=0;int dec_hr=0;int duration=0;
    //declare timers
    int start= millis();int std_start= millis();int dec_start= millis();int current= millis();
    String dec_str =String(dec_hr+":"+dec_min);
    String std_str =String(std_hr+":"+std_min);
void setup() {
    
    dec_str = dec_hr+":"+dec_min;
    dec_str=dec_str+":"+dec_sec;
    std_str=std_hr+":"+std_min;
    std_str = std_str+":"+std_sec;
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   // display.display();
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10,10);
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    display.println(3.141592);
    display.println("| \tDecimal \t\t| \tStandard\t\t| \tClock \t\t|\n");
    //Serial.print("|=======================|=======================|=======================|\n");   
    //loop();
}

void loop() {
  //set current time and elapsed time
        current = millis();
        duration =(current-start);
        //increment standard time
        if(current-std_start >=1000){
            std_start = millis()-(1000-(current-std_start));
              if(std_sec==60){
                std_sec=0;
                if(std_min==60){
                    std_min=0;
                    if(std_hr==24){
                        std_hr=0;
                    }else{
                        std_hr++;
                    }
                }else{
                    std_min++;
                }
            }else{
                std_sec++;
            }
        }
        //increment decimal time
        if(current-dec_start >=864){
            dec_start = millis()-(864-(current-dec_start));
            if(dec_sec==100){
                dec_sec=0;
                if(dec_min==100){
                    dec_min=0;
                    if(dec_hr==10){
                        dec_hr=0;
                    }else{
                        dec_hr++;
                    }
                }else{
                    dec_min++;
                }
            }else{
                dec_sec++;
            }
            dec_str = String(dec_hr)+":"+String(dec_min)+":"+String(dec_sec);
            std_str = String(std_hr)+":"+String(std_min)+":"+String(std_sec);
            //print time in columns
            Serial.print("| Decimal= ");
            Serial.print(dec_str);
            Serial.print("\t\t| Standard= ");
            Serial.print(std_str);
            Serial.print("\t\t| Clock= ");
            Serial.print(duration);
            Serial.print("  \t\t|\n");
            display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println(dec_str);
  display.display();
            //display.drawPixel(10, 10, WHITE);
            display.display();
        }
}
