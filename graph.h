#ifndef _GRAPH_HEADER_
#define _GRAPH_HEADER_

enum{
    WHITE,
    GREY,
    BLACK
};

typedef struct vertex{
    int id;
    int color;
    int distance;
    int seq;
    struct vertex *parent;
}vertex_t;

typedef struct edge{
    int vertex;
    struct edge *next;
}edge_t;

typedef struct graph{
    int n_vertices;
    vertex_t *vertices;
    edge_t **adjacencyList;
}graph_t;

#endif

