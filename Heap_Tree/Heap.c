#include<stdio.h>
#include<stdlib.h>

struct node {
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

struct node *insert(struct node *root,int data,int heapcase){//heapcase to check how to balance heap after insertion
    if(root==NULL){
        return create(data);
    }
    struct node *queue[50];
    int front=0;
    int rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node *temp=queue[front++];
        if(temp->left==NULL){
            temp->left=create(data);
            break;
        }else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=create(data);
            break;
        }else{
            queue[rear++]=temp->right;
        }
    }
    front--;
    switch(heapcase){
        case 1:
            while(front>=0){
                struct node *temp=queue[front];
                if(temp!=NULL){
                    if(temp->left!=NULL){
                        if(temp->left->data>temp->data){
                            int store=temp->left->data;
                            temp->left->data=temp->data;
                            temp->data=store;
                        }
                    }
                    if(temp->right!=NULL){
                        if(temp->right->data>temp->data){
                            int store=temp->right->data;
                            temp->right->data=temp->data;
                            temp->data=store;
                        }
                    }
                }
                front--;
            }
            break;
        case 2:
            while(front>=0){
                struct node *temp=queue[front];
                if(temp!=NULL){
                    if(temp->left!=NULL){
                        if(temp->left->data<temp->data){
                            int store=temp->left->data;
                            temp->left->data=temp->data;
                            temp->data=store;
                        }
                    }
                    if(temp->right!=NULL){
                        if(temp->right->data<temp->data){
                            int store=temp->right->data;
                            temp->right->data=temp->data;
                            temp->data=store;
                        }
                    }
                }
                front--;
            }
            break;
    }
    return root;
}

void printLevel(struct node *root){
    if(root==NULL){
        return;
    }
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
    printf("\n");
}
void showOptions(){
    printf("1) Max Heap\n");
    printf("2) Min Heap\n");
    printf("3) Both Heap\nEnter your choice : ");
}
int main(){
    struct node *root=NULL;
    int length;
    showOptions();
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter no. of elements : ");
            scanf("%d",&length);
            printf("Enter %d elements : ",length);
            for(int i=0;i<length;i++){
                int data;
                scanf("%d",&data);
                root=insert(root,data,1); 
            }
            printf("Your Max Heap is \n");
            printLevel(root);
            break;
        case 2:
            printf("Enter no. of elements : ");
            scanf("%d",&length);
            printf("Enter %d elements : ",length);
            for(int i=0;i<length;i++){
                int data;
                scanf("%d",&data);
                root=insert(root,data,2); 
            }
            printf("Your Min Heap is \n");
            printLevel(root);
            break;
        case 3:
            printf("Enter no. of elements : ");
            scanf("%d",&length);
            printf("Enter %d elements : ",length);
            struct node *root1=NULL;
            struct node *root2=NULL;
            for(int i=0;i<length;i++){
                int data;
                scanf("%d",&data);
                root1=insert(root1,data,1);
                root2=insert(root2,data,2); 
            }
            printf("Your Max Heap is \n");
            printLevel(root1);
            printf("Your Min Heap is \n");
            printLevel(root2);
            break;
        default:
            printf("Enter a valid choice\n");
    }
    
    return 0;
}