#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include "mylib/mylib.h"
volatile sig_atomic_t flag;
volatile sig_atomic_t flag2;


void my_function(int sig){ // can be called asynchronously
  //flag = 1; // set flag
    if (flag==0){
        flag = 1;
    }
    else{
        flag = 0;
    }
}
void my_function2(int sig){ // can be called asynchronously
  //flag = 1; // set flag
    if (flag2==0){
        flag2 = 1;
    }
    else{
        flag2 = 0;
    }
}


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
    printf("(press CTRL + C to pause when the timer start) \n");

    


    
}

void StopWatch(int hour, int minute, int second, bool start, int input, int S0, int S1){
    signal(SIGINT, my_function); 
    signal(SIGQUIT, my_function2);
    int printed;
    while(start == true){
        if(flag == 0){
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

            // second++;
            // system("clear");
            // printf("second: %d\n",second);
            printed = 0;

        } 
        else{
            if(flag2 == 0){
                if(printed == 0){
                    printf("\n");
                    printf("timer is paused, press CTRL+C to resume the timer or CTRL+\\ to exit\n");
                    printed=1;
                    

                }

            }
            else{
                printf("\n");
                break;
            }
            // printf("timer is paused, press CTRL+C to start the timer\n");
        }


        sleep(1);

        

        
  
    }


}


int main(void){
    int s0 = 0, s1 = 0, S0 = 0, S1 = 0, b1 = 0, b2 = 0, O0 = 0, O1 = 0;
    int hour = 0, minute = 0, second = 0;
    int input;
    bool start = true;
    signal(SIGINT, my_function);
    signal(SIGQUIT, my_function2);
    while(1){
        system("clear");
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
                flag = 0;
                flag2 = 0;
                system("clear");
                StopWatch(hour, minute, second, start, input, S0, S1);
            }
            else if(b1 == 0 && b2 == 1){
                start = false;
                system("clear");
                PrintData(hour, minute, second);
            }
            else if(b1 == 1 && b2 == 1){
                start = true;
                flag = 0;
                flag2 = 0;
                system("clear");
                StopWatch(hour, minute, second, start, input, S0, S1);

            }
            else if(b1 == 0 && b2 == 0){
                start = true;
            }
            printf("Current state %d %d\n", S0, S1);
        }
        b1 = 0;
        b2 = 0;
        printf("Insert input(0/1/2/3(both) (press CTRL + C to pause when the timer start) \n");
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
