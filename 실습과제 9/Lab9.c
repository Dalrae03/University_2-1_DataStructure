#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int i = 0;
	ListNode* p = head;
	ListNode* q = NULL;
	ListNode* revers;

	printf("첫 10개의 값:");
	while (i < 10)
	{
		printf("%d, ", p->data);

		if (i == 9)
			printf("%d\n", p->data);

		p = p->link;
		i++;
	}

	while (p != NULL)
	{
		revers = q;
		q = p;
		p = p->link;
		q->link = revers;
	}

	printf("마지막 10개의 값: ");
	for (int j = 0; j < 9; j++) {
		printf("%d, ", q->data);
		q = q->link;
	}
	printf("%d\n", q->data);

	return 0;
}


int get_length(ListNode* head)
{
	int count = 0;

	for (ListNode* p = head; p != NULL; p = p->link)
		count++;

	return count;
}

void print_list1(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d, ", p->data);
	printf("NULL \n");
}


// 테스트 프로그램
int main(void)
{
	srand(time(NULL));

	ListNode* head = NULL;

	for (int i = 0; i < 1000; i++) {
		int random = rand();
		head = insert_first(head, random);
	}

	print_list1(head);

	printf("노드의 개수: %d \n", get_length(head));

	print_list(head);

	return 0;
}