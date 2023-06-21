/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;


int sumNumber(TreeNode* root) {

	if (root == NULL)
		return 0;

	else
	{
		int count = root->data;
		count = count + sumNumber(root->left) + sumNumber(root->right);
		return count;
	}
}

int main(void)
{
	
	printf("노드의 합 = %d", sumNumber(root));

	return 0;
}
*/
