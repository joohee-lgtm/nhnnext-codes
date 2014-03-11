//
//  main.c
//  bintree9_1
//
//  Created by KIMJOOHWEE on 13. 5. 22..
//  Copyright (c) 2013년 KIMJOOHWEE. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _treeNode {
	int data;
	struct _treeNode *left, *right;
} TreeNode;

//데이터를 방문(출력)
void visit(TreeNode *node)
{
	printf("%d\n",node->data);
}
// 중위 순회
void inorder( TreeNode *root ){
	//printf("%s\n",__func__);
	if ( root ){
		inorder( root->left );	// 왼쪽서브트리 순회
		visit(root); 	// 노드 방문
		inorder( root->right );	// 오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder( TreeNode *root ){
	//printf("%s\n",__func__);
    if (root)
    {
        visit(root);
        preorder(root->left);
        preorder(root->right);
    }
}
// 후위 순회
void postorder( TreeNode *root ){
	//printf("%s\n",__func__);
	if (root)
    {
        postorder(root->left);
        postorder(root->right);
        visit(root);
    }
}

int main()
{
	//       V
	//		 15
	//	 4		 20
	// 1      16    25
	TreeNode n1={1, NULL, NULL};
	TreeNode n2={4, &n1, NULL};
	TreeNode n3={16, NULL, NULL};
	TreeNode n4={25, NULL, NULL};
	TreeNode n5={20, &n3, &n4};
	TreeNode n6={15, &n2, &n5};
	TreeNode *root= &n6;
    
    printf("중위순회\n");
	inorder(root);
    printf("전위순회\n");
	preorder(root);
    printf("후위순회\n");
	postorder(root);
	return 0;
}
