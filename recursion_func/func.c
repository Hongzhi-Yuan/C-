#include "stdlib.h"
#include "func.h"
#include <stdio.h>


void func1(int i){
    if (i < 10) {
        printf("call func1 %d times\n", i);
        func1(i+1);
    }
}

int factorial_fun(int n){
    if (n < 0)
        return -1;
    else if (n == 0 || n== 1)
        return 1;
    else     
        return n * factorial_fun(n - 1); 
}










