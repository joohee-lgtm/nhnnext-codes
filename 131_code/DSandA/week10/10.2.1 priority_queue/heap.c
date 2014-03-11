//
//  heap.c
//  10.2.1 priority_queue
//
//  Created by KIMJOOHWEE on 13. 5. 27..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include "heap.h"
/*
 
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

*/

void init() {numData=0;}

void HInsertElement(HElem el)
{
	numData++;
	int idx = numData;
	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while( (idx != 1) &&
          (el.prio > heapArr[idx/2].prio) ) {
		heapArr[idx] = heapArr[idx/2];
		idx = idx/2;
	}
	heapArr[idx] = el; //새로운 노드를 삽입
}

void HInsertData(Priority prio, HData data)
{
	HElem el = {prio, data};
	HInsertElement(el);
}

HData HDelete()
{
    
	HElem ret, temp;
	ret = heapArr[1]; //root
	temp = heapArr[numData];//last leaf node
	numData--;
	int parent = 1;
	int child = 2;
	while( child <= numData ) {
		//서브 트리 중 선택
		if( ( child < numData ) &&
           (heapArr[child].prio) < heapArr[child+1].prio)
			child++;
		if( temp.prio >= heapArr[child].prio ) break;
		// 한단계 아래로 이동
		heapArr[parent] = heapArr[child];
		parent = child;
		child *= 2;
	}
    
	heapArr[parent] = temp;
	return ret.data;
}

int isHEmpty() {return (numData==0);}