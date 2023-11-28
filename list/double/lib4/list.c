#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "list.h"


typedef struct  node_st{
    struct node_st *prev;
    struct node_st *next;
    char data[0];                       //占位符，结构体可大可小
}node_st;

struct llist_st{
    int size;
    node_st head;
};


llist_st * llist_create(int initsize){
    struct llist_st *ptr = malloc(sizeof(*ptr));
    if (ptr == NULL) return  NULL;

    ptr->size = initsize;
    
    ptr->head.next = &ptr->head;
    ptr->head.prev = &ptr->head;

    return ptr;
}

int  llist_insert(llist_st *ptr, const void *data, int mode){
    struct llist_st *p = ptr;
    if (p == NULL) return -1;
    if (data == NULL) return -2;

    struct llist_st *cur = p;
    
    node_st *new_node = malloc(sizeof(*new_node) + p->size);
    if (new_node == NULL) return -3; 

    
    memcpy(new_node->data, data, cur->size);

    if (mode == FORWARD) {
        new_node->next = cur->head.next;
        new_node->prev = &cur->head;
    } else if (mode == BACKWARD){
        new_node->next = &cur->head;
        new_node->prev = cur->head.prev;
    } else {
        return -5;
    }

    new_node->prev->next = new_node;
    new_node->next->prev = new_node;
    

    return 0;
}

static node_st *find_(llist_st *ptr, const void *key, llist_cmp *cmp){
    struct llist_st *p = ptr;

    node_st *cur = p->head.next;

    do {
        if (cmp(key, cur->data) == 0) 
            break;
        cur = cur->next;
    }while (cur!=&p->head);

    return cur;
}

void * llist_find(llist_st *ptr, const void *key, llist_cmp *cmp){

    struct llist_st *p = ptr;

    node_st * node =  find_(p, key, cmp);

    if (node == &p->head) return  NULL;

    return node->data;
}

void llist_show(llist_st *ptr, llist_op *op){

    struct llist_st * p = ptr;
    if (p == NULL) return;

    node_st  *cur = p->head.next;

    do {
        op(cur->data);
        cur = cur->next;
    }while (cur!= &p->head);

}


int llist_delete(llist_st *ptr, const void *key, llist_cmp *cmp){
    struct llist_st *p = ptr;

    node_st *node;
    node = find_(p,  key, cmp);
    if (node == &p->head) return  -1;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);

    return 0;
}

int  llist_fetch(llist_st *ptr, const void *key, llist_cmp *cmp, void *back){
    struct llist_st *p = ptr;

    node_st *node;
    node = find_(p, key, cmp);
    if (node == &p->head) return -1;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    memcpy(back, node->data, p->size);

    free(node);
    return 0;
}

void  llist_destroy(llist_st *p){

    struct llist_st *ptr = p;

    if (ptr == NULL) return;

    struct llist_st *cur = ptr;

    do {
       cur->head.next = cur->head.next->next;
       cur->head.next->prev = &cur->head;
       free(cur->head.next); 
    }while (cur!=ptr); 

    free(ptr);
}








