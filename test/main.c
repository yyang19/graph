#include<stdlib.h>
#include<stdio.h>
#include "bfs.h"
#include "graph.h"

static edge_t *
add_edge( edge_t *list, int v ){

    edge_t *newHead = (edge_t *) malloc( sizeof(edge_t) );

    if( newHead ){
        newHead->vertex = v;
        newHead->next = list;
    }

    return newHead;
}

static void
destroy_list( edge_t *list ){
    edge_t *e = list;

    if(e){
        if( e->next )
            destroy_list(e->next);
        free(e);
    }

    return;
}

int main(){

    graph_t G;

    int n_edges;
    int vi, ei;
    int v_start, v_end;
    edge_t *e;

    printf("Enter the number of vertices \n");
    scanf( "%d", &G.n_vertices );
    
    printf("Enter the number of edges \n");
    scanf( "%d", &n_edges );

    G.vertices = (vertex_t *)malloc( sizeof(vertex_t) * (G.n_vertices+1) );
    
    //create adjacencyList
    G.adjacencyList = (edge_t **)malloc( sizeof(edge_t *) * (G.n_vertices+1) );

    for(vi=0; vi<=G.n_vertices; vi++){
        //populate vertices
        G.vertices[vi].id       = vi;
        //initialize adjacencyList
        G.adjacencyList[vi]=NULL;
    }

    for(ei=1; ei<=n_edges; ei++){
        printf("Enter start and end point for %d-th edge: start=", ei);
        scanf( "%d", &v_start );
        printf( "end=" );
        scanf( "%d", &v_end );
        G.adjacencyList[v_start] = add_edge( G.adjacencyList[v_start], v_end );
        //remove the following line if you want a directed graph
        G.adjacencyList[v_end] = add_edge( G.adjacencyList[v_end], v_start );
    }

    //Print adjacencyList
    for(vi=0; vi<=G.n_vertices; vi++){
        printf("Adjacency List of vertex %d: ", vi);
        e = G.adjacencyList[vi];
        while(e){
            printf("%d->", e->vertex);
            e=e->next;
        };
        printf("NULL\n");
    }


    BFS( &G, 1, 1);
    BFS( &G, 2, 1);
    BFS( &G, 3, 1);
    BFS( &G, 4, 1);

    for(vi=0; vi<=G.n_vertices; vi++){
        destroy_list(G.adjacencyList[vi]);
        printf("Adjacency List of vertex %d destroyed\n", vi);
    }

    free( G.adjacencyList );
    free( G.vertices );

    return 0;
}
