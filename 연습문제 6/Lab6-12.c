/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)
	pre->link = p;		//(4)
	return head;		//(5)
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

void search(ListNode* head, int key)
{
	int count = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		if (p->data == key)
			count++;
	if (count != 0)
		printf("%d�� ���� ����Ʈ���� %d�� ��Ÿ���ϴ�.", key, count);
	else
		printf("ã�°��� �����ϴ�.");

	return 0;

}


// �׽�Ʈ ���α׷�
int main(void)
{
	int n;
	int find = 0;
	ListNode* head = NULL;


	printf("����� ���� : ");
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		int j;

		printf("��� #%d ������ : ", i + 1);
		scanf("%d", &j);

		head = insert_first(head, j);
	}

	printf("Ž���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &find);
	
	search(head, find);

	return 0;
}
*/


