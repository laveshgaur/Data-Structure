#include<stdio.h>
#include<stdlib.h>

void createGraph(int graph[6][6],int vertices,int edges){
    for(int i=1;i<edges+1;i++){
        int u,v;
        printf("Enter edge (u,v) : ");
        scanf("%d%d",&u,&v);
        graph[u][v]++;
        graph[v][u]++;
    }
}
void displayGraph(int graph[6][6]){
    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[6][6]={0};
    int edges;
    printf("Max vertices 5\nEnter number of edges : ");
    scanf("%d",&edges);
    createGraph(graph,6,edges);
    displayGraph(graph);
    return 0;
}