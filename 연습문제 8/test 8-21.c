
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
//		  15
//	   4		 20
//    1	      16   25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;



int serchMax(TreeNode* root)
{
	
	if (root == NULL)
		return 0;

	else if (root->right == NULL && root->left == NULL)
		return root->data;

	else
		serchMax(root->right);
}



int main(void)
{
	printf("max: %d", serchMax(root));

	return 0;
}
