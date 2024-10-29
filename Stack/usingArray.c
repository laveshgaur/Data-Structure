#include<stdio.h>
void pop(int *top){
    (*top)--;
}
void push(int arr[],int n,int *top){
    if(*top<9){
        arr[++*top]=n;
    }else{
        printf("Stack overflow\nDeleting an element type 1 and press enter\n");
        int number;
        scanf("%d",&number);
        if(number==1){
            printf("Enter number of pop operations : ");
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;i++)pop(top);
        }else{
            printf("Invalid operation\n");
        }
    }
    
}
void display(int arr[],int top){
    while(top>-1){
        printf("%d\n",arr[top--]);
    }
}
int main(){
    int arr[10];
    int top=-1;
    int n;
    printf("Enter number of operations : ");
    scanf("%d",&n);
    int i=0;
    while(i++<n){
        printf("Enter element to push : ");
        int number;
        scanf("%d",&number);
        push(arr,number,&top);
    }
    display(arr,top);
}