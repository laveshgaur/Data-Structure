#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *pre;
    struct node *next;
};
struct node *insert(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data=data;
    if(head==NULL){
        ptr->pre=NULL;
        ptr->next=NULL;
        return ptr;
    }else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        ptr->pre=temp;
        ptr->next=NULL;
        temp->next=ptr;
        return head;
    }
}
struct node *delete(struct node *head,int data){
    struct node *temp=head;
    if(temp==NULL){
        return head;
    }
    while(temp!=NULL && temp->data!=data){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found \n");
        return head;
    }
    if(temp->pre==NULL ){
        head=temp->next;
        free(temp);
        return head;
    }
    if(temp->next==NULL){
        temp->pre->next=NULL;
        free(temp);
        return head;
    }
    if(temp->data==data && temp!=NULL){
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        free(temp);
        return head;
    }
}
void display(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }printf("\n");
}
int main(){
    struct node *head=NULL;
    printf("Enter 5 elements for doubly linked list : ");
    for(int i=0;i<5;i++){
        int data;
        scanf("%d",&data);
        head=insert(head,data);
    }
    printf("Enter element to delete : ");
    int del;
    scanf("%d",&del);
    head=delete(head,del);
    display(head);
}