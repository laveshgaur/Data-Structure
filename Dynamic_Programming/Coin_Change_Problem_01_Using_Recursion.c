#include<stdio.h>

int max(int a,int b){
    return a>b ? a:b;
}

int ways(int coin[],int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(coin[n-1]<=sum){
        return (ways(coin,n,sum-coin[n-1])+ways(coin,n-1,sum));
    }else{
        return ways(coin,n-1,sum);
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
    printf("Total Number of ways are %d\n",ways(coin,n,sum));
    return 0;
}