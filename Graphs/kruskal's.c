#include<stdio.h>
#include<stdio.h>

struct node{
    int vertex;
    int weight;
    struct node *next;
};

struct Graph{
    int vertices;
    struct node **adjacency;
};