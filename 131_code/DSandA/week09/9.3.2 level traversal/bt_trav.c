#include <stdio.h>
#include "bin_tree.h"
#include "bt_trav.h"
#include "dqueue.h"

/*
 typedef int element;
 typedef struct _node* TreePointer;
 typedef struct _node
 {
 element data;
 TreePointer left, right;
 } BTNode;
 
 typedef struct {
 qelement *qlist;
 int front;
 int rear;
 int capa;
 } dqueue_t;
*/

void visit(TreePointer p)
{
	printf("%d\n",p->data);
}

void levelorder(TreePointer p)
{
	//1.init q
	dqueue_t * que;
    que = init();
	TreePointer curr;
    curr = p;
	
	//2.euqueue current
    enqueue(que, curr);

	while(1)
	{
		curr = dequeue(que);
        //dequeue and check whether it's NULL
		//if NULL, exit loop
        if (que == NULL)
            break;
        //visit current
        printf("%d",curr->data);
		//enqueue left and child if they are not NULL
        enqueue(que,curr->left);
        enqueue(que,curr->right);
	}
}
