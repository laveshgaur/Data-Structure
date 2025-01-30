#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

struct node *createNode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int findIndex(int *inorder,int start,int end,int data){
    for(int i=start;i<=end;i++){
        if(inorder[i]==data)return i;
    }
    return -1;
}

struct node *createTree(int *inorder,int start,int end,int* postorder,int *postIndex){
    if(start>end)return NULL;
    struct node *newnode=createNode(postorder[*postIndex]);
    (*postIndex)--;

    int index=findIndex(inorder,start,end,newnode->data);
    
    newnode->right=createTree(inorder,index+1,end,postorder,postIndex);
    newnode->left=createTree(inorder,start,index-1,postorder,postIndex);
    return newnode;
}

struct node* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex=postorderSize-1;
    return createTree(inorder,0,inorderSize-1,postorder,&postIndex);
}

int main(){
    int postorderSize,inorderSize;
    printf("Enter size of inOrder and postOrder : ");
    scanf("%d %d",&inorderSize,&postorderSize);
    int postOrder[postorderSize];
    int inOrder[inorderSize];
    printf("Enter values of inOrder : ");
    for(int i=0;i<inorderSize;i++){
        scanf("%d",&inOrder[i]);
    }
    printf("Enter values of postOrder : ");
    for(int i=0;i<postorderSize;i++){
        scanf("%d",&postOrder[i]);
    }
    struct node *tree=NULL;
    tree=buildTree(inOrder,inorderSize,postOrder,postorderSize);
    printf("Tree created successfully!\n");
    return 0;
}