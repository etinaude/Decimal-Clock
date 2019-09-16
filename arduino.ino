#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
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
    dec_str = dec_str+":"+dec_sec;
    std_str = std_str+":"+std_sec;
    Serial.begin(9600);
    Serial.print("| \tDecimal \t| \tStandard\t| \tClock \t\t|\n");
    Serial.print("|=======================|=======================|=======================|\n");   
    //set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("hello, world!");
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
            //print time in columns
            Serial.print("| Decimal: ");
            Serial.print(dec_str);
            Serial.print("\t| Standard: ");
            Serial.print(std_str);
            Serial.print("\t| Clock: ");
            Serial.print(duration);
            Serial.print("  \t|\n");
            lcd.setCursor(0, 1);
            // print the number of seconds since reset:
            lcd.print(millis() / 1000);
        }
}
