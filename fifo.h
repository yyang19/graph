#ifndef _FIFO_HEADER_
#define _FIFO_HEADER_

typedef struct node{
    void *data;
    struct node *next;
}fifonode_t;

typedef struct fifo{
    fifonode_t *head;
    fifonode_t *tail;
}fifo_t;

fifo_t * fifo_new(void);
int fifo_empty(fifo_t *f);
void fifo_in( fifo_t *f, void *data );
void *fifo_out( fifo_t *f );
void fifo_free( fifo_t *f );
#endif
