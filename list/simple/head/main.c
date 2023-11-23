#include "stdio.h"
#include "stdlib.h"
#include "list.h"

int main(){

    node_st *head = list_create();

    int test_arr1[] = {22,33,55,11,78,23,44,1010,62626};
    int test_arr2[] = {11,22,33,44,55,66,77,88,99};



    for (int i = 0; i < sizeof(test_arr1) / sizeof(test_arr1[0]); i++) {
        list_insert_at(head, i, test_arr1[i]);
    }

    list_display(head);

  
    exit(0);
}