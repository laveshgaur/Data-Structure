// Code to find out the length of Longest Common Palindromic Subsequence using recursion
#include<stdio.h>

int max(int a, int b){
    return a > b ? a : b;
}

int LCPS(int n, int m, char str[]){
    if(n > m){
        return 0;
    }
    if( n == m ){
        return 1;
    }
    if(str[n] == str[m]){
        return LCPS(n + 1 , m - 1 , str) + 2;
    }
    return max(LCPS(n + 1 , m , str), LCPS(n , m - 1, str));
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
    printf("Longest Palindromic Subsequence length is : %d\n",LCPS(0,n-1,str));
    return 0;
}