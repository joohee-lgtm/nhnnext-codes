//
//  list.c
//  10.1.2 dlist_stack
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/**
 @brief initHead()
 create head node and return it
 to avoid implementing double pointer, head node will be never used
 NodePtr initHead()
 @return pointer of head_node
 */
NodePtr initHead()
{
	NodePtr head = (NodePtr) malloc(sizeof(NodePtr));
	head->next =  head->prev = head;
	return head;
}

int isEmpty(NodePtr head)
{
	return (head->next == head);
}

/**
 @brief get size of list
 @return size fo list
 */
int size(NodePtr head)
{
	NodePtr cur = head;
	int len=0;
	while(1)
	{
		cur= cur-> next;
		if(cur!=head)
			len++;
		else
			break;
	}
	//printf("%d\n",len);
	return len;
}

/**
 @brief check whether the value is in list
 @return position of the value, if not fount return -1
 */
int search(NodePtr head, Element value)
{
	int n=0;
	NodePtr cur = head->next;
	while(cur!= head)
	{
		//if(strcmp(cur->data,value))
		if(cur->data == value)
			return n;
		cur = cur -> next;
		n++;
	}
	return -1;
}
/**
 @brief
 @return
 */
void addFirst(NodePtr head, Element new_data)
{
	NodePtr nn= (NodePtr) malloc (sizeof(Node));
	NodePtr after = head->next;
    
	//set value
	nn->data = new_data;
    
	//set newnode link
	nn-> next = after;
	nn-> prev = head;
    
	//set other link
	head-> next = nn;
	after -> prev = nn;
}
//interally used for get() and remove()
NodePtr _get(NodePtr head, int index)
{
	int i;
	NodePtr cur = head;
    
	for(i=0; i <= index; i++)
	{
		cur= cur-> next;
		if(cur==head)
		{
			cur = NULL;
			break;
		}
	}
	return cur;
}
//internallly used, and for performance
NodePtr _rget(NodePtr head, int rindex)
{
	int i;
	NodePtr cur = head;
	for (i=0 ; i <= rindex ; i++) {
		cur = cur->prev;
		if (cur == head) {
			cur = NULL;
			break;
		}
	}
	return cur;
}

Element get(NodePtr head, int index)
{
	NodePtr np = _get(head,index);
	return np->data;
}
Element getFirst(NodePtr head)
{
	return get(head,0);
}

Element getLast(NodePtr head)
{
	NodePtr np = _rget(head,0);
	return np->data;
}

Element removeNode(NodePtr head, int index)
{
	NodePtr target = _get(head,index);
	NodePtr before = target->prev;
	NodePtr after = target->next;
    
	//get data of target
	Element data = target->data;
    
	//fix link
	before->next = after;
	after->prev = before;
    
	//free target
	free(target);
	return data;
}

Element removeFirst(NodePtr head)
{
	return removeNode(head,0);
}

Element removeLast(NodePtr head)
{
	NodePtr target = _rget(head,0);
	NodePtr before = target->prev;
	NodePtr after = target->next;
    
	Element data = target->data;
    
	before->next =after;
	after->prev = before;
    
	free(target);
	return data;
}

void replace(NodePtr head, int index, Element data)
{
	NodePtr target = _get(head,index);
	target->data = data;
}

void shuffle(NodePtr head)
{
	int n = size(head);
	int i, idx;
	NodePtr cur;
    cur = head->next;
	Element src, dest;
    
	srand((unsigned)time(NULL));
    
	for(i=n-1; i > 0 ; i--)
	{
		src = get(head,i);
		idx = rand()%i;
		dest = get(head, idx);
		replace(head,i,dest);
		replace(head,idx,src);
	}
}


void display(NodePtr head)
{
	NodePtr cur = head->next;
	for(;cur!=head;cur=cur->next)
		printf("%ld ",cur->data);
	printf("\n");
}

void reverse_display(NodePtr head)
{
	NodePtr cur = head->prev;
	for(;cur!=head;cur=cur->prev)
		printf("%ld ",cur->data);
	printf("\n");
}