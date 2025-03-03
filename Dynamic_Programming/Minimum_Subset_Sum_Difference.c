#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void createDP(int arr[],int sum,int n,int dp[n+1][sum+1]){
    
    for(int j=0;j<sum+1;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}

int main(){
    int n;
    printf("Enter length of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array : ");
    int sum=0;
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        arr[i]=data;
        sum+=data;
    }

    int dp[n+1][sum+1];
    createDP(arr,sum,n,dp);
    int min=INT_MAX;
    for(int i=0;i<sum/2+1;i++){
        if(dp[n][i]){
            int diff=abs(sum-2*i);
            if(diff<min){
                min=diff;
            }
        }
    }
    printf("Minimum subset sum difference is %d\n",min);
    return 0;
}