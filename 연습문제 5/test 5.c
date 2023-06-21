/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 8
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
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
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// peek 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======
*/


/*
// 개수 반환 함수 (8번문제)
int get_count(QueueType* p)
{
	int r = p->rear;
	int f = p->front;
	int result;

	if (r < f)
		result = r - (f - MAX_QUEUE_SIZE);

	else
		result = r - f;

	return result;
}



int main(void)
{
	QueueType queue;
	int element;

	init_queue(&queue);
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);
	enqueue(&queue, 50);
	enqueue(&queue, 60);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	enqueue(&queue, 60);
	enqueue(&queue, 60);
	enqueue(&queue, 60);
	
	printf("남은 개수: %d", get_count(&queue));

	return 0;
}
*/

