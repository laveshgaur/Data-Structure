#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b){
    return a>b ? a:b;
}

int knapsack(int *val,int *wt,int n,int w,int dp[][w+1]){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        return dp[n][w] = max(val[n-1]+knapsack(val,wt,n-1,w-wt[n-1],dp),knapsack(val,wt,n-1,w,dp));
    }else{
        return dp[n][w] = knapsack(val,wt,n-1,w,dp);
    }
}

int main(){
    int n;
    printf("Enter your length of value array : ");
    scanf("%d",&n);
    int val[n];
    int wt[n];
    
    printf("Enter elements of value array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }

    printf("Enter elements of weight array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    int w;
    printf("Enter weight of knapsack : ");
    scanf("%d",&w);
    int dp[n+1][w+1];
    memset(dp,-1,sizeof(dp));
    printf("Max profit is %d\n",knapsack(val,wt,n,w,dp));
    return 0;
}