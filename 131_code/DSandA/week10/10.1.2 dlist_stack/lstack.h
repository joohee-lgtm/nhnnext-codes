//
//  lstack.h
//  10.1.2 dlist_stack
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#ifndef LSTACK_H
#define LSTACK_H

#include "list.h"
typedef struct _lstack
{
	int count;
	NodePtr head;
} LStack;

LStack* CreateStack();
void Push(LStack *s, Element e);
Element Pop(LStack *s);
int IsStackEmpty(LStack *s);
int StackCount(LStack* s);
#endif

