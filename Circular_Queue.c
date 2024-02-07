#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};
void push(struct queue *q,int value);
int main(){
    struct queue *q=NULL;
    q=(struct queue *)malloc(sizeof(struct queue));
    q->size=5;
    q->front=q->rear=-1;
    q->arr=(int *)malloc(q->size*(sizeof(int)));

    push(q,15);
    push(q,22);
    push(q,23);
    push(q,29);
    push(q,69);
    push(q,11);

    printf("%d ",delete(q));
    printf("%d ",delete(q));
    printf("%d ",delete(q));
    printf("%d ",delete(q));
    printf("%d ",delete(q));
    printf("%d ",delete(q));
    
    
}
void push(struct queue *q,int value){
    if(q->front==-1 && q->rear==-1){
        q->front=q->front+1;
        q->rear=q->rear+1;
        q->arr[q->rear]=value;
        printf("%d ",q->arr[q->rear]);
    }
    else{
        if((q->rear+1)%q->size==q->front){
            printf("Overflow\n");
        }
        else{
            q->arr[(q->rear+1)%q->size]=value;
            q->rear=(q->rear+1)%q->size;
            printf("%d ",q->arr[q->rear]);
        }
    }
    

}
int delete(struct queue *q){
    int a=-1;
    if(q->front==q->rear){
        if(q->front==-1 && q->rear==-1){
            printf("Underflow\n");
        }
        else{
            a=q->arr[(q->front)%q->size];
            q->front=q->rear=-1;
        }
    }
    else{
        a=q->arr[(q->front)%q->size];
        q->front=(q->front+1)%q->size;

    }
    return a;
}
