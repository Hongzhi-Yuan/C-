#include "stdio.h"
#include "stdlib.h"
#include "list.h"



// node_st * list_insert(node_st *p, score_st *data){
//     node_st *new = malloc(sizeof(*new));
//     if (new == NULL)    
//         return NULL;

//     new->data = *data;
//     new->next = p;
//     p = new ;

//     return p;
// }

int list_insert(node_st **p, score_st *data){
    node_st *new =  malloc(sizeof(*new));
    if (new == NULL)    
        return -1; 
    new->data = *data;
    new->next = *p;
    *p = new;
    
    return 0;
}


// int list_insert_order(node_st *, int ){

// }
void list_travel(node_st *p){
    if (p == NULL)
        return;

    node_st *cur;

    for (cur = p; cur!=NULL; cur = cur->next) {
        printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
    }    
    printf("\n");
}

int list_delete(node_st **p){
    if (*p == NULL)
        return -1;

    node_st *cur = *p;
    *p  = (*p)->next;
    free(cur);

    return 0;
}

score_st * list_find(node_st *p, int id){
    node_st *cur = NULL;

    for (cur = p; cur!=NULL ; cur = cur->next) {
        if (cur->data.id == id) {
            return &cur->data;
        }
    }
    return  NULL;
}

void list_destroy(node_st *p){
    if (p == NULL)
        return;
    
    
    for (node_st *cur = p; cur!=NULL ; cur = p) {
        p = p->next;      
        free(cur);
    }

}


 