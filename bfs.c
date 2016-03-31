#include<stdlib.h>
#include<stdio.h>
#include "graph.h"
#include "fifo.h"

static void
_dump( vertex_t *t ){
    printf("Vertex ID=%d, distance=%d\n", t->id, t->distance);    
}

void
BFS( graph_t *g, int start, int print )
{
    if( !g )
        return;

    if( start <= 0 || start>g->n_vertices )
        return;

    edge_t *e;
    vertex_t *v, *neighbour;
    fifo_t *queue = fifo_new();
    int vi;

    printf( "\t\t---BFS starting from vertex %d---\n", start );

    for(vi=0; vi<=g->n_vertices; vi++){
        // initialize vertex state
        g->vertices[vi].color    = WHITE;
        g->vertices[vi].distance = -1;
        g->vertices[vi].parent   = NULL;
    }

    //update state for the starting vertex
    g->vertices[start].color    = GREY;
    g->vertices[start].distance = 0;
    g->vertices[start].parent   = NULL;
    
    // start BFS
    fifo_in( queue, (void *)&start );

    while( !fifo_empty(queue) ){

        int vi = *(int *)fifo_out(queue);
        v = &g->vertices[ vi ];
        
        e = g->adjacencyList[v->id];
        while( e ){
            neighbour = &g->vertices[e->vertex];
            if( neighbour->color == WHITE ){
                neighbour->color = GREY;
                neighbour->parent = v;
                neighbour->distance = v->distance+1;
                fifo_in( queue, (void *)&neighbour->id );
            }
            e = e->next;
        }
        
        v->color = BLACK;
        if( print )
            _dump(v);
    };   

    fifo_free(queue);
}
