#include <stdio.h>
#include "bin_tree.h"
#include "bt_trav.h"
#include "dstack.h"

void visit(TreePointer p)
{
	printf("%d\n",p->data);
}

//LVR non-recursive version
void inorder(TreePointer p)
{
	printf("%s\n",__func__);

	//1. init stack, read dstack.h
	dstack_t * sta;
    sta = init();
	TreePointer curr;
    curr = p;

	while(1)
	{
		//2. find leftmost node,  all nodes in the path will be pushed
        while ( curr->left != NULL)
        {
            push(sta, curr);
            if (curr->left->left == NULL)
            {
                push(sta, curr->left);
                break;
            }
            curr = curr->left;
        }
        
		//3. if stack is empty quit func
        if (sta==NULL)
            break;

		//4. pop from stack and print it
        printf("%d",pop(sta)->data);
        printf("%d",pop(sta)->data);

		//5. change current node to right
        curr = curr->right;
	}
}

//option home work, if you have time, recommended to implement
void preorder(TreePointer p)
{

}

void postorder(TreePointer p)
{

}

