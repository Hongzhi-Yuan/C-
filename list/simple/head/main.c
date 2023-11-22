#include "stdio.h"
#include "stdlib.h"
#include "list.h"

int main(){

    node_st *head = list_create();


    for (int i = 0; i < 10; i ++) {
        list_insert_at(head, i, i*22);
    }

    list_display(head);

    list_insert_at(head,3, 2023);
    list_display(head);


    exit(0);
}