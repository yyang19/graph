#include<stdlib.h>
#include "fifo.h"

fifo_t *
fifo_new(void)
{
    fifo_t *f = (fifo_t *)malloc(sizeof(fifo_t));
    return f;
}

int
fifo_empty(fifo_t *f)
{
    return (f->head == NULL);
}

void
fifo_in( fifo_t *f, void *data ){
    
    fifonode_t *n = (fifonode_t*) malloc ( sizeof(fifonode_t) );

    if(!n)
        return;
    
    n->data = data;
    n->next = NULL;

    if( f->tail == NULL )
        f->head = f->tail = n;
    else{
        f->tail->next = n;
        f->tail = n;
    }
    return;
}

void *
fifo_out( fifo_t *f ){
    
    if( !f )
        return NULL;

    if( !f->head )
        return NULL;

    fifonode_t *n = f->head;
    void *data = n->data;

    if( (f->head = n->next) == NULL )
        f->tail = NULL;

    free(n);

    return data;
}

void
fifo_free( fifo_t *f ){
    
    if(!f)
        return;

    fifonode_t *curr = f->head;
    fifonode_t *next;

    while(curr){
        next = curr->next;
        free(curr);
        curr = next;
    };
}
