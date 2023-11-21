#include "stdio.h"
#include  "stdlib.h"
#include "call_back.h"


int main(){

    int a = 10, b = 20, ret = 0;

    ret = call(a, b, func);

    printf("ret = %d\n", ret);

    exit(0);
}