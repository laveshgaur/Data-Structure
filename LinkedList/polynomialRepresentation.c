#include<stdio.h>
#include<stdlib.h>
struct node {
    int coeff;
    int power;
    struct node *next;
};
struct node *insert(struct node *head,int coeff,int power){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->power=power;
    ptr->coeff=coeff;
    ptr->next=NULL;
    if(head==NULL){
        return ptr;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        return head;
    }
}
void display(struct node *head){
    struct node *temp=head;
    while(temp->next!=NULL){
        printf("%dx^%d + ",temp->coeff,temp->power);
        temp=temp->next;
    }
    if(temp->power==0){
        printf("%d\n",temp->coeff);
    }
    else{
        printf("%dx^%d\n",temp->coeff,temp->power);
    }
}
int main(){
    struct node *head=NULL;
    printf("Enter number of coefficients : ");
    int n;
    scanf("%d",&n);
    printf("Enter coefficient and power respectively : ");
    for(int i=0;i<n;i++){
        int coeff,power;
        scanf("%d %d",&coeff,&power);
        head=insert(head,coeff,power);
    }
    display(head);
}