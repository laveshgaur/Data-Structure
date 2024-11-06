#include<stdio.h>
#include<stdlib.h>
struct node {
    char c;
    int priority;
    struct node *next;
};
struct node *insertSymbol(struct node * symbol,char c,int priority){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->c=c;
    ptr->priority=priority;
    ptr->next=NULL;
    return ptr;
}
struct node *insert(struct node *top,char c){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->c=c;
    ptr->next=NULL;
    if(top==NULL){
        return ptr;
    }else{
        struct node *temp=top;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        return top;
    }

}
void display(struct node *temp){
    while(temp!=NULL){
        printf("%c",temp->c);
        temp=temp->next;
    }
}
struct node *postfix(struct node expression,struct node symbol,struct node top){
    
}
int main(){
    struct node *top=NULL;
    struct node *symbol=NULL;
    char c[]={'+','-','*','/'};
    int position=0;
    int priority=1;
    for(int i=0;i<2;i++){
        symbol=insertSymbol(symbol,c[position++],priority);
        symbol=insertSymbol(symbol,c[position++],priority++);
    }
    printf("Enter expression : ");
    char c;
    scanf("%c",&c);
    if(c!='(')
        top=insert(top,c);
    do{
        scanf("%c",&c);
        if(c==')')break;
        if(c=='\n')break;
        top=insert(top,c);
    }while(1);
    struct node *expression=NULL;
    expression=postfix(expression,symbol,top);
    display(expression);
}