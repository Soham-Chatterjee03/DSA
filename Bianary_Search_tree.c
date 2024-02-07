#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *tree=NULL;
struct node *insertBST(struct node *tree);
void preOrderTraversal(struct node *tree);
void inOrderTraversal(struct node *tree);
void postOrderTraversal(struct node *tree);
struct node *search(struct node *tree,int value);
void delete(struct node*tree,int value);
struct node *findlargestelement(struct node *tree);
int main(){
    int option,value;
    do
    {
        
        printf("1.Inserting in BST\n");
        printf("2.Preorder Traversal\n");
        printf("3.Inorder Traversal\n");
        printf("4.Postorder Traversal\n");
        printf("5.Search Bianary Search Tree\n");
        printf("6.Delete in a Bianary Search Tree\n");

        printf("Enter the option\n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            tree=insertBST(tree);
            break;
        case 2:
            preOrderTraversal(tree);
            break;
        case 3:
            inOrderTraversal(tree);
            break;
        case 4:
            postOrderTraversal(tree);
            break;
        case 5:
            printf("Enter the number you want to search\n");
            scanf("%d",&value);
            search(tree,value);
            break;
        case 6:
            printf("Enter the number you want to delete\n");
            scanf("%d",&value);
            delete(tree,value);
            break;
        case 7:
            findlargestelement(tree);

    
        }
            
    }while (option!=10);
     
}
struct node *insertBST(struct node *tree){
    int value;
    struct node *ptr,*nodeptr,*parentptr;
    printf("Enter the value you want to insert\n");
    scanf("%d",&value);
    while(value!=-1){
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=value;
        ptr->right=NULL;
        ptr->left=NULL;

        if(tree==NULL){
            tree=ptr;
        }
        else{
            nodeptr=tree;
            while(nodeptr!=NULL){
                parentptr=nodeptr;
                if(value>nodeptr->data){
                    nodeptr=nodeptr->right;
                }
                else{
                    nodeptr=nodeptr->left;
                }
            }
            if(value>parentptr->data){
                parentptr->right=ptr;
            }
            else{
                parentptr->left=ptr;
            }
        }
        printf("Enter the value you want to insert\n");
        scanf("%d",&value);
        
        
    }
    return tree;
}
void preOrderTraversal(struct node *tree){
    if (tree!=NULL)
    {
        printf("%d ",tree->data);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
    
}
void inOrderTraversal(struct node *tree){
    if (tree!=NULL)
    {
        inOrderTraversal(tree->left);
        printf("%d ",tree->data);
        inOrderTraversal(tree->right);
    }
    
}
void postOrderTraversal(struct node *tree){
    if (tree!=NULL)
    {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d ",tree->data);
    }
    
}
struct node *search(struct node *tree,int value){
    if(tree==NULL){
        printf("No BST present\n");
        return tree;
    }
    if(tree->data==value){
        printf("value fount at address %p\n",tree);
        return tree;
    }
    else if(value>tree->data){
        search(tree->right,value);
    }
    else{
        search(tree->left,value);
        
    }
}
void delete(struct node*tree,int value){
    struct node *temp;
    if(tree==NULL){
    }
    else if(value>tree->data){
        delete(tree->right,value);
    }
    else if(value<tree->data){
        delete(tree->left,value);
    }
    else if(tree->left!=NULL && tree->right!=NULL){
        temp=findlargestelement(tree->left);
        tree->data=temp->data;
        delete(tree->left,temp->data);
    }
    else{
        if(tree->left==NULL && tree->right==NULL){
            tree=NULL;
        }
        else if (tree->left!=NULL){
            temp=tree->left;
            tree=tree->left;
        }
        else{
            temp=tree->right;
            tree=tree->right;
        }
        free(temp);
        
        
    }
}
struct node *findlargestelement(struct node *tree){
    if(tree==NULL || tree->right==NULL){
        return tree;
    }
    else
        return findlargestelement(tree->right);
}