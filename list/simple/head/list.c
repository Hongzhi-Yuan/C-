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

    node_st *prev = p;
    node_st *curr = prev->next;

    if (curr == NULL) {
        node_st *new_node = malloc(sizeof(*new_node));
        new_node->data = data;
        new_node->next = curr;
        prev->next = new_node;
    } else {
        while (curr!=NULL) {
            if (curr->data > data) {
                break;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        node_st *new_node = malloc(sizeof(*new_node));
        new_node->data = data;
        new_node->next = curr;
        prev->next = new_node;
    }
    return 0;     
}
int list_delete_at(node_st *p, int pos, type *data){
    if (p == NULL)
        return -1;

    if (pos < 0)
        return -2; 

    int j = -1;
    node_st *curr = p;

    while (curr->next != NULL) {
        node_st *next = curr->next;
        j++;
        if (j == pos) {
            *data = next->data;
            curr->next = next->next;
            free(next);
            break;
        }
        curr = next;
    }
    return 0;

}
int list_setempty(node_st *p){

    return 0; 
}

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
void list_destroy(node_st *p){
    if (p == NULL)
        return;


    while (p->next!=NULL) {
        node_st *curr = p->next;
        p->next = curr->next;
        free(curr);
        curr = NULL;
    }

    free(p);
}

