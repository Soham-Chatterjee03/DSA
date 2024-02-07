#include<stdio.h>
#define MAX 10
int arr[MAX],top=-1;
void push(int arr[],int val);
int pop(int arr[]);
int peek(int arr[]);
void display(int arr[]);


int main(){
    int val, option;
    do
    {
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.PEEK");
        printf("\n 4.DISPLAY");
        printf("\n 5.EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            push(arr, val);
            break;
        case 2:
            val = pop(arr);
            printf("\n The value deleted from stack is: %d", val);
            break;
        case 3:
            val = peek(arr);
            printf("\n The value stored at top of stack is: %d", val);
            break;
        case 4:
            display(arr);
        break;
        }
    }
        while(option != 5);
}
void push(int arr[],int val){
    if(top==(MAX-1)){
        printf("OVERFLOW");
    }
    else{
        top++;
        arr[top]=val;
    }

}
int pop(int arr[]){
    int val;
    if(top==-1){
        printf("UNDERFLOW");
        return -1;
    }
    else{
        val=arr[top];
        top--;
        return val;
    }
}
void display(int arr[]){
    int i;
    if(top==-1){
        printf("No elements in stack");
    }
    else{
        for(i=top;i>=0;i--){
            printf("\n %d",arr[i]);

        }
    }
}
int peek(int arr[]){
    if(top == -1){
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else{}
        return (arr[top]);
}
    




