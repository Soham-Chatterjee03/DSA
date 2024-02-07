#include<stdio.h>
#include<stdlib.h>
int arr[10];
int first=-1,last=-1;
void push(int arr[],int value);
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
void push(int arr[],int value){
    if(first==-1){
        arr[0]=value;
        first++;
        last++;
    }
    else{
        if(last==10-1){
            printf("Overflow");

        }
        else{
            arr[last+1]=value;
            last++;
        }
        
    }
}
int pop(int arr[]){
    int del;
    if(first==-1 || first==last){
        printf("Underflow");
    }
    else{
        del=arr[first];
        first++;
    }
    
    
    return del;
}
int peek(int arr[]){
    int peek;
    peek=arr[last];
    return peek;
}
void display(int arr[]){
    int i;
    for(i=first;i<=last;i++){
        printf("%d ",arr[i]);
    }
}