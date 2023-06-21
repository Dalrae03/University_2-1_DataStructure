
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;


// ================ ����ť �ڵ� ���� =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->data);  // ��� �湮
		inorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);  // ��� �湮
		preorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);// ���ʼ���Ʈ�� ��ȸ
		postorder(root->right);// �����ʼ���Ʈ����ȸ
		printf("[%d] ", root->data);  // ��� �湮
	}
}

//		    15
//	   4		 20
//    1	      16  25
//     3         23
TreeNode n1 = { 3,  NULL, NULL };
TreeNode n2 = { 1,  NULL, &n1 };
TreeNode n3 = { 4,  &n2,  NULL };
TreeNode n4 = { 23,  NULL, NULL };
TreeNode n5 = { 16, NULL, NULL };
TreeNode n6 = { 25, &n4, NULL };
TreeNode n7 = { 20, &n5,  &n6 };
TreeNode n8 = { 15, &n3,  &n7 };
TreeNode* root = &n8;


void level_order(TreeNode* ptr)
{
	QueueType q;

	init_queue(&q);	 // ť �ʱ�ȭ

	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}


int main(void)
{
	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	postorder(root);
	printf("\n");
	

	printf("���� ��ȸ=");
	level_order(root);
	printf("\n");
	return 0;
}

