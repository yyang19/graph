#include<stdlib.h>
#include<stdio.h>

typedef struct edge{
    int vertex;
    struct edge *next;
}edge_t;

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

    int n_vertices, n_edges;
    int vi, ei;
    int v_start, v_end;
    edge_t *e;

    printf("Enter the number of vertices \n");
    scanf( "%d", &n_vertices );
    
    printf("Enter the number of edges \n");
    scanf( "%d", &n_edges );

    //create adjacencyList
    edge_t **adjacencyList = (edge_t **)malloc( sizeof(edge_t *) * (n_vertices+1) );

    //initialize adjacencyList
    for(vi=0; vi<=n_vertices; vi++)
        adjacencyList[vi]=NULL;

    for(ei=1; ei<=n_edges; ei++){
        printf("Enter start and end point for %d-th edge: start=", ei);
        scanf( "%d", &v_start );
        printf( "end=" );
        scanf( "%d", &v_end );
        adjacencyList[v_start] = add_edge( adjacencyList[v_start], v_end );
        //remove the following line if you want a directed graph
        adjacencyList[v_end] = add_edge( adjacencyList[v_end], v_start );
    }

    //Print adjacencyList
    for(vi=0; vi<=n_vertices; vi++){
        printf("Adjacency List of vertex %d: ", vi);
        e = adjacencyList[vi];
        while(e){
            printf("%d->", e->vertex);
            e=e->next;
        };
        printf("NULL\n");
    }

    for(vi=0; vi<=n_vertices; vi++){
        destroy_list(adjacencyList[vi]);
        printf("Adjacency List of vertex %d destroyed\n", vi);
    }

    free( adjacencyList );

    return 0;
}
