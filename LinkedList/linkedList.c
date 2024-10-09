#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;    
};
void display(struct Node* ptr ){
    while (ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    struct Node *head,*second,*third;
    //Allocate memory in heap for the nodes of linked list;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    head->data=5;
    head->next=second;
    second->data=7;
    second->next=third;
    third->data=9;
    third->next=NULL;
    display(head);
}