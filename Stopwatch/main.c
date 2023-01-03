#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <poll.h>
#include "mylib/mylib.h"

void Delay(ms){
    clock_t timeDelay = ms + clock();
    while(timeDelay > clock());
}
void PrintData(int hour, int minute,  int second){
    printf(" %d:%d:%d \n", hour, minute, second);

    
}

void StopWatch(int hour, int minute, int second, bool start, int input){
    while(start == true){

        if (minute > 59){
            minute = 0;
            hour++;
        }
        if(second > 59){
            second = 0;
            minute++;
        }
        system("clear");
        PrintData(hour, minute, second);
        Delay(1000000);
        second++;
        sleep(1);
        printf("Insert input 1/2/3(both) \n");
        scanf("%d",&input);
        if(input == 2){
            start = false;
            break;
        }
        else if(input == 1 || input == 3){
            continue;
        }
        

        
  
    }
    // while true{
    //     if(flag == 0){
    //         for(int i = 0; i<=hour; i++){
                
    //             for(minute = 0; minute<=60; minute++){
                    
    //                 for(second = 0;  second<=60; second++){
                        
    //                     system("clear");
    //                     PrintData(hour,minute,second);
    //                     scanf("%d",&input);
    //                     Delay(1000000);


    //                 }
    //             }
                
    //         }
    //     }

    // }

}
void choice(int hour, int minute, int second, bool start, int input){
        do
        {   

            printf("Insert input 1/2/3(both)\n");
            scanf("%d",&input);
            if(input == 2){
                start = false;
                break;
            }
            else{
            continue;
            }

        } while (sleep(1));
}
int main(void){
    int s0 = 0, s1 = 0, S0 = 0, S1 = 0, b1 = 0, b2 = 0, O0 = 0, O1 = 0;
    int hour = 0, minute = 0, second = 0;
    int input;
    bool start = false;
    while(1){
        if ((S0 == 0 && S1 == 0)){
            // system("clear");
            if((b1 == 1 && b2 == 0)){
                 
                system("clear");
            }
            else if((b1 == 0 && b2 == 1)){
                 
                system("clear");
            }
            else if((b1 == 1 && b2 == 1)){
                 
                system("clear");
            }
            printf("Current state %d %d\n", S0, S1);
        }
        else if((S0 == 0 && S1 == 1)){
            if(b1 == 1 && b2 == 0){
                 
                system("clear");
                PrintData(hour, minute, second);
            }
            else if(b1 == 0 && b2 == 1){
                 
                system("clear");
                PrintData(hour, minute, second);

            }
            else if(b1 == 1 && b2 == 1){
                 
                system("clear");
                PrintData(hour, minute, second);
            }
            else if(b1 == 0 && b2 == 0){
                system("clear");
                PrintData(hour, minute, second);
            }
            printf("Current state %d %d\n", S0, S1);
        }
        else if((S0 == 1 && S1 == 0)){
            if(b1 == 1 && b2 == 0){
                start = true;
                system("clear");
                choice(hour, minute,second,start, input);
            }
            else if(b1 == 0 && b2 == 1){
                start = false;
                break;
            }
            else if(b1 == 1 && b2 == 1){
                start = true;
            }
            else if(b1 == 0 && b2 == 0){
                PrintData(hour, minute, second);
            }
            printf("Current state %d %d\n", S0, S1);
        }
        b1 = 0;
        b2 = 0;
        printf("Insert input(1/2/3(both) \n");
        scanf("%d", &input);
        if(input == 1){
            b1 = 1;
            b2 = 0;
        }
        else if(input == 2){
            b1 = 0;
            b2 = 1;

        }
        else if(input == 3){
            b1 = 1;
            b2 = 1;
        }
        else if(input == 0){
            b1 = 0;
            b2 = 0;
        }
        else{
            input = 0;
        }
        



        states(s0, s1, b1, b2, &S0, &S1);
        s0 = S0;
        s1 = S1;









    }
    
  
    return 0;
    
}