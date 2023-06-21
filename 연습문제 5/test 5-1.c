/*
#include <stdio.h>
#include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 



// 9��
typedef struct {
	StackType s1;
	StackType s2;
} QueueType;


void stack_push(QueueType* q, element item)
{
	push(&(q->s1), item);
}


int stack_pop(QueueType* q)
{
	if (is_empty(&(q->s2)))
		while (!is_empty(&(q->s1))) {
			push(&(q->s2), pop(&(q->s1)));
		}
	return pop(&(q->s2));
}

int main(void)
{
	QueueType q;

	init_stack(&(q.s1));
	init_stack(&(q.s2));

	stack_push(&q, 10);
	stack_push(&q, 20);
	stack_push(&q, 30);
	
	printf("%d\n", stack_pop(&q));
	printf("%d\n", stack_pop(&q));
	printf("%d\n", stack_pop(&q));

	return 0;
}
*/



