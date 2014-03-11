//
//  heap.h
//  10.2.1 priority_queue
//
//  Created by KIMJOOHWEE on 13. 5. 27..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#ifndef HEAP_H_
#define HEAP_H_

#define LEN (1<<7)

typedef char HData;
typedef int Priority;
typedef struct _hElem
{
	Priority prio;
	HData data;
} HElem;

//global variables
int numData;
HElem heapArr[LEN];

int isHEmpty();
void init();
void HInsertData(Priority prio, HData data);
void HInsertElement(HElem el);
HData HDelete();

#endif
