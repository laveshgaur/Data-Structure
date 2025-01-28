#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct Graph{
    struct node **adjacency;
};

struct Graph *createGraph(struct Graph *graph,int vertices){
    graph->adjacency=(struct node**)malloc((vertices+1)*sizeof(struct node*));
    for(int i=0;i<vertices+1;i++){
        graph->adjacency[i]=NULL;
    }
    return graph;
}
struct node *createNode(int point){
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->vertex=point;
    newnode->next=NULL;
    return newnode; 
}

struct Graph *addEdge(struct Graph *graph,int src,int des){
    //for link src to des
    struct node *newnode=createNode(des);
    newnode->next=graph->adjacency[src];
    graph->adjacency[src]=newnode;
    // for link des to src
    newnode=createNode(src);
    newnode->next=graph->adjacency[des];
    graph->adjacency[des]=newnode;
    return graph;    
}

void printGraph(struct Graph *graph,int vertices){
    for(int i=1;i<vertices+1;i++){
        printf("Vertex %d is connected to : ",i);
        struct node *temp=graph->adjacency[i];
        while(temp!=NULL){
            printf("%d ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main(){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    int vertices;
    printf("Enter number of vertices : ");
    scanf("%d",&vertices);
    printf("Enter number of edges : ");
    int edges;
    scanf("%d",&edges);
    graph=createGraph(graph,vertices);
    for(int i=0;i<edges;i++){
        int u,v;// u = source ; v = destination of edges
        printf("Enter edges (u,v) : ");
        scanf("%d %d",&u,&v);
        graph=addEdge(graph,u,v);
    }
    printf("\n");
    printGraph(graph,vertices);
    printf("\nGraph created successfully!\n\n");
    return 0;
}