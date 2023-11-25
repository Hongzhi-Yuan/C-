#include "stdio.h"
#include "stdlib.h"
#include "list.h"

int main(){

    node_st *head = list_create();

    int test_arr1[] = {22,55,11,78,23,44,1010,62626};
    


    for (int i = 0; i < sizeof(test_arr1) / sizeof(test_arr1[0]); i++) {
        list_order_insert(head, test_arr1[i]);
    }

    list_display(head);

    type deleted_elem;

    list_delete_at(head, 3,& deleted_elem);

    printf("deleted_elem is %d\n", deleted_elem);
    
    list_display(head);
   
    list_destroy(head);
    head = NULL;

    exit(0);
}