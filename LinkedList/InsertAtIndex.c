#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node*insert(struct node*head,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    if(index==0){
        ptr->next=head;
        return ptr;
    }
    else{
        struct node * temp=head;
        for(int i=0;i<index-1;i++){
            if(temp==NULL)break;
            temp=temp->next;
        }
        if (temp != NULL) {
            ptr->next = temp->next;
            temp->next = ptr;
        }
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
    struct node * head=NULL;
    for(int i=0;i<10;i++){
        printf("Enter index number and value : ");
        int index,value;
        scanf("%d%d",&index,&value);
        head=insert(head,value,index);
        display(head);
    }
}