#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "list.h"
#include <stdio.h>



int main(){

    node_st *user_list =  llist_create();
    if (user_list == NULL) exit(1); 


    int ret;
    for (int i = 0; i < 10; i++) {
        ret = llist_insert(user_list, i ,BACKWARD);
        if (ret) {printf("insert error!\n"); break;}
    }

    llist_show(user_list);


    ret = llist_delete(user_list, 3);
    if (!ret) llist_show(user_list); 

    llist_destroy(user_list);

    user_list = NULL;

    exit(0);
}