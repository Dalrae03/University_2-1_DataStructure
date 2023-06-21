/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS  2


void print_bucket(QueueType*q, int list[])
{
	printf("================\n");
	for (int u = 0; u < BUCKETS; u++)
	{
		printf("[%d]-> ", u);
		for (int i = 0; i < list[u]; i++)
		{
			if(q[u].data[i]>-1)
				printf("%d ", q[u].data[i]);
		}	
		printf("\n");
	}
	printf("================\n");

	return 0;
}


void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	int count[10] = { 0 };
	QueueType queues[BUCKETS];

	for (b = 0; b<BUCKETS; b++) 
		init_queue(&queues[b]);  // ť���� �ʱ�ȭ

	for (d = 0; d<DIGITS; d++) {
		for (i = 0; i < n; i++)			// �����͵��� �ڸ����� ���� ť�� ����
		{
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
			count[(list[i] / factor) % 10] += 1;
			//printf("%d. %d\n", i, list[i]);
		}
			
		print_bucket(queues, count);

		for (b = i = 0; b<BUCKETS; b++)  // ��Ŷ���� ������ list�� ��ģ��.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;					// �� ���� �ڸ����� ����.
		
	}
}

#define  SIZE 10

int main(void)
{
	int list[SIZE] = { 58,69,0,62,34,24,64,78,91,47 };	

	radix_sort(list, SIZE); // ������� ȣ��
	for (int i = 0; i<SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
*/
