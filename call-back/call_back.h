#ifndef    CALL_BACK_H__
#define    CALL_BACK_H__

typedef int (*p)(int , int);

int func(int , int );

int call(int, int, p);

#endif 
