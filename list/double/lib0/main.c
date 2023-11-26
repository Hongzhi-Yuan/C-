#include "stdlib.h"
#include "stdio.h"
#include "list.h"


#define NAMESIZE 1024

typedef struct{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}score_st;
 
void print_s(const void *rv){
    const score_st *r = rv;
    printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}



int main(){
    

    llist_st *handler = llist_create(FORWARD);
    if (handler == NULL) exit(1); 


    score_st tmp;

    int ret ;

    for (int i = 0; i < 8; i++) {
        tmp.id = i;
        snprintf(tmp.name, handler->size, "stu%d", i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;
        ret = llist_insert(handler, &tmp, FORWARD);
        if (ret) exit(1);
    }

    
    llist_show(handler, print_s);

    llist_destroy(handler);



    exit(0);
}