#include "stdlib.h"
#include "stdio.h"
#include "list.h"


#define NAMESIZE 32

typedef struct{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
}score_st;
 
static void print_s(const void *ptr){
   const score_st *cur = ptr;
   printf("%d %s %d %d\n", cur->id, cur->name, cur->math, cur->chinese);
}

static int  id_cmp(const void *key, const void *record){
    const int *k = key;
    const score_st *r = record;
    return ( *k - r->id );
}





int main(){

    llist_st *user_list = llist_create(sizeof(score_st));        


    for (int j = 0; j < 8; j++){
        score_st tmp;
        tmp.id = j;
        snprintf(tmp.name, NAMESIZE, "stu%d", j);
        tmp.math = rand() % 100;
        tmp.chinese =rand() % 100;
        int ret = user_list->insert(user_list, &tmp, BACKWARD);
        if (ret) printf("error\n");
    }


    user_list->show(user_list, print_s);

    printf("\n\n\n");


    int id  = 3;
    
    score_st *score_st_ret = NULL ;
    #if 0
    score_st_ret = llist_find(user_list, &id, id_cmp);
    if (score_st_ret == NULL) printf("Can not find!!!\n");
    else print_s(score_st_ret);


    #else 
    printf("\n\n\n");
    score_st ret_data; score_st_ret = &ret_data;
    llist_fetch(user_list, &id, id_cmp, score_st_ret);
    print_s(score_st_ret);
    #endif




    // llist_delete(user_list, &id, id_cmp);

    // llist_show(user_list, print_s);



    printf("\n\n\n");
  


    llist_destroy(user_list);

    user_list = NULL;

    exit(0);
}