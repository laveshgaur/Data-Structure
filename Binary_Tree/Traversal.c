#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
struct node *create(){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data (-1 for no node) : ");
    int data;
    scanf("%d",&data);
    if(data==-1){
        return 0;
    }
    newnode->data=data;
    printf("Enter left child of %d\n",data);
    newnode->left=create();
    printf("Enter right child of %d\n",data);
    newnode->right=create();
    return newnode;
}
void printChoices(){
    printf("Your choices are \n");
    printf("1) InOrder Traversal\n");
    printf("2) PreOrder Traversal\n");
    printf("3) PostOrder Traversal\n");
}
void inOrder();
void preOrder();
void postOrder();
int main(){
    struct node *root;
    root = create();
    printChoices();
    printf("Enter your choice : ");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("InOrder Traversal is : ");
            inOrder(root);
            printf("\n");
            break;
        case 2:
            printf("PreOrder Traversal is : ");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            printf("PostOrder Traversal is : ");
            postOrder(root);
            printf("\n");
            break;
        default:
            printf("Enter valid choice\n");     
    }
}
void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void preOrder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}