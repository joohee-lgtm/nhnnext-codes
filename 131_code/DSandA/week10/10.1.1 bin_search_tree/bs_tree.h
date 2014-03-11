//
//  bs_tree.h
//  10.1.1 bin_search_tree
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#ifndef BS_TREE_H_
#define BS_TREE_H_
#include "bin_tree.h"
#include "bt_trav.h"

TreePointer createBST(element data);
TreePointer BSTsearch(TreePointer bst, element data);
void insert(TreePointer bst, element data);
void printSorted(TreePointer bst);
element GetBSTData(TreePointer bst);
#endif