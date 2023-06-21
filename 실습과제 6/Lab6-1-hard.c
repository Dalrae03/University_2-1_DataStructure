/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 9

typedef struct {		// 교체!
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 =====



int count = 0;
element here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1', '1', '1', '1'},
{ 'e', '0', '1', '0', '0', '0', '1', '1', '1'},
{ '1', '0', '0', '0', '1', '1', '1', '1', '1'},
{ '1', '0', '1', '0', '0', '1', '1', '1', '1'},
{ '1', '1', '1', '1', '0', '0', '0', '1', '1'},
{ '1', '1', '0', '0', '0', '1', '1', '1', '1'},
{ '1', '0', '0', '1', '1', '1', '1', '1', '1'},
{ '1', '1', '0', '0', '0', '0', '0', '0', 'x'},
{ '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// 위치를 스택에 삽입
int push_loc(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return 1;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
		count++;
		return 0;
	}
	else
		return 1;
}
// 미로를 화면에 출력한다.
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int r, c;
	int blocking = 0;
	StackType s;
	StackType road;
	StackType separate;

	init_stack(&s);
	init_stack(&road);
	init_stack(&separate);

	here = entry;
	printf("(%d, %d)\n", here.r, here.c);
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		
		blocking += push_loc(&s, r - 1, c); //왼쪽
		blocking += push_loc(&s, r + 1, c); //오른쪽
		blocking += push_loc(&s, r, c - 1); //아래
		blocking += push_loc(&s, r, c + 1); //위

		if (count >= 2)
			push(&separate, here);

		count = 0;

		if (blocking == 4)
		{
			int a = peek(&separate).r;
			int b = peek(&separate).c;
			int c = peek(&road).r;
			int d = peek(&road).c;


			while (a != c || b != d)
			{
				element test = { 0,0 };
				int R, C;
				test = pop(&road);
				R = test.r;
				C = test.c;
				maze[R][C] = '0';

				a = peek(&separate).r;
				b = peek(&separate).c;
				c = peek(&road).r;
				d = peek(&road).c;
			}
			
		}		

		if (is_empty(&s)) { // 아예 막혀서 갈림길도 없는상황
			printf("실패\n");
			return;
		}
		else
		{
			here = pop(&s);
			push(&road, here);
		}
			
		blocking = 0;
	}

	
	for (int i = 0; i < 49; i++)
	{
		element result = { 0,0 };
		result = road.data[i];
		if (result.r >= 0 && result.c >= 0)
			printf("(%d, %d)\n", result.r, result.c);
		else
			break;
	}
	
	return 0;
}
*/