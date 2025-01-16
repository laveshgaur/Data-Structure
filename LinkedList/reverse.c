#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct node *insert(struct node *head,int data){
    if(head==NULL){
        return create(data);
    }else{
        head->next=insert(head->next,data);
    }
    return head;
}

struct node *reverse(struct node *curr,struct node *pre){
    if(curr==NULL){
        return pre;
    }
    struct node *next=curr->next;
    curr->next=pre;
    return reverse(next,curr);
}

void printList(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *head=NULL;
    int length;
    printf("Enter number of elements : ");
    scanf("%d",&length);
    printf("Enter your elements : ");
    for(int i=0;i<length;i++){
        int data;
        scanf("%d",&data);
        head=insert(head,data);
    }
    printf("Your linked list is : ");
    printList(head);
    printf("Reverse is : ");
    head=reverse(head,NULL);
    printList(head);
    return 0;
}