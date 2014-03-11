//
//  lstack.c
//  10.1.2 dlist_stack
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include <stdio.h>
#include "lstack.h"

/*
 
typedef struct _lstack
{
    int count;
    NodePtr head;
} LStack;


typedef struct _Node {
    Element data;
    struct _Node *prev;
    struct _Node *next;
 } Node;
 
 typedef Node* NodePtr;
*/


LStack* CreateStack()
{
    LStack * new_stack = (LStack)malloc(sizeof(_lstack));
    new_stack->count = -1;
    new_stack->head = initHead();
    new_stack->head->prev = NULL;
    new_stack->head->next = NULL;
    return new_stack;
}

void Push(LStack *s, Element e)
{
    NodePtr new_stack;
    
    NodePtr stack_check = s->head;
    
    while (stack_check->next != NULL)
        stack_check = stack_check->next;
    
    stack_check->next = new_stack;
    new_stack->prev = stack_check;
    new_stack->data = e;
    new_stack->next = NULL;
}

Element Pop(LStack *s)
{
    NodePtr poped_stack = s->head->next;
    s->head->next = poped_stack->next;
    poped_stack->next->prev = s->head;
    
    return poped_stack->data;
}

int IsStackEmpty(LStack *s)
{
    if (s->head->next == NULL)
        return -1;
}

int StackCount(LStack* s)
{
    NodePtr stack_check = s->head;
    int count = -1;
    
    while (stack_check->next != NULL)
    {
        count ++;
        stack_check = stack_check->next;
    }
    return count;
}