#include "stdio.h"
#include "stdlib.h"
#include "josephu.h"


node_st * jose_create(int n){
    node_st *p = malloc(sizeof(*p));
    if (p == NULL) return  NULL;

    int j = 1;
    p->elem = j;
    p->next = p;
    j++;

    node_st *cur = p;

    //上一个节点指向每次创建出来的节点，
    //创建出来新节点的next都指向头节点
    for (; j <= n; j++) {
        node_st *new = malloc(sizeof(*new));
        if (new == NULL) return NULL;

        new->elem = j; 
        new->next = p;
        cur->next = new;
        cur = new; 
    }

    return p;
}


void jose_show(node_st *p){
    if (p == NULL)  return;
    node_st *cur = p;

    do {
        printf("%6d", cur->elem);
        cur = cur->next;
    }while (cur!=p);
    printf("\n");
}

void jose_kill(node_st *p, int n){
    if (p == NULL)  return;

    node_st *cur = p, *node;

    int i = 1;
    while (i < n) {
        node = cur;
        cur = cur->next;
        
    }

}








