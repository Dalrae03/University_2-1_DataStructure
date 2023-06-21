
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
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
// pre가 가리키는 노드의 다음 노드를 삭제한다.
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


ListNode* add(ListNode* head, element item) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}


ListNode* merge(ListNode* head1, ListNode* head2)
{
	ListNode* result = NULL;

	while (head1 || head2)
	{
		ListNode* ptr;
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
		if (head1 != NULL && head2 != NULL) {
			if (head1->data <= head2->data) {

				temp->data = head1->data;
				temp->link = NULL;

				if (result == NULL)
					result = temp;

				else
				{
					ptr = result;
					while (ptr->link != NULL)
						ptr = ptr->link;
					ptr->link = temp;
				}
				head1 = head1->link;
			}
			else
			{
				temp->data = head2->data;
				temp->link = NULL;

				if (result == NULL)
					result = temp;

				else
				{
					ptr = result;
					while (ptr->link != NULL)
						ptr = ptr->link;
					ptr->link = temp;
				}
				head2 = head2->link;
			}
		}

		if (head1 == NULL) {
			ListNode* p;
			p = result;
			while (p->link != NULL)
				p = p->link;
			p->link = head2;
			break;
		}
		else if (head2 == NULL) {
			ListNode* p;
			p = result;
			while (p->link != NULL)
				p = p->link;
			p->link = head1;
			break;
		}
	}
	return result;
}





ListNode* merge1(ListNode* head, ListNode* head2) {
	ListNode* result = NULL;
	while (head || head2) {
		ListNode* ptr;
		ListNode* temp = (ListNode*)malloc(sizeof(ListNode));

		if (head != NULL && head2 != NULL) {
			if (head->data >= head2->data) {
				//result = add(result, head2->data);

				temp->data = head2->data;
				temp->link = NULL;

				if (result == NULL)
					result = temp;

				else
				{
					ptr = result;
					while (ptr->link != NULL)
						ptr = ptr->link;
					ptr->link = temp;
				}
				head2 = head2->link;

				//head2 = head2->link;
			}
			else {
				//result = add(result, head->data);

				temp->data = head->data;
				temp->link = NULL;

				if (result == NULL)
					result = temp;

				else
				{
					ptr = result;
					while (ptr->link != NULL)
						ptr = ptr->link;
					ptr->link = temp;
				}
				head = head->link;

				//head = head->link;
			}
		}
		if (head == NULL)
		{
			result = add(result, head2->data); 
			head2 = head2->link;
		}
		else if (head2 == NULL) { 
			result = add(result, head->data); 
			head = head->link; 
		}
	}
	return result;
}


// 테스트 프로그램
int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* r = NULL;


	head1 = insert_first(head1, 7);
	head1 = insert_first(head1, 6);
	head1 = insert_first(head1, 5);
	head1 = insert_first(head1, 3);
	head1 = insert_first(head1, 1);
	print_list(head1);


	head2 = insert_first(head2, 10);
	head2 = insert_first(head2, 9);
	head2 = insert_first(head2, 8);
	head2 = insert_first(head2, 4);
	head2 = insert_first(head2, 2);
	print_list(head2);

	r = merge(head1, head2);
	print_list(r);

	return 0;
}
