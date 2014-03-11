//
//  main.c
//  circular_double_nexted_list
//
//  Created by KIMJOOHWEE on 13. 5. 18..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#include <stdio.h>

typedef long element;
struct node{
    element data;
    struct node * prev;
    struct node * next;
};

typedef struct node* node_ptr;

struct node * initHead();
int isEmpty(struct node * head);
void addFirst(struct node * head, long new_data);
void addLast(struct node * heand, long new_data);
element getFirst(struct node * head);
element getLast(struct node * head);
element get(struct node * head, int index);
element removeNode(node_ptr head, int index);// index 위치의 값을 리턴하고 노드는 제거
element removeFirst(struct node * head);
element removeLast(struct node * head);



int main()
{
    return 0;
};

// 유민 질문하기!
int isEmpty(struct node * head)
{
    return 0;
}

void addFirst(struct node * head, long new_data)
{
    node_ptr add_first_node =  (node_ptr)malloc(sizeof(struct node));
    add_first_node -> prev = head;
    add_first_node -> data = new_data;
    add_first_node -> next = head -> next;
};


void addLast(struct node * head, long new_data)
{
    node_ptr p;
    node_ptr add_last_node =  (node_ptr)malloc(sizeof(struct node));
    p = head->next;
    while ( p->next != NULL )
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        p->next = add_last_node;
        add_last_node -> data = new_data;
        add_last_node -> prev = p;
        add_last_node -> next = NULL;
    }
};

element getFirst(struct node * head)
{
	return get(head,0);
};

element getLast(struct node * head)
{
    node_ptr search_p = head->next;
    while(search_p->next != NULL)
    {
        search_p = search_p -> next;
    }
    return search_p -> data;
};

element get(struct node * head, int index)
{
    //node_ptr np = head->next;
	node_ptr np = head -> next;
	int check;
    for (check = 0; check<index ; check++)
    {
        np = np -> next;
    }
	return np->data;
};

element removeNode(node_ptr head, int index)// index 위치의 값을 리턴하고 노드는 제거
{
    node_ptr np = head -> next;
	int check;
    for (check = 0; check<index ; check++)
    {
        np = np -> next;
    }
    
    node_ptr removed = np;
    node_ptr before = removed -> prev;
    node_ptr after = removed -> next;
    
    before -> next = after;
    after -> prev = before;
    
    element removed_data = removed -> data;
    
    free(removed);
    return removed_data;
};

element removeFirst(struct node * head)
{
    return removeNode(head,0);
};

element removeLast(struct node * head)
{
    element removed_data;
    node_ptr find_last = head->next;
    while (find_last->next != NULL)
    {
        find_last = find_last->next;
    }
    removed_data = find_last -> data;
    find_last -> prev -> next = NULL;
    free(find_last);

    return removed_data;
};








