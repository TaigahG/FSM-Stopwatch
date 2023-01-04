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
    printf("     _____________________________________________________ \n");
    printf("   /                                                      \\ \n");
    printf("  /                                                        \\ \n");
    printf(" /                                                          \\ \n");
    printf(" |                                                          | \n");
    printf(" |                          %d:%d:%d                           | \n", hour, minute, second);
    printf(" |                                                          | \n");
    printf(" |                                                          | \n");
    printf(" \\                                                          / \n");
    printf("  \\                         Ready                          / \n");
    printf("   \\______________________________________________________/ \n");

    
}
void PrintDataStpWatch(int hour, int minute,  int second, int input, int S0, int S1){

    bool start = true;
    printf("     _____________________________________________________ \n");
    printf("   /                                                      \\ \n");
    printf("  /                                                        \\ \n");
    printf(" /                                                          \\ \n");
    printf(" |                                                          | \n");
    printf(" |                          %d:%d:%d                           | \n", hour, minute, second);
    printf(" |                                                          | \n");
    printf(" |                                                          | \n");
    printf(" \\                                                          / \n");
    printf("  \\                         Start                          / \n");
    printf("   \\______________________________________________________/ \n");
    printf("Current state %d %d\n", S0, S1);
    printf("Insert input(0/1/2/3(both) \n");




    
}

void StopWatch(int hour, int minute, int second, bool start, int input, int S0, int S1){
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
        PrintDataStpWatch(hour, minute, second, input, S0, S1);
        Delay(1000000);
        second++;
 

        

        
  
    }


}

int main(void){
    int s0 = 0, s1 = 0, S0 = 0, S1 = 0, b1 = 0, b2 = 0, O0 = 0, O1 = 0;
    int hour = 0, minute = 0, second = 0;
    int input;
    bool start = false;
    while(1){
        if ((S0 == 0 && S1 == 0)){
            system("clear");
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
                StopWatch(hour, minute, second, start, input, S0, S1);
            }
            else if(b1 == 0 && b2 == 1){
                start = false;
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
        printf("Insert input(0/1/2/3(both) \n");
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
