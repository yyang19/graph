#include<stdlib.h>
#include<stdio.h>
#include "graph.h"

static int dfs_visited = 0;

static void
_dump( vertex_t *t ){
    printf("Vertex ID=%d, seq=%d\n", t->id, t->seq);    
}

static void
_dfs_visit( graph_t *g, int vi, int print ){

   if( g->vertices[vi].color != WHITE )
      return;

   edge_t *e = g->adjacencyList[vi];
   vertex_t *v = &g->vertices[vi];
   int neighbour;

   v->color = GREY;

   while(e){
      neighbour = e->vertex;
      if( g->vertices[neighbour].color == WHITE ){
         g->vertices[neighbour].parent = v;
         _dfs_visit( g, neighbour, print );         
      }
      e = e->next;
   };

   v->color = BLACK;
   v->seq = ++ dfs_visited;
   _dump(v);
}

void
DFS( graph_t *g, int start, int print )
{
    if( !g )
        return;
   
    if( start<1 || start>g->n_vertices )
       return;

    int vi;

    printf( "\t\t---DFS starting from vertex %d---\n", start );

    for( vi=0; vi<=g->n_vertices; vi++ ){
      g->vertices[vi].color = WHITE;
      g->vertices[vi].parent = NULL;
      g->vertices[vi].seq = -1;
    }

    dfs_visited = 0;

    _dfs_visit( g, start, print);

    return;
}
