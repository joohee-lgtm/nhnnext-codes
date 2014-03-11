//
//  bt_trav.c
//  10.1.1 bin_search_tree
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include <stdio.h>
#include "bin_tree.h"
#include "bt_trav.h"

void visit(TreePointer p)
{
	printf("%d\n",p->data);
}

//LVR
void inorder(TreePointer p)
{
	if(p)
	{
		inorder(p->left);
		visit(p);
		inorder(p->right);
	}
}

//VLR
void preorder(TreePointer p)
{
	if(p)
	{
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}
//LRV
void postorder(TreePointer p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		visit(p);
	}
}
