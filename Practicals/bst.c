#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *root=NULL;
struct TreeNode *insert(struct TreeNode *root){
    int val;
    struct TreeNode *node;
    struct TreeNode *nodeptr;
    struct TreeNode *parentptr;
    printf("Enter the value you want to insert \n");
    scanf("%d",&val);
    while(val!=-1){
        node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->data=val;
        node->left=NULL;
        node->right=NULL;
        if (root==NULL){
            root=node;
        }
        else{
            
            nodeptr=root;
            while(nodeptr!=NULL){
                parentptr=nodeptr;
                if(val>nodeptr->data){
                    nodeptr=nodeptr->right;
                }
                else{
                    nodeptr=nodeptr->left;
                }

            }
            if(val>parentptr->data){
                parentptr->right=node;
            }
            else{
                parentptr->left=node;
            }
            
        }
        printf("Enter the value you want to insert \n");
        scanf("%d",&val);

    }
    return root;

}
void inordertraversal(struct TreeNode *root){
    if(root!=NULL){
        inordertraversal(root->left);
        printf("%d ",root->data);
        inordertraversal(root->right);
    }
}
void preordertraversal(struct TreeNode *root){
    if(root!=NULL){
        printf("%d ",root->data);
        inordertraversal(root->left);
        
        inordertraversal(root->right);
    }
}
int main(){
    int option,value;
    root=insert(root);
    inordertraversal(root);
    preordertraversal(root);
    
     
}