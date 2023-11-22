#include "stdio.h"
#include "stdlib.h"
#include "liner.h"


liner * liner_create(){
    liner *p = malloc(sizeof(*p));
    if (p == NULL) 
        return NULL;
    p->last = 0;
    return p;
}

int  liner_insert(liner *p, int pos, type data){
    if(p->last == DATASIZE) 
        return  -1;

    if (pos < 0  || pos >= DATASIZE)
        return  -2;

    if (pos >= p->last) {
       p->elem[p->last] = data;
       p->last++;
    } else {
        for (int i = p->last; i >= pos ; i--) {
            p->elem[i] = p->elem[i-1];
        }
        p->elem[pos] = data;
        p->last ++;
    }
    return 0;
}

int liner_delete(liner *p, int pos){
    if (p == NULL)
        return -1;
    if (pos < 0 || pos > DATASIZE)
        return -2; 

    if (pos >= p->last) {
        p->elem[p->last --] = 0;
        return 0;
    } else {
        for (int i = pos; i < p->last; i++) {
            p->elem[i] = p->elem[i+1];
        }
        p->last --;
        return 0;
    }
}

void liner_travel(liner *p){
    if (p == NULL)  
        return;
    for (int i = 0; i < p->last; i++) {
        printf("%6d", p->elem[i]);
    }
    printf("\n");
}

int liner_getnum(liner *p){
    if (p == NULL)
        return -1;
    return p->last;
}

int liner_find(liner *p, int inedex){
    if (p == NULL) 
        return  -1;
    return p->elem[inedex];
}

int liner_isempty(liner *p){
    if (p == NULL)
        return -1;
    if (p->last == 0)
        return 0;
    else 
        return 1;
}

int liner_isfull(liner *p){
    if (p == NULL)
        return -1;
    if (p->last == DATASIZE)
        return 0;
    else 
        return 1; 
}

int liner_setempty(liner *p){
    if (p == NULL)
        return -1;

    p->last = 0;
    return 0;
}

void liner_destroy(liner *p){
    if (p == NULL)
        return;
    
    free(p);
}
