#include<stdio.h>
#include<stdlib.h>
void createDP(int arr[],int n,int sum,int dp[n+1][sum+1]){
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
    int sum;
    printf("Enter elements of array : ");
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        arr[i]=data;
        sum+=data;
    }

    int diff;
    printf("Enter difference : ");
    scanf("%d",&diff);

    int dp[n+1][sum+1];
    for(int j=0;j<sum+1;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    createDP(arr,n,sum,dp);
    int count=0;
    for(int i=0;i<sum/2+1;i++){
        if(dp[n][i]){
            int newdiff=sum-2*i;
            if(abs(newdiff)==diff){
                count++;
            }
        }
    }
    if(!count){
        printf("0 subset found with difference %d\n",diff);
    }else if(count==1){
        printf("Only %d subset found with %d difference\n",count,diff);
    }else{
        printf("%d subsets found with %d difference\n",count,diff);
    }
    return 0;
}