#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct Graph {
    int vertices;
    struct node **adjacency;
};

struct Graph *createGraph(struct Graph *graph,int vertices){
    graph->vertices=vertices;
    graph->adjacency=(struct node **)malloc(sizeof(struct node*)*(graph->vertices+1));
    for(int i=0;i<graph->vertices+1;i++)
    graph->adjacency[i]=NULL;
    return graph;
}

struct node *createNode(int vertex){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=vertex;
    newnode->next=NULL;
    return newnode;
}

struct Graph *addEdge(struct Graph *graph,int src,int des){
    struct node *newnode=createNode(des);
    newnode->next=graph->adjacency[src];
    graph->adjacency[src]=newnode;

    newnode=createNode(src);
    newnode->next=graph->adjacency[des];
    graph->adjacency[des]=newnode;
    
    return graph;
}

void BFS(struct Graph *graph,int start){
    int *visited=(int*)calloc(graph->vertices,sizeof(int*));

    int queue[100];
    int front=0,rear=0;
    
    visited[start-1]=1;
    queue[rear++]=start;
    
    printf("BFS is : ");
    printf("%d ",start);
    while(front<rear){
        struct node *temp=graph->adjacency[queue[front++]];
        
        while(temp){
            if(!visited[temp->vertex-1]){
                visited[temp->vertex-1]=1;
                printf("%d ",temp->vertex);
                queue[rear++]=temp->vertex;
            }
            temp=temp->next;
        }
    }
    printf("\n");
}

int main(){
    struct Graph *graph;
    int vertices,edges;
    printf("Enter number of vertices of graph : ");
    scanf("%d",&vertices);
    printf("Enter number of edges of graph : ");
    scanf("%d",&edges);
    
    graph=createGraph(graph,vertices);
    
    for(int i=0;i<edges;i++){
        int u,v;
        printf("Edge no. %d u v : ",i+1);
        scanf("%d %d",&u,&v);
        graph=addEdge(graph,u,v);
    }
    
    int start;
    printf("Enter starting vertex for BFS : ");
    scanf("%d",&start);
    BFS(graph,start);

    return 0;
}