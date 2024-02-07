#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *pre;
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *create_doubly_linked_list(struct node *head);
struct node *display_linked_list(struct node *head);
struct node *insert_at_begining(struct node *head);
struct node *insert_at_end(struct node *head);

int main(){
    int option;
    do{
    printf("\n\n *****MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");

    printf("\n\n Enter your option : ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    head=create_doubly_linked_list(head);
    printf("\n List created Successhully\n");
    break;
    case 2:
    head=display_linked_list(head);
    break;
    case 3:
    head=insert_at_begining(head);
    break;
    case 4:
    head=insert_at_end(head);
    break;
    
    
    }

    }while(option!=10);
}
//Create a doubly liked list
struct node *create_doubly_linked_list(struct node *head){
    struct node *ptr,*new_node;
    int value;

    printf("Enter -1 to End\n");
    printf("Enter the data\n");
    scanf("%d",&value);
    while(value!=-1){
        if(head==NULL){
            new_node=(struct node *)malloc(sizeof(struct node));
            new_node->data=value;
            new_node->pre=NULL;
            new_node->next=NULL;

            head= new_node;
        }
        else{
            ptr=head;
            new_node=(struct node *)malloc(sizeof(struct node));
            new_node->data=value;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->pre=ptr;
            new_node->next=NULL;
        }
        printf("Enter the data\n");
        scanf("%d",&value);
    }
    return head;
}
//Display of linked list
struct node *display_linked_list(struct node *head){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    return head;

}
//Insert at begining
struct node *insert_at_begining(struct node *head){
    struct node *ptr,*new_node;
    int value;
    ptr=head;
    printf("Enter the value you want to insert at the begining \n");
    scanf("%d",&value);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->pre=NULL;
    new_node->data=value;
    new_node->next=ptr;
    ptr->pre=new_node;
    head=new_node;

    return head;
}
//inserrt at the end
struct node *insert_at_end(struct node *head){
    struct node *ptr,*new_node;
    int value;
    ptr=head;
    printf("Enter the value you want to insert at the end\n");
    scanf("%d",&value);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->pre=ptr;


}
//insert after a node
struct node *insert_after_a_value(struct node *head){
    struct node *ptr,*new_node,*postptr;
    int value,data;
    printf("Enter the value you want to insert after \n");
    scanf("%d",&value);
    printf("Enter the value you want to insert  \n");
    scanf("%d",&data);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=data;
    ptr=head;
    while(ptr->data!=value){
        ptr=ptr->next;
    }
    postptr=ptr->next;
    ptr->next=new_node;
    new_node->pre=ptr;
    new_node->next=postptr;
    postptr->pre=new_node;

    return head;

    
}
