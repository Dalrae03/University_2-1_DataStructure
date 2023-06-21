/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h> 

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
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
// pre가 가리키는 노드의 다음 노드를 삭제한다.
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

ListNode* sear_del_list(ListNode* head, element x)
{
	ListNode* p = head;
	//ListNode* removed = head->link;
	ListNode* remove;

	if (head == NULL)
		return NULL;

	else
	{
		while (p->link != NULL)
		{
			if (p->link->data == x)
			{
				remove = p->link;
				p->link = remove->link;
				free(remove);
			}
			p = p->link;
		}
	}

	return NULL;
}


// 테스트 프로그램
int main(void)
{
	int max = 0;
	int min = INT_MAX;
	ListNode* head = NULL;
	ListNode* p;
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		int a = rand() % 10;
		head = insert_first(head, a);
	}
	print_list(head);

	p = head;
	while (p != NULL)
	{
		if (max < p->data)
			max = p->data;
		if (min > p->data)
			min = p->data;
		p = p->link;
	}

	printf("max: %d, min: %d", max, min);

	return 0;
}
*/

