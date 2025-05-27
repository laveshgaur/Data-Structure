// Minimum_Number_of_insertion_and_deletion_is_required_to_convert_a_string_to_b

#include<stdio.h>

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    int n,m;
    printf("Enter length of first string : ");
    scanf("%d",&n);
    printf("Enter length of second string : ");
    scanf("%d",&m);
    char a[n],b[m];
    printf("Enter first string : ");
    scanf("%s",a);
    printf("Enter second string : ");
    scanf("%s",b);

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
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    printf("Minimum %d deletions and %d insertions are required.\n",n-dp[n][m],m-dp[n][m]);
    return 0;
}