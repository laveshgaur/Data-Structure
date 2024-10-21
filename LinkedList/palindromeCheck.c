//USING SINGLE LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *insert(struct node *head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    if(head==NULL){
        ptr->next=NULL;
        return ptr;
    }
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ptr->next=NULL;
    temp->next=ptr;
    return head;
}
struct node *insertAtStart(struct node *head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}
void check(struct node *head){
    struct node *new=NULL;
    struct node *temp=head;
    while(temp!=NULL){
        new=insertAtStart(new,temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data==new->data){
            temp=temp->next;
            new=new->next;
        }
        else{
            printf("Not palindrome \n");
            return;
        }
    }
    printf("palindrome \n");
    return;
}
int main(){
    struct node *head=NULL;
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        head=insert(head,data);
    }
    check(head);
}