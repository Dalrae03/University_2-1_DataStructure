/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
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
	return head;	// 변경된 헤드 포인터를 반환한다. 
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
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

// 원형 연결 리스트 L에 저장된 데이터의 개수를 반환한다.
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


// 원형 연결 리스트 테스트 프로그램
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
	printf("개수: %d", get_size(head));
	return 0;
}



// 연습문제 6번 역순 출력
// 왼쪽삽입
void back_print(DListNode* phead)
{
	DListNode* p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf("%d ", p->data);
	}
	printf("\n");

	return 0;
}

// 역순 출력
void linsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = before;
	newnode->llink = before->llink;
	before->llink->rlink = newnode;
	before->llink = newnode;
}


// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	int n;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	srand(time(NULL));

	printf("데이터의 개수를 입력하시오 : ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int num = rand();
		printf("노드 #%d의 데이터를 입력하시오: ", i);
		printf("%d\n", num);
		linsert(head, num);
	}

	printf("데이터를 역순으로 출력: ");
	back_print(head);

	free(head);
	return 0;
}



// 연습문제 7번 노드반환
// 입력한 값 찾아 노드 반환
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

// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	int n;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	DListNode* R = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	srand(time(NULL));


	
	for (int i = 0; i < 1000; i++) {
		int num = rand();
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, num);
	}
	

	for (int i = 0; i < 8; i++)
		dinsert(head, i);

	print_dlist(head);

	printf("찾는 숫자 입력: ");
	scanf("%d", &n);

	R = search(head, n);

	print_dlist(R);

	free(head);
	return 0;
}
*/