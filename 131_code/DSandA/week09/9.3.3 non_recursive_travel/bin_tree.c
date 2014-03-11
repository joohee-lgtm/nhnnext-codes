#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bin_tree.h"

#define EMPTY INT_MIN //use INT_MIN for empty node

TreePointer createBT(element data)
{
	TreePointer root = (TreePointer) malloc(sizeof(BTNode));
	if(root)
	{
		root->left = root->right = NULL;
		setData(root,data);
	}
	return root;
}

int isEmpty(TreePointer root)
{
	return (!root->left && !root->right && (root->data == EMPTY));
}
TreePointer makeBT(TreePointer left_tree, element item, TreePointer right_tree)
{
	TreePointer new_root = (TreePointer) malloc(sizeof(BTNode));
	if(new_root)
	{
		new_root->data = item;
		new_root->left = left_tree;
		new_root->right = right_tree;
	}
	return new_root;
}
TreePointer leftBT(TreePointer bt)
{
	return bt->left;
}
TreePointer rightBT(TreePointer bt)
{
	return bt->right;
}
element getData(TreePointer root)
{
	return root->data;

}
element setData(TreePointer node, element data)
{
	node->data = data;
}

int addLeft(TreePointer root, element litem)
{
	TreePointer new_node = createBT(litem);
	if(new_node)
	{
		root->left = new_node;
		return 1;
	}
	return -1;
}

int addRight(TreePointer root, element ritem)
{
	TreePointer new_node = createBT(ritem);
	if(new_node)
	{
		root->right = new_node;
		return 1;
	}
	return -1;
}
