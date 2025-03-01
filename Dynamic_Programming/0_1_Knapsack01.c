#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>b ? a:b;
}

int knapsack(int *val,int *wt,int n,int w){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(val,wt,n-1,w-wt[n-1]),knapsack(val,wt,n-1,w));
    }else{
        return knapsack(val,wt,n-1,w);
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
    printf("Max profit is %d\n",knapsack(val,wt,n,w));
    return 0;
}