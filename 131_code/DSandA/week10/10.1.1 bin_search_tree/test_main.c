//
//  test_main.c
//  10.1.1 bin_search_tree
//
//  Created by KIMJOOHWEE on 13. 5. 26..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//
#include <stdio.h>
#include "bs_tree.h"
#include <assert.h>

#define arr_length(arr,type) ((sizeof(arr)/sizeof(type)))

//binary search tree test
//insert 10, 3, 5, 2, 9 , 100

int main()
{
	int arr[] = {10,3,5,2,9,100};
	int i, len, key;
	TreePointer bst, ret;
	
	len = arr_length(arr,int);
    
	//create tree using ADT
	bst = createBST(arr[0]);
	for(i=1; i <  len ; i ++)
		insert(bst,arr[i]);
    
	
	key = 2;
	ret = BSTsearch(bst,key);
	assert(ret!=NULL);
	assert(key==getBSTData(ret));
    
	//print all by order
	printSorted(bst);
    
	return 0;
}