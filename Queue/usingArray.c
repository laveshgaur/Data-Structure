#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int front =-1;
int rear = -1;
int isEmpty(){
    if(rear==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(){
    if(rear+1==max){
        return 1;
    }else{
        return 0;
    }
}
void shift(int rear){
    for(int i=0;i<rear;i++){
        queue[i]=queue[i+1];
    }
}
int push(int data){
    if(isEmpty()){
        front++;
        rear++;
        queue[rear]=data;
        printf("Element pushed\n");
    }
    else if(!isFull()){
        queue[++rear]=data;
        printf("Element pushed\n");
    }
    else{
        printf("Queue overflow\n");
    }
}
int pop(){
    if(isEmpty()){
        printf("Queue Underflow\n");
    }
    else{
        shift(rear);
        printf("Element popped\n");
        rear--;
    }
    if(rear==-1){
        front--;
    }
}
int main(){
    while(1){
        int choice;
        printf("Queue size is 10\n");
        printf("1. Push\n2. Pop\n3. Print queue\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            int data;
            printf("Enter a value : ");
            scanf("%d",&data);
            push(data);
            printf("front is %d rear is %d \n",front,rear);
            break;
            case 2 :
            pop();
            printf("front is %d rear is %d \n",front,rear);
            break;
            case 3 :
            for(int i=0;i<=rear;i++){
                printf("%d ",queue[i]);
            }
            printf("\n");
            break;
            default :
            printf("Enter valid input\n");           
        }
    }
    return 0;
}