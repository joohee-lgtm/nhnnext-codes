//
//  test.c
//  10.2.1 priority_queue
//
//  Created by KIMJOOHWEE on 13. 5. 27..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#include <stdio.h>
#include "heap.h"
#include "heap.c"

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
 
 int isHEmpty();
 void init();
 void HInsertData(Priority prio, HData data);
 void HInsertElement(HElem el);
 HData HDelete();
*/

int main()
{
    HInsertData(0,0);
    HInsertData(1,20);
    HInsertData(2,40);
    HInsertData(3,10);
    HInsertData(4,60);
    HInsertData(5,5);
    
    while(isHEmpty())
    {
        printf("%d\n",HDelete());
    }
    
    return 0;
}