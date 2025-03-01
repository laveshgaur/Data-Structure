#include<stdio.h>

int count(int *arr,int arrsize,int sum){
    int dp[arrsize+1][sum+1];
    for(int j=0;j<sum+1;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<arrsize+1;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<arrsize+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[arrsize][sum];
}

int main(){
    int n;
    printf("Enter length of array : ");
    scanf("%d",&n);
    int arr[n];
    if(n>0)
    printf("Enter elements of array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum;
    printf("Enter subset sum : ");
    scanf("%d",&sum);
    int result=count(arr,n,sum);
    if(result==0){
        printf("No subset found\n");
    }else if(result==1){
        printf("Only %d subset is present with sum %d\n",result,sum);
    }else{
        printf("Total %d subsets are present with sum %d\n",result,sum);
    }
    return 0;
}