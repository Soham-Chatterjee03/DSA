#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root=NULL;
void preoderTraversal(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preoderTraversal(root->left);
    preoderTraversal(root->right);
}

int main ()
{
    struct node *node;
    struct node *node1;
    struct node *node2;
    struct node *node3;
    struct node *node4;
    struct node *node5;
    struct node *node6;
    
    node=(struct node *)malloc(sizeof(struct node));
    node1=(struct node *)malloc(sizeof(struct node));
    node2=(struct node *)malloc(sizeof(struct node));
    node3=(struct node *)malloc(sizeof(struct node));
    node4=(struct node *)malloc(sizeof(struct node));
    node5=(struct node *)malloc(sizeof(struct node));
    node6=(struct node *)malloc(sizeof(struct node));
    


    node->data=20;
    node->left=node1;
    node->right=node2;

    node1->data=15;
    node2->data=17;
    node3->data=19;
    node4->data=58;
    node5->data=11;
    node6->data=1;
    

    node1->left=node3;
    node1->right=node4;
    node2->left=node5;
    node2->right=node6;
    node3->left=NULL;
    node3->right=NULL;
    node4->left=NULL;
    node4->right=NULL;
    node5->left=NULL;
    node5->right=NULL;
    node6->left=NULL;
    node6->right=NULL;

    root=node;
    preoderTraversal(root);
    return 0;
}

/*
struct node *createtree(struct node *root){
    struct node *node,;
    int data;
    int choice;
    printf("Enter data \n");
    scanf("%d",&data);
    while (data!=-1)
    {
        node=(struct node *)malloc(sizeof(struct node));
        if(root==NULL){
            root->data=data;
            root->left=NULL;
            root->right=NULL;
        }
        else{
            printf("Enter 1 to insert to the left side of the tree 2 to enter the right side of the tree\n");
            scanf("%d",&choice);
            if(choice==1){
                
            }

        }
        

    }
    
    
}
*/


            
        
    