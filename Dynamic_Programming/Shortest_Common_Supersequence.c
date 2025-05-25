// Shortest Common SuperSequence
#include<stdio.h>
#include<string.h>

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    int m,n;
    printf("Enter length of first string : ");
    scanf("%d",&m);
    printf("Enter length of second string : ");
    scanf("%d",&n);
    char str1[m+1],str2[n+1];
    printf("Enter first string : ");
    scanf("%s",str1);
    printf("Enter second string : ");
    scanf("%s",str2);

    int dp[m+1][n+1];
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("\nLength of shortest common supersequence : %d\n",m+n-dp[m][n]);


    return 0;

}