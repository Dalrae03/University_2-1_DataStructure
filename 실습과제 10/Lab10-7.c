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


DListNode* search(DListNode* L, element data)
{
	DListNode* p;
	for (p = L->rlink; p != L; p = p->rlink) {
		if (p->data == data) {
			return p;
		}
	}
	return NULL;
}


// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	int n;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	DListNode* R = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	srand(time(NULL));

	
	
	for (int i = 0; i < 1000; i++) {
		int num = rand();
		// ��� ����� �����ʿ� ����
		dinsert(head, num);
	}
	

	for (int i = 0; i < 8; i++)
		dinsert(head, i);

	print_dlist(head);

	printf("ã�� ���� �Է�: ");
	scanf("%d", &n);

	R = search(head, n);
	
	print_dlist(R);
	
	free(head);
	return 0;
}
*/


