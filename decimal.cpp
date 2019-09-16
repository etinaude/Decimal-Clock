#include <iostream>
//#include <unistd.h>
#include <ctime>
int main() {
    std::cout<<"| \tDecimal \t"<<"| \tStandard\t"<<"| \tClock \t\t|\n";
    std::cout<<"|======================="<<"|======================="<<"|=======================|\n";
    //declare counters
    long duration,std_sec,dec_sec,std_min,std_hr,dec_min,dec_hr;
    std_sec=0,dec_sec=0;std_min=0;dec_min=0;std_hr=0;dec_hr=0;duration=0;
    //declare timers
    std::clock_t start,std_start,dec_start,current;
    start,std_start= std::clock();
    dec_start= std::clock();
    //while loop for given clock cycles
    while (true){
        //set current time and elapsed time
        current = std::clock();
        duration =(current-start);
        //increment standard time
        if(current-std_start >=CLOCKS_PER_SEC){
            std_start = std::clock()-(CLOCKS_PER_SEC-(current-std_start));
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
        if(current-dec_start >=864000){
            dec_start = std::clock()-(864000-(current-dec_start));
            if(dec_sec==100){
                dec_sec=0;
                if(dec_min==100){
                    dec_min=0;
                    if(dec_hr==10){
                        dec_hr=0;
                        std::cout<<"NEW DAY\n";
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
            std::cout<<"| Decimal: "<<dec_hr<<":"<<dec_min<<":"<<dec_sec<<"\t|";
            std::cout<<" Standard: "<<std_hr<<":"<<std_min<<":"<<std_sec<<"\t| Clock: "<<duration<<"  \t|\n";
        }
        //sleep(20);
    }
    //std::cout<<"|======================="<<"|======================="<<"|=======================|\n";
    //std::cout<<"| \tDecimal \t"<<"| \tStandard\t"<<"| \tclock \t\t|\n";
    return 0;
}