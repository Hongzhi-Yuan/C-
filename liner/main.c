#include "stdio.h"
#include "stdlib.h"
#include "liner.h"

int main(){
    liner *user_list = liner_create();
    if (user_list == NULL){
        fprintf(stderr, "liner_create() failed!\n");
        exit(1);
    }
    
    for (int i = 0;  i < 10; i++) {
        liner_insert(user_list, i, i*10);
    }

    liner_travel(user_list);

    liner_insert(user_list, 2, 2023);
    liner_travel(user_list);

    liner_delete(user_list, 2);
    liner_travel(user_list);

    liner_destroy(user_list);
    user_list = NULL;

    exit(0);
}