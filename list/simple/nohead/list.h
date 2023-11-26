#ifndef LIST_H__
#define LIST_H__

#define NAMESIZE 1024

typedef struct{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}score_st;

typedef struct node_st{
    score_st data;
    struct node_st *next;
}node_st;



int list_insert(node_st **, score_st *);
void list_travel(node_st *);
int list_delete(node_st **);
score_st * list_find(node_st *, int );
void list_destroy(node_st *);





#endif 