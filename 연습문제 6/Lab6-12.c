/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

void search(ListNode* head, int key)
{
	int count = 0;
	for (ListNode* p = head; p != NULL; p = p->link)
		if (p->data == key)
			count++;
	if (count != 0)
		printf("%d는 연결 리스트에서 %d번 나타납니다.", key, count);
	else
		printf("찾는값이 없습니다.");

	return 0;

}


// 테스트 프로그램
int main(void)
{
	int n;
	int find = 0;
	ListNode* head = NULL;


	printf("노드의 개수 : ");
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		int j;

		printf("노드 #%d 데이터 : ", i + 1);
		scanf("%d", &j);

		head = insert_first(head, j);
	}

	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &find);
	
	search(head, find);

	return 0;
}
*/


