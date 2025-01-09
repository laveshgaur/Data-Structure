#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *create(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
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
    printf("Enter the values for insert in Binary Tree : ");
    char c='a';
    do{
        int data;
        scanf("%d",&data);
        c=getchar();
        root=insert(root,data);
    }while(c!='\n');
    printf("PreOrder is : ");
    preOrder(root);
    printf("\nInOrder is : ");
    inOrder(root);
    printf("\nPostOrder is : ");
    postOrder(root);
    printf("\n");
    return 0;
}