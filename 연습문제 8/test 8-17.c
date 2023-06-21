/*
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define MIN -10
#define MAX 980000

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
//		  15
//	   16		 10
//    1	      5  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 16,  &n1,  NULL };
TreeNode n3 = { 5, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 10, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;



//		  15
//	   16		 10
//    1	      5  25

// ��ȯȣ����........


// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->data);  // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}


int serchMax(TreeNode* root)
{
	if (root == NULL)
		return MIN;

	int max_value = root->data;
	max_value = max(max_value, serchMax(root->right));
	max_value = max(max_value, serchMax(root->left));

	return max_value;
}

int serchMin(TreeNode* root)
{

	if (root == NULL)
		return MAX;

	int min_value = root->data;
	min_value = min(min_value, serchMin(root->right));
	min_value = min(min_value, serchMin(root->left));

	return min_value;
}




int main(void)
{
	int ma, mi;

	ma = serchMax(root);
	mi = serchMin(root);

	//ma = find_max(root);
	//mi = find_min(root);

	printf("�ּҰ�: %d, �ִ밪: %d", mi, ma);




	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");

	return 0;
}
*/

