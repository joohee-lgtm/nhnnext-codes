//
//  Header.h
//  10.1.2 dlist_stack
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#ifndef list_h
#define list_h
#include <stdio.h>

//adt of list
//typedef long Element;
typedef long Element; //for storing name

typedef struct _Node {
	Element data;
	struct _Node *prev;
	struct _Node *next;
} Node;

typedef Node* NodePtr;

//create empty head Node
NodePtr initHead();
int isEmpty(NodePtr head);
int size(NodePtr head);
int search(NodePtr head, Element value);
void addFirst(NodePtr head, Element new_data);
Element get(NodePtr head, int index);
Element getFirst(NodePtr head);
Element getLast(NodePtr head);
Element removeNode(NodePtr head, int index); //index 위치의 값을 리턴하고 노드는 제거
Element removeFirst(NodePtr head);
Element removeLast(NodePtr head);
void replace(NodePtr head, int index, Element data);
void shuffle(NodePtr head);
void display(NodePtr head);
void rerverse_display(NodePtr head);

#endif
