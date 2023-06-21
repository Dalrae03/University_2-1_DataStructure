#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
/*
#define MAX_STACK_SIZE 101

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
*/
// ===== ���� �ڵ��� �� ===== 


// 10��
/*
int main(void)
{
	int size = 0;
	StackType numbers;
	element n = 0;

	init_stack(&numbers);

	printf("���� �迭�� ũ��: ");
	scanf("%d", &size);


	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &n);
		push(&numbers, n);
	}

	printf("������ ���� �迭: ");
	for (int i = 0; i < size; i++)
		printf("%d ", pop(&numbers));

	return 0;
}
*/





// 11��
/*
int numbering(char* in)
{
	StackType pare;
	char ch;
	int n = strlen(in);
	element num = 1;

	init_stack(&pare);

	for (int i = 0; i < n; i++)
	{
		ch = in[i];
		
		if (ch == '(')
		{
			push(&pare, num);
			printf("%d ", num);
			num++;
		}

		else
		{
			printf("%d ", pop(&pare));
		}
			

	}

	return 0;
}


int main(void)
{
	char* p = malloc(sizeof(char) * 100);

	printf("����: ");
	scanf("%s", p);
	printf("��ȣ ��: ");
	numbering(p);

	free(p);

	return 0;
}
*/


// 12��
/*
#define MAX_STACK_SIZE 101

typedef char element;
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




int main(void)
{
	StackType result;
	StackType alp;
	int count = 0;
	char ch;
	char* p = malloc(sizeof(char) * 100);

	init_stack(&result);
	init_stack(&alp);


	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%s", p);


	for (int i = 0; p[i] != NULL; i++)
	{
		if (p[i] >= 'A' && p[i] <= 'Z')
			p[i] = p[i] + 32;
		
		push(&alp, p[i]);
	}

	
	ch = pop(&alp);
	push(&result, ch);
	count++;
	
	
	while (!is_empty(&alp))
	{
		ch = pop(&alp);
		if (ch == peek(&result))
		{
			count++;
		}

		else
		{
			push(&result, count);
			push(&result, ch);
			count = 1;
		}
	}
	push(&result, count);

	int c = 1;
	printf("����� ���ڿ�: ");
	while (!is_empty(&result))
	{
		if (c % 2 == 1)
		{
			printf("%d", pop(&result));
			c++;
		}
		else
		{
			printf("%c", pop(&result));
			c++;
		}
	}

	free(p);

	return 0;
}
*/



// 13��
/*
// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 101

typedef char element;
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
*/

/*
int main(void)
{
	StackType number;
	StackType result;
	char* p = malloc(sizeof(char) * 100);

	init_stack(&number);
	init_stack(&result);

	printf("������ �Է��Ͻÿ�: ");
	scanf("%s", p);

	for (int i = 0; p[i] != NULL; i++)
		push(&number, p[i]);


	push(&result, pop(&number));
	while (!is_empty(&number))
	{
		if (peek(&result) == peek(&number))
		{
			pop(&number);
			continue;
		}
			
		else
			push(&result, pop(&number));
	}

	printf("���: ");
	while (!is_empty(&result))
		printf("%c", pop(&result));

	free(p);

	return 0;
}
*/


// 14��
/*
element size(StackType* s)
{
	if (is_empty(s))
		return 0;
	else
		return(s->top + 1);
}

int main(void)
{
	StackType p;
	init_stack(&p);
	printf("%d\n", size(&p));
	
	push(&p, 'c');
	printf("%d\n", size(&p));

	pop(&p);
	printf("%d\n", size(&p));

	return 0;
}
*/


// 16��

#define MAX_STACK_SIZE 101

typedef char element;
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

int main(void)
{
	StackType a;
	char ch;
	int size = 0;
	int count = 0;

	char* p = malloc(sizeof(char) * 100);
	char r[101];

	init_stack(&a);
	

	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%[^\n]s", p);

	
	for (int i = 0; p[i] != NULL; i++)
	{
		if (p[i] >= 'A' && p[i] <= 'z')
		{
			if (p[i] >= 'A' && p[i] <= 'Z')
				p[i] = p[i] + 32;
			push(&a, p[i]);
			r[i] = p[i];

		}
	}

	for (int i = 0; i < p[i]; i++)
	{
		if (p[i] == ' ' || p[i] == '.')
			continue;
		else
		{
			r[count] = p[i];
			count++;
		}
	}

	size = a.top + 1;

	for (int i = 0; i < size; i++)
	{
		if (pop(&a) != r[i])
		{
			printf("ȸ���� �ƴմϴ�.");
			exit(1);
		}
	}

	printf("ȸ���Դϴ�.");

	return 0;
}
