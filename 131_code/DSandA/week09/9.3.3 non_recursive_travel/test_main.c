#include <stdio.h>
#include "bin_tree.h"
#include "bt_trav.h"

/*
//binary tree test
       8
      / \
    10   15
   /    /  \
  3    5    9
*/

int main()
{
	//create tree using ADT
	TreePointer temp;
	TreePointer root = createBT(3);
	root = makeBT(root,10,NULL);
	root = makeBT(root,8,NULL);
	addRight(root,15);
	temp = rightBT(root);
	addLeft(temp,5);
	addRight(temp,9);

	//printf all tree
	printf("      8      \n");
	printf("     / \\     \n");
	printf("   10   15   \n");
	printf("  /    /  \\  \n");
	printf(" 3    5    9 \n");
	printf("\n");


	//traversal 
	inorder(root);
	//preorder(root);
	//postorder(root);

	return 0;
}
