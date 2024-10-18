#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *insert(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    if(head==NULL){
        ptr->next=ptr;
        return ptr;
    }
    else{
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        ptr->next=head;
        temp->next=ptr;
        return head;
    }
}
void display(struct node *head){
    struct node *temp=head;
    do{
        printf("Data = %d , Next address = %d \t\n",temp->data,temp->next);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
int main(){
    struct node *head=NULL;
    printf("Enter 5 elements : ");
    for(int i=0;i<5;i++){
        int data;
        scanf("%d",&data);
        head=insert(head,data);
    }
    display(head);
}