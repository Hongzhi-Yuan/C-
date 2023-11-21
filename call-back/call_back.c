#include "stdio.h"
#include "call_back.h"


int func(int i, int j){
    return  i + j;
}

int  call(int i, int j, p func){
    return func(i, j);
}



