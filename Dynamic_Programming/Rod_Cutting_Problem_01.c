#include<stdio.h>

int max(int a,int b){
    return a>b ? a:b;
}

int knapsack(int lengthArr[],int price[],int n,int length){
    if(n==0 || length==0){
        return 0;
    }
    if(lengthArr[n-1]<=length){
        return max(price[n-1]+knapsack(lengthArr,price,n,length-lengthArr[n-1]),knapsack(lengthArr,price,n-1,length));
    }else{
        return knapsack(lengthArr,price,n-1,length);
    }
}

int main(){
    int n;
    printf("Enter size of length array : ");
    scanf("%d",&n);
    printf("Enter length array elements : ");
    int lengthArr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&lengthArr[i]);
    }
    printf("Enter price array elements : ");
    int price[n];
    for(int i=0;i<n;i++){
        scanf("%d",&price[i]);
    }
    int length;
    printf("Enter length of rod : ");
    scanf("%d",&length);
    printf("%d\n",knapsack(lengthArr,price,n,length));

    return 0;
}