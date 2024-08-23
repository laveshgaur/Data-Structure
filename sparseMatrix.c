#include<stdio.h>
int sparseMatrix(int r,int c,int arr[r][c]);
void printMatrix(int r,int c,int arr[r][c]);
int main(){
	int r,c;
    printf("Enter row & column : ");
	scanf("%d%d",&r,&c);
	int arr[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int sparseTest=sparseMatrix(r,c,arr);
	if (sparseTest==1){
		printf("Your matrix is sparse matrix\n");
		printMatrix(r,c,arr);
	}
	else{
		printf("Your matrix is not sparse matrix\n");
	}
}
int sparseMatrix(int r,int c,int arr[r][c]){
	int zero=0;
    int nonzore=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==0){
				zero++;
			}
			else{
				nonzore;
			}
		}
	}
	if(zero>nonzore){
		return 1;
	}
	else{
		return 0;
	}
}
void printMatrix(int r,int c,int arr[r][c]){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if (arr[i][j]!=0){
				printf("%d %d %d\n",i,j,arr[i][j]);
			}
		}
	}
}