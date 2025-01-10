#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left , *right;
};
struct node *create(int data){
    struct node * newnode=(struct node *)malloc(sizeof(struct node)); 
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *findMin(struct node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node *insert(struct node *root,int data){
    if(root==NULL){
        root=create(data);
    }else{
        if(data<root->data){
            root->left=insert(root->left,data);
        }else{
            root->right=insert(root->right,data);
        }
    }
    return root;
}
struct node *delete(struct node *root,int target){
    if(root==NULL){
        return root;
    }else{
        if(root->data==target){
            if(root->left==NULL && root->right==NULL){
                free(root);
                return NULL;
            }else if(root->left==NULL || root->right==NULL){
                if(root->left==NULL){
                    struct node * temp=root;
                    temp=temp->right;
                    free(root);
                    return temp;
                }else{
                    struct node * temp=root;
                    temp=temp->left;
                    free(root);
                    return temp;
                }
            }else{
                struct node *newnode=findMin(root->right);
                root->data=newnode->data;
                root->right=delete(root->right,newnode->data);
            }
        }else if(target<root->data){
            root->left=delete(root->left,target);
        }else{
            root->right=delete(root->right,target);
        }
    }
    return root;
}
void preOrder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
int main(){
    struct node *root=NULL;
    printf("Enter numbers to insert in Binary Tree : ");
    char c;
    do{
        int data;
        scanf("%d",&data);
        c=getchar();
        root=insert(root,data);
    }while(c!='\n');
    printf("Before deleting element \nPreOrder is : ");
    preOrder(root);
    printf("\nInorder is : ");
    inOrder(root);
    printf("\nPostOrder is : ");
    postOrder(root);
    printf("\nEnter number to delete : ");
    int number;
    scanf("%d",&number);
    root=delete(root,number);
    printf("After deleting element \nPreOrder is : ");
    preOrder(root);
    printf("\nInorder is : ");
    inOrder(root);
    printf("\nPostOrder is : ");
    postOrder(root);
    printf("\n");
    return 0;
}