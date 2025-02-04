#include<stdio.h>
#include<stdlib.h>

struct node {
    int vertex;
    int cost;
    struct node *next;
};

struct Graph{
    int vertices;
    struct node **adjacency;
};

struct Graph *createGraph(int vertices){
    struct Graph *graph=(struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices=vertices;
    graph->adjacency=(struct node **)malloc(sizeof(struct node*)*(vertices+1));
    for(int i=0;i<vertices+1;i++)
    graph->adjacency[i]=NULL;
    return graph;
}

struct node *createNode(int vertex,int weight){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=vertex;
    newnode->cost=weight;
    newnode->next=NULL;
    return newnode;
}

struct Graph *addEdge(struct Graph *graph,int src,int des,int weight){
    struct node *newnode=createNode(des,weight);
    newnode->next=graph->adjacency[src];
    graph->adjacency[src]=newnode;

    newnode=createNode(src,weight);
    newnode->next=graph->adjacency[des];
    graph->adjacency[des]=newnode;

    return graph;
}

void primsMST(struct Graph *graph){
     
}

int main(){
    struct Graph *graph;
    int vertices,edges;
    printf("Enter number of vertices of graph : ");
    scanf("%d",&vertices);
    printf("Enter number of edges of graph : ");
    scanf("%d",&edges);
    
    graph=createGraph(vertices);

    for(int i=0;i<edges;i++){
        int u,v,weight;
        printf("Enter source destination and weight of %d edge : ",i+1);
        scanf("%d %d %d",&u,&v,&weight);
        graph=addEdge(graph,u,v,weight);
    }


    return 0;
}