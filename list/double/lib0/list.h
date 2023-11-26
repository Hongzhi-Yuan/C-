#ifndef LIST_H__
#define LIST_H__

#include <stdlib.h>

#define FORWARD 1
#define BACKWARD 2

typedef void llist_op(const void *);

typedef struct  node_st{
    void *data;
    struct node_st *prev;
    struct node_st *next;
}node_st;

typedef struct llist_st{
    int size;
    node_st head;
}llist_st;





llist_st * llist_create(int initsize);

int  llist_insert(llist_st *p, const void *data, int mode);


//llist_find();

//llist_delete();

//llist_fetch();

void llist_show(llist_st *p, llist_op);


void  llist_destroy(llist_st *);












#endif 