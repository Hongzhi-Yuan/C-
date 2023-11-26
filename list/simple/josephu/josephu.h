#ifndef  JOSEPHU_H__
#define  JOSEPHU_H__

typedef struct node_st{
    int elem;
    struct  node_st *next;
}node_st;

node_st * jose_create(int );
void jose_show(node_st *);
void jose_kill(node_st *, int );







#endif