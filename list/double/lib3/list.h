#ifndef LIST_H__
#define LIST_H__



#define FORWARD 1
#define BACKWARD 2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *, const void *);


typedef struct  node_st{
    struct node_st *prev;
    struct node_st *next;
    char data[0];                       //占位符，结构体可大可小
}node_st;

typedef struct llist_st{
    int size;
    node_st head;

    int  (*insert)(struct llist_st *, const void *, int );
    void (*show)(struct llist_st *, llist_op);

}llist_st;



llist_st * llist_create(int initsize);




void * llist_find(llist_st *p, const void *key, llist_cmp *cmp);

int llist_delete(llist_st *p, const void *key, llist_cmp *cmp);

int  llist_fetch(llist_st *p, const void *key, llist_cmp *cmp, void *back);




void  llist_destroy(llist_st *);












#endif 