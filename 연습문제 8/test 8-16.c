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
//           5
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n7 = { 5,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, &n7, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };

TreeNode *root = &n6;


//		  15
//	   4		 20
//    1	      16  25
//           5

// 자식이 하나만 있는 노드 개수의 반환
int countOneNode(TreeNode* root) {

	if (root == NULL)
		return 0;
	
	int count = 0;
	if ((root->right == NULL && root->left != NULL) || (root->right != NULL && root->left == NULL))
		count++;
	count = count + countOneNode(root->left) + countOneNode(root->right);

	return count;

}


int main(void)
{
	
	printf("값: %d", countOneNode(root));


	return 0;
}
*/


