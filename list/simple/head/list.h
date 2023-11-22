#ifndef LIST_H__
#define LIST_H__


typedef int type;

typedef struct node_st{
    type data;
    struct node_st *next;
}node_st;

node_st * list_create();
int list_insert_at(node_st *, int , type);
int list_order_insert(node_st *, type);
int list_delete_at( node_st *, int, type *);
int list_delet(node_st *, type);
int list_isempty(node_st *);
void list_display(node_st *);
void list_destroy(node_st *);


#endif