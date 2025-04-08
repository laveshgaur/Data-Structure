//Dijkstra's Algorithm

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void Dijkstra(int v,int adjMatrix[][v],int weight[]){
    int *visited=calloc(v,sizeof(int));
    weight[0]=0;
    for(int i=0;i<v;i++){
        int next_node=-1,min_weight=INT_MAX;
        for(int j=0;j<v;j++){
            if(!visited[j] && min_weight>weight[j]){
                next_node=j;
                min_weight=weight[j];
            }
        }
        if(next_node == -1) break;
        visited[next_node] = 1;

        for(int j=0;j<v;j++){
            if(!visited[j] && adjMatrix[next_node][j]!=INT_MAX){
                int new_weight = weight[next_node] + adjMatrix[next_node][j];
                if(new_weight < weight[j]) {
                    weight[j] = new_weight;
                }
            }
        }
        
    }
}
int main(){
    printf("Dijkstra's Algorithm\nVertex start from 0\n\n");
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
        int src,des,weight;
        printf("Enter src des weight : ");
        scanf("%d %d %d",&src,&des,&weight);
        adjMatrix[src][des]=weight;
    }
    int weight[v];
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
    }
    Dijkstra(v,adjMatrix,weight);
    printf("\nShortest distance\n\n");
    for(int i=0;i<v;i++){
        printf("0-------%d = %d\n",i,weight[i]);
    }

    return 0;
}