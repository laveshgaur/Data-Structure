//Using recursion
#include<stdio.h>

int max(int a,int b){
    return a > b ? a : b ;
}

int LCS(char *str1,int n,char *str2,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(str1[n-1]==str2[m-1]){
        return LCS(str1,n-1,str2,m-1)+1;
    }else{
        return max(LCS(str1,n-1,str2,m),LCS(str1,n,str2,m-1));
    }
}

int main(){
    char str1[100],str2[100];
    int len1,len2;
    printf("Max length is 100\n");
    printf("Enter length of string 1 : ");
    scanf("%d",&len1);
    printf("Enter length of string 2 : ");    
    scanf("%d",&len2);
    getchar();
    if(len1<=100 && len2<=100 && len1>=0 && len2>=0){
        printf("Enter string 1 : ");
        for(int i=0;i<len1;i++){
            scanf("%c",&str1[i]);
        }
        printf("Enter string 2 : ");
        for(int i=0;i<len2;i++){
            scanf("%c",&str2[i]);
        }
        printf("Length of longest common subsequence is %d \n",LCS(str1,len1,str2,len2));
    }else{
        printf("Invalid length\n");
    }

    return 0;
}