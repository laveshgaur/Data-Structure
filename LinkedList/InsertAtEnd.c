#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* InsertAtEnd(struct node *head,int data){
    struct node* ptr = (struct node*)(malloc(sizeof(struct node *)));
    ptr->data=data;
    ptr->next=NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    return head;
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
    for(int i=0;i<5;i++){
        int data;
        printf("Enter element : ");
        scanf("%d",&data);
        head=InsertAtEnd(head,data);
        printf("Updated linked list : ");
        display(head);
    }

}