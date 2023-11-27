#ifndef  LIST_H__
#define  LIST_H__


#define  FARWARD 1
#define  BACKWARD 2

typedef struct node_st{
    int  data;
    struct node_st *next;
    struct node_st *prev;
}node_st;

node_st *llist_create();
int llist_insert(node_st *, int , int );
void llist_show(node_st *);
int llist_delete(node_st *, int );
int llist_find(node_st *, int);

void llist_destroy(node_st *);






#endif 