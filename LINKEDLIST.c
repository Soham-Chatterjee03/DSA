#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *create_linked_list(struct node *head);
struct node *display_linked_list(struct node *head);
struct node *insert_at_begining(struct node *head);
struct node *insert_at_end(struct node *head);
struct node *insert_after(struct node *head);
struct node *insert_before(struct node *head);
struct node *delete_beg(struct node *head);
struct node *delete_end(struct node *head);
struct node *delete_a_node(struct node *head);

int main(){
    int option;
    do{
    printf("\n\n *****MAIN MENU *****");
    printf("\n 1: Create a list");
    printf("\n 2: Display the list");
    printf("\n 3: Add a node at the beginning");
    printf("\n 4: Add a node at the end");
    printf("\n 5: Add a node before a given node");
    printf("\n 6: Add a node after a given node");
    printf("\n 7: Delete a node from the beginning");
    printf("\n 8: Delete a node from the end");
    printf("\n 9: Delete a given node");
    printf("\n 10: Delete a node after a given node");
    printf("\n 11: Delete the entire list");
    printf("\n 12: Sort the list");
    printf("\n 13: EXIT");
    printf("\n\n Enter your option : ");
    scanf("%d", &option);
    switch(option)
    {
    case 1: head = create_linked_list(head);
    printf("\n LINKED LIST CREATED");
    break;
    case 2: head = display_linked_list(head);
    break;
    case 3: head = insert_at_begining(head);
    break;
    case 4: head = insert_at_end(head);
    break;
    case 5: head = insert_before(head);
    break;
    case 6: head = insert_after(head);
    break;
    case 7: head = delete_beg(head);
    break;
    case 8: head = delete_end(head);
    break;
    case 9: head = delete_a_node(head);
    break;
    }
}while(option !=10);

return 0;
}

    
    


//Creating a linked List
struct node *create_linked_list(struct node *head){
    struct node *ptr,*new_node;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter a number ");
    scanf("%d",&num);
    while(num!=-1){
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        if(head==NULL){
            head=new_node;
            new_node->next=NULL;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;

        }
        printf("Enter a number ");
        scanf("%d",&num);
    }
    return head;
}
//Display of Linked list
struct node *display_linked_list(struct node *head){
    struct node *ptr;
    ptr=head;
    while (ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
    }
    return head;
}
//Insert a Linked List at Begining
struct node *insert_at_begining(struct node *head){
    struct node *new_node;
    int num;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter a number at the begining of the linked List\n");
    scanf("%d",&num);

    new_node->data=num;
    new_node->next=head;
    head=new_node;

    return head;
    
}
//insert at end
struct node *insert_at_end(struct node *head){
    struct node *ptr,*new_node;
    int num;
    
    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter a number at the end \n");
    scanf("%d",&num);

    new_node->data=num;
    new_node->next=NULL;

    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    
    return head;

}
//insert after a node
struct node *insert_after(struct node *head){
    struct node *ptr,*new_node,*preptr;
    int num,value;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter a number \n");
    scanf("%d",&num);
    printf("Enter a number after you want to insert \n");
    scanf("%d",&value);

    new_node->data=num;

    preptr=head;
    ptr=head->next;

    while(preptr->data!=value){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;

    return head;
    
}
//insert before a node
struct node *insert_before(struct node *head){
    struct node *ptr,*new_node,*preptr;
    int num,value;

    new_node=(struct node *)malloc(sizeof(struct node));

    printf("Enter a number \n");
    scanf("%d",&num);
    printf("Enter a number before you want to insert \n");
    scanf("%d",&value);

    new_node->data=num;

    ptr=head;
    
    while(ptr->data!=value){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;

    return head;
    
}
//delete begining
struct node *delete_beg(struct node *head){
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
}
//delete end
struct node *delete_end(struct node *head){
    struct node *ptr,*preptr;
    preptr=head;
    ptr=head->next;
    while(ptr!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);

    return head;

}
//delete a node
struct node *delete_a_node(struct node *head){
    struct node *preptr,*ptr;
    int value;

    preptr=head;
    ptr=head->next;

    printf("Enter the value you want to delete \n");
    scanf("%d",&value);

    if(preptr->data==value){
        head=delete_beg(head);
        return head;
    }
    else{
        while(ptr->data!=value){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return head;
    }
    


}


