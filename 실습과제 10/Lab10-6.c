/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct DListNode {	// ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// ��� removed�� �����Ѵ�.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}




void back_print(DListNode* phead)
{
	DListNode* p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf("%d ", p->data);
	}
	printf("\n");

	return 0;
}

void linsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = before;
	newnode->llink = before->llink;
	before->llink->rlink = newnode;
	before->llink = newnode;
}


// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	int n;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	srand(time(NULL));

	printf("�������� ������ �Է��Ͻÿ� : ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int num = rand();
		printf("��� #%d�� �����͸� �Է��Ͻÿ�: ", i);
		printf("%d\n", num);
		linsert(head, num);
	}

	printf("�����͸� �������� ���: ");
	back_print(head);

	free(head);
	return 0;
}
*/

