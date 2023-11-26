#include "stdio.h"
#include "stdlib.h"
#include "list.h"





int main(){


    node_st *list = NULL;
    score_st tmp;

    for (int i = 0; i  < 7; i++) {
       tmp.id = i;
       snprintf(tmp.name, NAMESIZE, "stu%d", i);
       tmp.math = rand() %100;
       tmp.chinese = rand()%100;
       int ret =  list_insert(&list, &tmp);
       if (ret != 0)
        exit(1);
    }
    
    list_travel(list);

    list_delete(&list);
    list_travel(list);

    int id = 3;
    score_st *ptr;

    ptr = list_find(list, id);

    printf("%d %s %d %d\n",ptr->id, ptr->name, ptr->math, ptr->chinese);


    list_destroy(list);
    list = NULL;

    exit(0);
}