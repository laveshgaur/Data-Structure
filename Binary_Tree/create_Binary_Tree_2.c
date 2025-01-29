#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left,*right;
};

// struct createTree

struct node *createNode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int findIndex(int *inorder,int start,int end,int data){
    for(int i=start;i<end+1;i++){
        if(inorder[i]==data){
            return i;
        }
    }
    return -1;
}

struct node *createTree(int *preorder,int *inorder,int start,int end,int *preIndex){
    if(start>end)return NULL;
    struct node *newnode=createNode(preorder[*preIndex]);
    (*preIndex)++;
    int index=findIndex(inorder,start,end,newnode->data);

    newnode->left=createTree(preorder,inorder,start,index-1,preIndex);
    newnode->right=createTree(preorder,inorder,index+1,end,preIndex);
    return newnode;
}

struct node* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex=0;
    return createTree(preorder,inorder,0,inorderSize-1,&preIndex);
}

int main(){
    int preorderSize,inorderSize;
    printf("Enter size of preOrder and inOrder : ");
    scanf("%d %d",&preorderSize,&inorderSize);
    int preOrder[preorderSize];
    int inOrder[inorderSize];
    printf("Enter values of preOrder : ");
    for(int i=0;i<preorderSize;i++){
        scanf("%d",&preOrder[i]);
    }
    printf("Enter values of inOrder : ");
    for(int i=0;i<inorderSize;i++){
        scanf("%d",&inOrder[i]);
    }
    struct node *tree=NULL;
    tree=buildTree(preOrder,preorderSize,inOrder,inorderSize);
    printf("Tree created successfully!\n");
    return 0;
}



