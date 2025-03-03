#include<stdio.h>
#include<stdlib.h>

int count(int arr[],int n,int targetSum){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if((sum-targetSum)%2!=0 || sum-targetSum<0)return 0;
    targetSum=(sum+targetSum)/2;
   
    int dp[n+1][targetSum+1];
    for(int j=0;j<targetSum+1;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<targetSum+1;j++){
            if(arr[i]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][targetSum];
}

int main(){
    int n;
    printf("Enter length of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int targetSum;
    //it means difference of two subsets is targetSum
    printf("Enter target sum : ");
    scanf("%d",&targetSum);
    
    printf("%d ways to achieve sum as %d\n",count(arr,n,targetSum),targetSum);
    return 0;
}