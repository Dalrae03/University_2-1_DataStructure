/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // ������ ��� ���
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

// ���� ���� ����Ʈ L�� ����� �������� ������ ��ȯ�Ѵ�.
int get_size(ListNode* L)
{
	int count = 0;
	ListNode* p;

	p = L;

	do {
		count++;
		p = p->link;
	} while (p != L);

	return count;
}


// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	srand(time(NULL));

	for (int i = 0; i < 1000; i++)
	{
		int num = rand();
		head = insert_first(head, num);
	}

	print_list(head);
	printf("\n");
	printf("����: %d", get_size(head));
	return 0;
}



// �������� 6�� ���� ���
// ���ʻ���
void back_print(DListNode* phead)
{
	DListNode* p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf("%d ", p->data);
	}
	printf("\n");

	return 0;
}

// ���� ���
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



// �������� 7�� ����ȯ
// �Է��� �� ã�� ��� ��ȯ
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