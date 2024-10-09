#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* InsertAtStart(struct node *head,int data){
    struct node *ptr=(struct node *)(malloc(sizeof(struct node *)));
    if (ptr==NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    ptr->next=head;
    ptr->data=data; 
    return ptr;
}
void display(struct node *ptr){
    while (ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    struct node *head=NULL;
    int i=0;
    do{
        printf("Enter element : ");
        int data;
        scanf("%d",&data);
        head = InsertAtStart(head,data);
        printf("Updated linked list : ");
        display(head);
        i++;
    }while (i<5);
    return 0;
}