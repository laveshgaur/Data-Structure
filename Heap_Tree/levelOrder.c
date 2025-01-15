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
        return root;
    }else{
        struct node *queue[100];
        int front=0;
        int rear=0;
        queue[rear++]=root;
        while(front<rear){
            struct node *temp=queue[front++];
            if(temp->left==NULL){
                temp->left=insert(temp->left,data);
                break;
            }else{
                queue[rear++]=temp->left;
            }
            if(temp->right==NULL){
                temp->right=insert(temp->right,data);
                break;
            }else{
                queue[rear++]=temp->right;
            }
        }
    }
    return root;
}

void levelOrder(struct node *root){
    struct node *queue[100];
    int front=0;
    int rear=0;
    queue[rear++]=root;
    queue[rear++]=NULL;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp==NULL){
            printf("\n");
            if (front < rear) { 
                queue[rear++]=NULL;
            }
        }
        else{
            printf("%d ",temp->data);
            if(temp->left!=NULL){
                queue[rear++]=temp->left;
            }
            if(temp->right!=NULL){
                queue[rear++]=temp->right;
            }
        }
    }
}

void preOrder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    struct node *root=NULL;
    printf("Enter number of elements : ");
    int length;
    scanf("%d",&length);
    printf("Enter data to insert in Tree( %d elements limit ) : ",length);
    int i=0;
    while(i<length){
        int data;
        scanf("%d",&data);
        root=insert(root,data);
        i++;
    }
    printf("PreOrder is : ");
    preOrder(root);
    printf("\nLevel Order is \n");
    levelOrder(root);
    return 0;
}