#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ways(int coin[],int n,int sum,int **dp){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1){
        return dp[n][sum];
    }
    if(coin[n-1]<=sum){
        return dp[n][sum]=(ways(coin,n,sum-coin[n-1],dp)+ways(coin,n-1,sum,dp));
    }else{
        return dp[n][sum]=ways(coin,n-1,sum,dp);
    }
}

int main(){
    int n;
    printf("Enter size of coin array : ");
    scanf("%d",&n);
    printf("Enter coin array elements : ");
    int coin[n];
    for(int i=0;i<n;i++){
        scanf("%d",&coin[i]);
    }
    int sum;
    printf("Enter coin sum : ");
    scanf("%d",&sum);
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for(int i = 0; i <= n; i++) {
        dp[i] = (int*)malloc((sum + 1) * sizeof(int));
        memset(dp[i], -1, (sum + 1) * sizeof(int));
    }
    memset(dp,-1,sizeof(dp));
    printf("Total Number of ways are %d\n",ways(coin,n,sum,dp));
    return 0;
}