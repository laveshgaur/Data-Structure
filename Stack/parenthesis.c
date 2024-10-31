#include<stdio.h>
#include<stdlib.h>
struct node{
    char c;
    struct node *next;
};
struct node *push(struct node *top,char c){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->c=c;
    ptr->next=top;
    return ptr;
}
struct node *pop(struct node *top,int *underflow){
    if(top==NULL){
        (*underflow)++;
        return top;
    }else{
        return top->next;
    }
}
int check(struct node *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int main(){
    int underflow=0;
    struct node *top;
    printf("Enter expression : ");
    char open[]={'[','{','('};
    char close[]={']','}',')'};
    char expression[20];
    int i=0;
    do{
        scanf("%c",&expression[i++]);
    }while(expression[i-1]!='\n');
    int flag=0;
    for(int j=0;j<i;j++){
        for(int k=0;k<3;k++){
            if(expression[j]==open[k]){
                top=push(top,open[k]);
                flag++;
            }
            else if(expression[j]==close[k]){
                if(top->c==open[k])
                    top=pop(top,&underflow);
            }
            else{
                continue;
            }
        }
    }
    if(underflow==0 && check(top)){
        printf("Balanced\n");
    }
    else{
        printf("Unbalanced\n");
    }
}