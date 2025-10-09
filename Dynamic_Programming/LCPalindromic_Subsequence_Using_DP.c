// Code to find out the length of Longest Common Palindromic Subsequence using Dynamic Programming
#include<stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    int n;
    printf("Enter length of string : ");
    scanf("%d",&n);
    if(n <= 0){
        printf("Enter Invalid Input\n");
        return 0;
    }
    char str[n];
    getchar();
    printf("Enter string : ");
    for(int i = 0 ; i < n ; i++){
        scanf("%c",&str[i]);
    }
    int dp[n][n];
    for(int i = 0 ; i < n ; i++){
        dp[i][i] = 1;
    }
    for(int len = 2 ; len <= n ; len++){
        for(int i = 0 ; i <= n - len ; i++){
            int j = i + len - 1;
            if(str[i] == str[j] && len == 2){
                dp[i][j] = 2;
            }else if(str[i] == str[j]){
                dp[i][j] = dp[i+1][j-1] + 2; 
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    printf("Longest Palindromic Subsequence length is : %d\n",dp[0][n-1]);
    return 0;
}