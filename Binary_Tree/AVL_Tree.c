#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left,*right;
    int height;
};
int getMax(int a,int b){
    return (a > b) ? a : b ;
}

int getHeight(struct node *root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int getBalanceFactor(struct node *root){
    if(root==NULL){
        return 0;
    }
    return (getHeight(root->left)-getHeight(root->right));
}

struct node *create(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    newnode->height=1;
    return newnode;
}

struct node *leftRotate(struct node *root){
    if(root==NULL || root->right==NULL){
        return root;
    }
    struct node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    temp->height=getMax(getHeight(temp->left),getHeight(temp->right))+1;
    return temp;
}

struct node *rightRotate(struct node *root){
    if(root==NULL || root->left==NULL){
        return root;
    }
    struct node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root->height=getMax(getHeight(root->left),getHeight(root->right))+1;
    temp->height=getMax(getHeight(temp->left),getHeight(temp->right))+1;
    return temp;
}

struct node *insert(struct node *root,int data){
    if(root==NULL){
        root=create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right,data);
    }else{
        return root;
    }

    root->height=1+getMax(getHeight(root->left),getHeight(root->right));
    int balanceFactor=getBalanceFactor(root);
    
    if(balanceFactor > 1 && data < root->left->data){
        return rightRotate(root);
    }
    
    if(balanceFactor < -1 && data>root->right->data){
        return leftRotate(root);
    }
    
    if(balanceFactor > 1 && data >root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    
    if(balanceFactor < -1 && data < root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
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

 void Show_Menu(){
    printf("1) PreOrder\n2) InOrder\n3) PostOrder\n");
}

int main(){
    struct node *root=NULL;
    printf("Press Enter without space when data is complete\nEnter data to insert in AVL Tree : ");
    char c;
    do{
        int data;
        scanf("%d",&data);
        c=getchar();
        root=insert(root,data);
    }while(c!='\n');
    Show_Menu();
    printf("Enter your choice : ");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("PreOrder is : ");
            preOrder(root);
            break;
        case 2:
            printf("InOrder is : ");
            inOrder(root);
            break;
        case 3:
            printf("PostOrder is : ");
            postOrder(root);
            break;
        default: 
            printf("Enter valid choice\n");
    }
    printf("\n");
    return 0;
}