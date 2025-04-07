// floyd warshall algorithm
#include <stdio.h>
#include<limits.h>


int main() {
    printf("Directed Graph\nVertex starts from 0\n");
    int v,e;
    printf("Enter number of vertices : ");
    scanf("%d",&v);
    printf("Enter number of edges : ");
    scanf("%d",&e);
    
    int adjMatrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adjMatrix[i][j]=INT_MAX;
            if(i==j){
                adjMatrix[i][j]=0;
            }
        }
    }
    
    for(int i=0;i<e;i++){
        printf("Enter src des weight : ");
        int src,des,weight;
        scanf("%d %d %d",&src,&des,&weight);
        if (src >= 0 && src < v && des >= 0 && des < v) {
            adjMatrix[src][des] = weight; 
        } else {
            printf("Invalid edge input\n");
        }
    }
    
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(adjMatrix[i][k]!=INT_MAX && adjMatrix[k][j]!=INT_MAX){
                int    new_weight=adjMatrix[i][k] + adjMatrix[k][j];
                    if(new_weight<adjMatrix[i][j]){
                        adjMatrix[i][j]=new_weight;
                    }
                }
            }
        }
    }
    printf("Shortest path matrix:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adjMatrix[i][j]!=INT_MAX){
                printf("%d ", adjMatrix[i][j]);
            }else{
                printf("∞ ");
            }
        }
        printf("\n");
    }
    
    return 0;
}