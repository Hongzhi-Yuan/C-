#include "stdio.h"
#include "stdlib.h"
#include "josephu.h"


#define JOSE_NR 8



int main(){

    node_st *list =  NULL;
    list = jose_create(JOSE_NR);    
    if (list == NULL)
        exit(1);


    jose_show(list);    


    exit(0);
}

