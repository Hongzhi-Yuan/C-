#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "list.h"

node_st *llist_create(){
    node_st *cur = malloc(sizeof(*cur));
    if (cur == NULL) return NULL;

    cur->next = cur;
    cur->prev = cur;
    return  cur;
}

int llist_insert(node_st *ptr, int data, int mode ){
    if (ptr == NULL) return -1;

    node_st *cur = ptr;

    node_st *new = malloc(sizeof(*new));
    new->data = data;


    if (mode == FARWARD) {
        new->prev = cur;            //先对先创建的节点操作，然后前后节点指向新的节点
        new->next = cur->next;

        new->prev->next = new;
        new->next->prev = new;

        printf("prev = %p    curr = %p    next = %p\n", new->prev, new, new->next);

    } else if (mode == BACKWARD) {
        new->next = cur;
        new->prev = cur->prev;

        new->prev->next = new;
        new->next->prev = new;    

    }  else {
        return -2;
    }  

    return  0;
}


void llist_show(node_st *ptr){
    if (ptr == NULL) return;

    node_st *cur = ptr;

    do {
        cur = cur->next;
        printf("%6d", cur->data);
    }while (cur->next!=ptr); 
    printf("\n");
}

int llist_delete(node_st *ptr, int data){
    if (ptr == NULL) return -1;

    node_st *cur = ptr;

    do {
        cur = cur->next;
        if (cur->data == data) break;
    }while (cur->next != ptr);

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    
    return 0;
}

void llist_destroy(node_st *ptr){
    if (ptr == NULL) exit(1);

    node_st *cur = ptr;

    do {
        cur->next = cur->next->next;
        cur->next->prev = cur;
        free(cur->next);
    }while (cur!=ptr);

    free(cur);
}
