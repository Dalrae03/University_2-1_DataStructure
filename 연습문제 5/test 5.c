/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 8
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// peek �Լ�
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== ����ť �ڵ� �� ======
*/


/*
// ���� ��ȯ �Լ� (8������)
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
	
	printf("���� ����: %d", get_count(&queue));

	return 0;
}
*/

