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

struct Graph *createGraph(int vertices){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices=vertices;
    graph->adjacency=(struct node **)malloc(sizeof(struct node *)*(graph->vertices+1));
    for(int i=0;i<graph->vertices+1;i++)
    graph->adjacency[i]=NULL;
    return graph;
}

struct node* createNode(int vertex){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->vertex=vertex;
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

void DFS(struct Graph *graph,int *visited,int start){
    printf("%d ",start);
    struct node *temp=graph->adjacency[start];
    visited[start-1]=1;
    while(temp!=NULL){
        if(!visited[temp->vertex-1]){

            DFS(graph,visited,temp->vertex);
        }
        temp=temp->next;
    }
}

int main(){
    struct Graph *graph;
    int vertices,edges;
    printf("Enter number of vertices : ");
    scanf("%d",&vertices);

    graph=createGraph(vertices);

    printf("Enter number of edges : ");
    scanf("%d",&edges);

    for(int i=0;i<edges;i++){
        int u,v;
        printf("Enter starting and ending point of edge %d : ",i+1);
        scanf("%d %d",&u,&v);
        graph=addEdge(graph,u,v);
    }
    int start;
    printf("Enter the starting vertex : ");
    scanf("%d",&start);

    int *visited=calloc(vertices,sizeof(int));
    DFS(graph,visited,start);

    return 0;
}