#include "stdio.h"
#include "stdlib.h"
#include "list.h"

node_st * list_create(){
    node_st *p = malloc(sizeof(*p));
    if (p == NULL)
        return  NULL;
    p->next = NULL;
    return p;
}
int list_insert_at(node_st *p, int pos, type data){
    if (p == NULL)
        return -1;
    
    if (pos < 0)
        return -2;     

    node_st *curr = p;    
    int j = 0;

    while (curr->next != NULL) {
        if (j < pos) {
            j ++;
            curr = curr->next;
        }else {
            break;
        }
    }

    node_st *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL)
        return -3;
    else {
        new_node->data = data;
        new_node->next = curr->next;
        curr->next = new_node;
        return 0;
    } 

}
int list_order_insert(node_st *p, type data){
    if (p == NULL)
        return  -1;
        

    return 0; 
}
// int list_delete_at(node_st *p, int pos, type *data){}
// int list_delet(node_st *p, type data){}
// int list_isempty(node_st *p){}
void list_display(node_st *p){
    if (p == NULL)
        return;

    node_st *curr = p;

    while (curr->next != NULL) {
        curr = curr->next;
        printf("%6d", curr->data);
    }
    printf("\n");

}
// void list_destroy(node_st *p){}

