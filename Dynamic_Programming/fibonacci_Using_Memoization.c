#include<stdio.h>
#include<string.h>

int fibo(int n ,int arr[]){
    if(n<=1){
        arr[n]=n;
        return n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }else{
        return arr[n]=fibo(n-1,arr)+fibo(n-2,arr);
    }
}

int main(){
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=-1;
    }
    if(n>0){
        fibo(n-1,arr);

        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    }else{
        printf("Enter positive number");
    }
    printf("\n");
    return 0;
}