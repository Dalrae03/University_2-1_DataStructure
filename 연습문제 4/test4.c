#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
/*
#define MAX_STACK_SIZE 101

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
*/
// ===== 스택 코드의 끝 ===== 


// 10번
/*
int main(void)
{
	int size = 0;
	StackType numbers;
	element n = 0;

	init_stack(&numbers);

	printf("정수 배열의 크기: ");
	scanf("%d", &size);


	printf("정수를 입력하시오: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &n);
		push(&numbers, n);
	}

	printf("반전된 정수 배열: ");
	for (int i = 0; i < size; i++)
		printf("%d ", pop(&numbers));

	return 0;
}
*/





// 11번
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

	printf("수식: ");
	scanf("%s", p);
	printf("괄호 수: ");
	numbering(p);

	free(p);

	return 0;
}
*/


// 12번
/*
#define MAX_STACK_SIZE 101

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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


	printf("문자열을 입력하시오: ");
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
	printf("압축된 문자열: ");
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



// 13번
/*
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 101

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 
*/

/*
int main(void)
{
	StackType number;
	StackType result;
	char* p = malloc(sizeof(char) * 100);

	init_stack(&number);
	init_stack(&result);

	printf("정수를 입력하시오: ");
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

	printf("출력: ");
	while (!is_empty(&result))
		printf("%c", pop(&result));

	free(p);

	return 0;
}
*/


// 14번
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


// 16번

#define MAX_STACK_SIZE 101

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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
	

	printf("문자열을 입력하시오: ");
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
			printf("회문이 아닙니다.");
			exit(1);
		}
	}

	printf("회문입니다.");

	return 0;
}
