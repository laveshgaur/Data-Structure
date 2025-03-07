#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){
    return a>b ? a:b;
}

int knapsack(int *lengthArr, int *price, int n, int length, int **dp){
    if(n==0 || length==0){
        return 0;
    }
    if(dp[n][length]!=-1){
        return dp[n][length];
    }
    if(lengthArr[n-1]<=length){
        return dp[n][length]=max(price[n-1]+knapsack(lengthArr,price,n,length-lengthArr[n-1],dp),knapsack(lengthArr,price,n-1,length,dp));
    }else{
        return dp[n][length]=knapsack(lengthArr,price,n-1,length,dp);
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
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for(int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((length + 1) * sizeof(int));
        memset(dp[i], -1, (length + 1) * sizeof(int));
    }
    printf("Max Profit is %d\n",knapsack(lengthArr,price,n,length,dp));
    
    return 0;
}