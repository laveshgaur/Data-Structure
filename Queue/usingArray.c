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
    else if(front==rear){
        front=-1;
        rear=-1;
        printf("Element popped\n");
    }
    else{
        front++;
        printf("Element popped\n");
    }
}
int main(){
    while(1){
        int choice;
        printf("1. Push\n2. Pop\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
            int data;
            printf("Enter a value : ");
            scanf("%d",&data);
            push(data);
            printf("%d %d \n",front,rear);
            break;
            case 2 :
            pop();
            break; 
            default :
            printf("Enter valid input\n");           
        }
    }
    return 0;
}