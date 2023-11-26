#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "string.h"


llist_st * llist_create(int init_size){
    llist_st * p = malloc(sizeof(*p));
    if (p == NULL) return NULL;
    
    p->size = init_size;
    p->head.data = NULL;
    p->head.prev = &p->head;
    p->head.next = &p->head;

    return p;
}

int  llist_insert(llist_st *p, const void *data, int mode){
    
    node_st *new = malloc(sizeof(*new));
    if (new == NULL)  return -1;

    new->data = malloc(sizeof(p->size));
    if (new->data == NULL) return -2;
    
    memcpy(new->data, data, p->size);

    if (mode == FORWARD){
        new->prev = &p->head;
        new->next = p->head.next;
        new->prev->next = new;
        new->next->prev = new;
        return 0;
    } else if (mode == BACKWARD) {
        new->prev = p->head.prev;
        new->next = &p->head;   
        new->prev->next = new;
        new->next->prev = new;     
    } else {
        return -3;
    }

    return 0;
}

void llist_show(llist_st *p, llist_op *op){
    node_st *cur  = NULL;
    for (cur = p->head.next; cur->next != &p->head; cur = cur->next) {
        op(cur->data);
    }
}

void  llist_destroy(llist_st *p){
    node_st *cur =  NULL, *next;

    for (cur = p->head.next; cur->next!=&p->head; cur = next) {
        next = cur->next;
        free(cur->data);
        free(cur);
    }

    free(p);
}
