#include <stdio.h>
#include <stdlib.h>
#include "bt_trav.h"

#define MAX (1<<10)
#define CUR 4
#define debug

//for tree traversal
typedef TreePointer selement;

//dynamic stack 구조체 
typedef struct {
	selement *stack;
	int top;
	int capa;
} dstack_t;

dstack_t *init();
int is_empty ( dstack_t *s);
int is_full( dstack_t *s);
void push( dstack_t *s, selement item);
void free_stack(dstack_t *s);
selement pop( dstack_t *s);
selement peek( dstack_t *s);
