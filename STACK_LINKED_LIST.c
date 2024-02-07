#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *pre;
    int data;
    
};

struct node *top=NULL;
struct node *push(struct node *top);
struct node *pop(struct node *top);
struct node *peek(struct node *top);
struct node *display(struct node *top);

int main(){
    int option;
    do
    {
        printf("\n****MAIN MENU*****");
        printf("\n 1.Push value");
        printf("\n 2.Pop value");
        printf("\n 3.Peek");
        printf("\n 4.Display");
        printf("\n 5.Exit");

        printf("\n Enter your option ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            top=push(top);
            printf("\n The stack is created");
            break;
        case 2:
            top=pop(top);
            break;
        case 3:
            top=peek(top);
            break;
        case 4:
            top=display(top);
            break;
        
        }

    } while (option!=5);
    
}
struct node *push(struct node *top){
    int data;
    struct node *new_node;

    

    printf("\n Enter -1 to End");
    printf("\n Enter the value you want to insert ");
    scanf("%d",&data);
    while (data!=-1){
        new_node=(struct node *)malloc(sizeof(struct node));

        if(top==NULL){
            new_node->data=data;
            new_node->pre=NULL;
            top=new_node;


        }
        else{
            new_node->data=data;
            new_node->pre=top;
            top=new_node;

        }
        printf("\n Enter -1 to End");
        printf("\n Enter the value you want to insert ");
        scanf("%d",&data);

    }

    return top;
    

}
struct node *pop(struct node *top){
    struct node *ptr;
    ptr=top;
    printf("\n The value deleted is %d",top->data);
    top=top->pre;
    free(ptr);

    return top;
}
struct node *peek(struct node *top){
    printf("\nThe Top value is %d",top->data);
    return top;
}
struct node *display(struct node *top){
    struct node *ptr;
    ptr=top;
    while(ptr!=NULL){
        printf("\n %d ",ptr->data);
        ptr=ptr->pre;
    }
    return top;
     
}
