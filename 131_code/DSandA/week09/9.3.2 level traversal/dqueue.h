#ifndef DQUEUE_H_
#define DQUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include "bin_tree.h"

typedef TreePointer qelement;

//dynamic queue 구조체 
typedef struct {
	qelement *qlist;
	int front;
	int rear;
	int capa;
} dqueue_t;

dqueue_t *init();
int is_empty( dqueue_t *q);
int is_full( dqueue_t *q);
void enqueue( dqueue_t *q, qelement item);
qelement dequeue( dqueue_t *q);
#endif
