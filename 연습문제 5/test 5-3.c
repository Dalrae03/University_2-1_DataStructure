#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 100
typedef char element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} DequeType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void deque_print(DequeType* q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// fornt 삭제 함수
element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// front peek 함수
element get_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}


// 11번
int main(void)
{
	DequeType pal;
	char a;
	char b;
	int count = 0;

	char* p = malloc(sizeof(char) * 100);

	init_deque(&pal);

	printf("문자열 입력: ");
	scanf("%[^\n]s", p);

	for (int i = 0; p[i] != NULL; i++)
	{
		if (p[i] >= 'A' && p[i] <= 'z')
		{
			if (p[i] >= 'A' && p[i] <= 'Z')
				p[i] = p[i] + 32;
			add_front(&pal, p[i]);
			count++;

		}
	}
	
	
	if (count % 2 == 1)
	{
		for (int i = count; count == 1; count -= 2)
		{
			a = delete_front(&p);
			b = delete_rear(&p);
			if (a == b)
				continue;
			else
			{
				printf("회문이 아닙니다.");
				break;
			}
		}
	}
	
	else
	{
		for (int i = count; count == 0; count -= 2)
		{
			a = delete_front(&p);
			b = delete_rear(&p);
			if (a == b)
				continue;
			else
			{
				printf("회문이 아닙니다.");
				break;
			}
		}
	}

	printf("회문입니다.");

	return 0;
}