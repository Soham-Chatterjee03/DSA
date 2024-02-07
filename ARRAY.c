#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
int arr[SIZE];
int size=0;
int main(){
    int i,data;
    printf("Enter the number o values");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        scanf("%d",&data);
        arr[i]=data;
    }
    display(arr);
    insert(arr);
    display(arr);
    delete(arr);
    display(arr);


}
void insert(int arr[]){
    int data;
    int i,index;
    printf("Enter a value");
    scanf("%d",&data);
    printf("Enter the index");
    scanf("%d",&index);
    for(i=size-1;i>=(index-1);i--){

        arr[i+1]=arr[i];
    }
    arr[index-1]=data;
    size++;

}
void delete(int arr[]){
    int index,i;
    printf("Enter the index");
    scanf("%d",&index);
    for(i=index-1;i<size;i++){
        arr[i]=arr[i+1];
    }
    size--;
}
void display(int arr[]){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}