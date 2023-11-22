#ifndef LINER_H__
#define LINER_H__

#define DATASIZE 1024

typedef int type;

typedef struct {
    type elem[DATASIZE];
    int last;
}liner;

liner* liner_create();
int  liner_insert(liner *, int pos, type data);
int  liner_delete(liner*, int pos);
int  liner_find(liner *, int pos);
int  liner_isempty(liner *);
int  liner_isfull(liner *);
int  liner_setempty(liner *);
int  liner_getnum(liner *);
void liner_travel(liner*);
void liner_union(liner *, liner *);
void liner_destroy(liner *);

#endif