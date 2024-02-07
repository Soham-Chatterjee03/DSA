// Implementation deletion and insertion of the double ended queue 
#include<stdio.h>
#include<stdlib.h>

struct DEQueue  //(DEQueue means Double ended Queue, In this type of Queue is insertion and deleition operation perform at the both end ie. front and rear)
{
    int size;
    int front;
    int rear;
    int *arr;

};

