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


//		  15
//	   4		 20
//    1	      16  25

void pulse(TreeNode* root)
{
	if (root == NULL)
		return 0;

	pulse(root->left);
	root->data = (root->data) + 1;
	printf("[%d] ", (root->data)); 
	pulse(root->right);
}




int main(void)
{
	printf("1¡ı∞°\n");
	pulse(root);
	
	return 0;
}
*/