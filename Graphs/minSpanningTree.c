#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node {
    int vertex;
    int weight;
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
    newnode->weight=weight;
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
int minKey(int *key,int *minSPT,int v){
    int min=-1;
    for(int i=0;i<v;i++){
        if((minSPT[i]==0) && (min==-1 || key[i]<key[min])){
            min=i;
        }
    }
    return min;
}

void primsMST(struct Graph *graph){
    int V=graph->vertices+1;
    int parent[V];
    int key[V];
    int minSPT[V];

    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        minSPT[i]=0;
    }
    key[1]=0;
    parent[1]=-1;
    
    for(int i=1;i<V-1;i++){
        int u=minKey(key,minSPT,V);
        minSPT[u]=1;
        struct node *temp=graph->adjacency[u];
        while(temp){
            int v=temp->vertex;
            int weight=temp->weight;
            if(minSPT[v]==0 && weight<key[v]){
                key[v]=weight;
                parent[v]=u;
            }
            temp=temp->next;
        }
    }
    int weight=0;
    for(int i=2;i<V;i++){
        printf("%d----%d   %d\n",parent[i],i,key[i]);
        weight+=key[i];
    }
    printf("Total weight = %d \n",weight);
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
    primsMST(graph);

    return 0;
}