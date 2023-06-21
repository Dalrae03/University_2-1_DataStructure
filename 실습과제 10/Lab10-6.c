/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}
// 노드 removed를 삭제한다.
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
*/

