
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
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
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
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
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
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



ListNode* search(ListNode* L, element data)
{
	ListNode* p;
	p = L;
	for (p = L; p != L; p = p->link) {
		if (p->data == data) {
			return p;
		}
	}
	return NULL;
}



ListNode* search1(ListNode* L, element data) {
	ListNode* p = L;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != L);
	return NULL;
}


// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *head = NULL;
	ListNode* r;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	printf("\n");

	r = search(head, 40);
	print_list(r);


	return 0;
}
