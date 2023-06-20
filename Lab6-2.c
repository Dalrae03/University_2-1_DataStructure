/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 47


typedef int element;

typedef struct { 				// 큐 타입
	int  front;
	int rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;


// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}

int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}




int main(void)
{
	int item = 0;
	QueueType fib;

	init_queue(&fib);

	enqueue(&fib, 0);  // F(0) = 0 
	enqueue(&fib, 1);  // F(1) = 1

	for (int i = 2; i <= MAX_QUEUE_SIZE-1; i++)
	{
		int frist = dequeue(&fib);
		item = frist + fib.data[fib.front + 1];
		enqueue(&fib, item);
	}

	printf("피보나치 수열 46번째: %d\n", fib.data[MAX_QUEUE_SIZE-1]);

	return 0;
}
*/