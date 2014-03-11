//
//  bs_tree.c
//  10.1.1 bin_search_tree
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include <stdio.h>
#include "bs_tree.h"

/*
 
 typedef int element;
 
 typedef struct _node* TreePointer;
 
 typedef struct _node
 {
 element data;
 TreePointer left, right;
 } BTNode;
 
*/

TreePointer createBST(element data)
{
	return createBT(data);
}

TreePointer BSTsearch(TreePointer bst, element data)
{
	TreePointer ret=NULL;
	//implement
    if (bst->data == data)
    {
        ret = bst;
    }
    else if( bst->data < data)
    {
        if (bst->left == NULL)
            ret = bst;
        else
            ret = bst -> left;
            BSTsearch(ret,data);
    }
    else if( bst->data > data)
    {
        if (bst->right == NULL)
            ret = bst;
        else
            ret = bst -> right;
            BSTsearch(ret,data);
    }
	return ret;
}

void insert(TreePointer bst, element data)
{
    TreePointer searched = BSTsearch(bst,data);
    if (searched->data != data)
    {
        if (searched->data > data)
        {
            addLeft(searched, data);
        }
        else if (searched->data < data)
        {
            addRight(searched, data);
        }
    }
}

void printSorted(TreePointer bst)
{
	printf("%d", getBSTData(bst));
}

element getBSTData(TreePointer bst)
{
	return bst->data;
}