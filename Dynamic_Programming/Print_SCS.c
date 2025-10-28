// Print_Shortest_Common_Supersequence
#include<stdio.h>
#include<string.h>

int main(){
    char str1[100]; 
    char str2[100];
    printf("Max length of string is 100\n");
    printf("Enter first string : ");
    scanf("%s", str1); 

    printf("Enter second string : ");
    scanf("%s", str2); 

    int n = strlen(str1);
    int m = strlen(str2);

    int dp[n+1][m+1];
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = 0;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }

    char ans[m+n]; 
    int index = 0;
    int i = n , j = m;

    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            ans[index++] = str1[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans[index++] = str1[i-1];
                i--;
            }else{
                ans[index++] = str2[j-1];
                j--;
            }
        }
    }

    while (i > 0) ans[index++] = str1[--i];
    while (j > 0) ans[index++] = str2[--j];

    printf("Shortest common supersequence is : ");
    while(index-- > 0){
        printf("%c",ans[index]);
    }
    printf("\n");
    return 0;
}