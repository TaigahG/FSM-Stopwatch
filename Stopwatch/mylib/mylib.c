#include <stdio.h>
void states(int s0, int s1, int m, int b, int* S0, int *S1){
    int a = s0 & !s1;
    int h = s0 & !m & !b;
    int c = (!s0) & s1 & m & !b;
    *S0 = a | h | c;
    int d = s1 & !m & !b;
    int e = !s1 & !m & b;
    int f = !s0 & !s1 & m;
    int g = s0 & s1 & m & b;
    *S1 = d | e | f | g;

}