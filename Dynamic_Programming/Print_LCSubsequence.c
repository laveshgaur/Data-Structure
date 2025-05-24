// "Print_Longest_Common_Subsequence_Using_Dynamic_Programming"
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a > b ? a : b;
}

int min(int a,int b){
    return a < b ? a : b;
}

int main(){
    int n,m;
    printf("Enter length of first string : ");
    scanf("%d",&n);
    printf("Enter length of second string : ");
    scanf("%d",&m);

    char *str1=malloc(sizeof(char)*(n+1));
    char *str2=malloc(sizeof(char)*(m+1));
    printf("Enter first string : ");
    scanf("%s", str1);
    printf("Enter second string : ");
    scanf("%s", str2);

    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    printf("\nTable of Dynamic Programming\n\n");
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }

    char LCS[min(n,m)];
    int index=0;
    for(int i=n;i>=1;){
        for(int j=m;j>=1;){
            if(str1[i-1]==str2[j-1]){
                LCS[index++]=str1[i-1];
                i--,j--;
            }else{
                if(dp[i-1]>dp[j-1]){
                    i--;
                }else{
                    j--;
                }
            }
        }
    }

    printf("\nLongest common subsequence is : ");
    for(int i=index-1;i>=0;i--){
        printf("%c",LCS[i]);
    }
    printf("\n");

    return 0;
}