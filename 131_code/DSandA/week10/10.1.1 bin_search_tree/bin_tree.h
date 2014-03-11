//
//  bin_tree.h
//  10.1.1 bin_search_tree
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#ifndef BIN_TREE_
#define BIN_TREE_

//BinTree Object
typedef int element;
typedef struct _node* TreePointer;
typedef struct _node
{
	element data;
	TreePointer left, right;
} BTNode;

//BinTree adt funcitons
TreePointer createBT(element data);
int isEmpty(TreePointer root);
TreePointer makeBT(TreePointer left_tree, element item, TreePointer right_tree);
TreePointer leftBT(TreePointer bt);
TreePointer rightBT(TreePointer bt);
element getData(TreePointer root);
element setData(TreePointer node, element data);

//BinTree additional functions
int addLeft(TreePointer root, element litem);
int addRight(TreePointer root, element ritem);

#endif