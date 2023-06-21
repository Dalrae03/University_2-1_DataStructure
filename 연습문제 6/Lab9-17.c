/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

// ���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode*  insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)
	pre->link = p;		//(4)
	return head;		//(5)
}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}


ListNode* alternate(ListNode* head1, ListNode* head2)
{
	ListNode* result = NULL;
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));

	while (head1 || head2)
	{
		if (head1 != NULL) {
			result = insert_first(result, head1->data);
			head1 = head1->link;
		}
		if (head2 != NULL) {
			result = insert_first(result, head2->data);
			head2 = head2->link;
		}
	}

	return result;
}



// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* r = NULL;

	for (int i = 1; i <= 5; i++) {
		head1 = insert_first(head1, i);
	}
	print_list(head1);

	for (int i = 1; i <= 5; i++) {
		head2 = insert_first(head2, i * 10);
	}
	print_list(head2);

	printf("\n");
	r = alternate(head1, head2);
	print_list(r);

	return 0;
}
*/
