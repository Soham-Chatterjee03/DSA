#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *create_linked_list(struct node *head);
struct node *display_linked_list(struct node *head);
struct node *insert_begining(struct node *head);
struct node *insert_end(struct node *head);
struct node *insert_after_value(struct node *head);
struct node *delete_begining(struct node * head);
struct node *delete_end(struct node * head);
struct node *delete_a_node(struct node * head);

int main(){
    int option;
    do{
    printf("\n\n *****MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Add a node after a given node");
    printf("\n 6: Delete a node from the beginning");
    printf("\n 7: Delete a node from the end");
    printf("\n 8: Delete a given node");
    printf("\n 9: EXIT");

    printf("\n\n Enter your option : ");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        head=create_linked_list(head);
        printf("Linked List is Created");
        break;
        case 2:
        head=display_linked_list(head);
        break;
        case 3:
        head=insert_begining(head);
        break;
        case 4:
        head=insert_end(head);
        break;
        case 5:
        head=insert_after_value(head);
        break;
        case 6:
        head=delete_begining(head);
        break;
        case 7:
        head=delete_end(head);
        break;
        case 8:
        head=delete_a_node(head);
        break;

    }
    
    }while(option!=9);
}
//Creating a circular linked list
struct node *create_linked_list(struct node *head){
    struct node *ptr,*newnode;
    int value;

    printf("Enter -1 to End \n");
    printf("Enter a value \n");
    scanf("%d",&value);

    while(value!=-1){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
        }
        else{
            ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=head;
        }
        printf("Enter -1 to End \n");
        printf("Enter a value");
        scanf("%d",&value);

    }
    return head;
}
//display
struct node *display_linked_list(struct node *head){
    struct node *ptr;
    ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    return head;
}
//insert begining
struct node *insert_begining(struct node *head){
    struct node *ptr,*lastnode,*new_node;
    int value;

    lastnode=head;
    ptr=head;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter a value \n");
    scanf("%d",&value);
    
    new_node->data=value;

    while(lastnode->next!=head){
        lastnode=lastnode->next;
    }
    new_node->next=ptr;
    head=new_node;
    lastnode->next=head;

    return head;

}
//insert End
struct node *insert_end(struct node *head){
    struct node *lastnode,*new_node;
    int value;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter a value \n");
    scanf("%d",&value);
    
    new_node->data=value;

    lastnode=head;
    
    while(lastnode->next!=head){
        lastnode=lastnode->next;
    }
    lastnode->next=new_node;
    new_node->next=head;

    return head;

    
}
//insert after a value
struct node *insert_after_value(struct node *head){
    struct node *ptr,*new_node;
    int value,data;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter the value after you want to insert \n");
    scanf("%d",&value);
    printf("Enter the data in the new node");
    scanf("%d",&data);
    
    new_node->data=data;

    ptr=head;
    while(ptr->data!=value){
        ptr=ptr->next;
    }
    new_node->next=ptr->next;
    ptr->next=new_node;

    return head;
}
//delete begining
struct node *delete_begining(struct node * head){
    struct node *ptr,*lastnode;
    ptr=head;
    lastnode=head;
    
    while(lastnode->next!=head){
        lastnode=lastnode->next;
    }
    head=head->next;
    lastnode->next=head;
    free(ptr);  

    return head;  
}
//delete end
struct node *delete_end(struct node * head){
    struct node *ptr,*lastnode;
    lastnode=head;
    while(lastnode->next!=head){
        ptr=lastnode;
        lastnode=lastnode->next;
    }
    ptr->next=head;
    free(lastnode);
    return head;
}
//delete a node
struct node *delete_a_node(struct node * head){
    struct node *ptr,*preptr;
    int value;
    ptr=head;
    printf("Enter a value you want to delete \n");
    scanf("%d",&value);
    if(ptr->data==value){
        head=delete_begining(head);
        return head;
    }
    else{
        preptr=ptr;
        ptr=ptr->next;
        while(ptr->data!=value){
            preptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->next==head){
            head=delete_end(head);
            return head;
        }
        else{
            preptr->next=ptr->next;
            free(ptr);
            return head;
        }
    }
    

    return head;
}
//kturfkdfkydfkhfktgutf

