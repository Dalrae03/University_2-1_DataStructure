#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
// 504반 C289044 이예진

typedef char element;		// char -> element로 교체


// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 100


typedef struct {                // 구조체
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








int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= 문자열의 길이
	init_stack(&s);			// 스택의 초기화
	int count = 0;
	char a;

	for (i = 0; i < n; i++)
	{
		ch = in[i];		// ch = 다음 문자
		if (ch != ' ')
			count++;
		int k = 0;  // stack에 입력했던 괄호의 짝이 있는지 검사할때 참거짓 저장


		switch (ch) 
		{
		case '(':  // push 함수 
		case '[':    
		case '{':  
			push(&s, ch);
			break;

		case ')':   
		case ']':    
		case '}':
			if (is_empty(&s))  // 스택이 비어있는데 닫는괄호가 들어간경우 (3번째 조건)
			{
				printf("수식 스캔시 %d번째 글자 '%c'를 만났는데 스택에는 여는 괄호가 없음.\n", count, ch);
				return 0;
			}

			else {
				for (int z = 0; z <= s.top; z++)
				{
					a = s.data[z];

					if ((a == '(' && ch == ')') ||
						(a == '[' && ch == ']') ||
						(a == '{' && ch == '}'))
					{
						k = 1;
					}
				}

				if (k == 1)
				{
					open_ch = pop(&s);   // stack 마지막과 입력된 괄호 비교해서 아닌경우 
					if ((open_ch == '(' && ch != ')') ||
						(open_ch == '[' && ch != ']') ||
						(open_ch == '{' && ch != '}')) {

						// (4번째 조건)
						printf("수식 스캔시 %d번째 글자 '%c'를 만났는데 스택위에는 \"%c\"가 있어 서로 맞지 않음.\n", count, ch, open_ch);
						return 0;
					}
				}

				else
				{
					printf("수식 스캔시 %d번째 글자 '%c'를 만났는데 스택에는 여는 괄호가 없음.\n", count, ch);
					return 0;
				}

				break;
			}
		}
	}
	if (!is_empty(&s))
	{
		printf("수식의 끝까지 스캔했을때도, 스택에 아직 여는괄호들이 남아있음. 스택 내용: ");
		for (int l = 0; l <= s.top; l++)
			printf("%c", s.data[l]);
		return 0; // 스택에 남아있으면 오류
	}
	return 1;
}


int main(void)
{
	char* p = "{ A[(i+1)]=0; }(";
	printf("검사 식: %s\n", p);
	if (check_matching(p) == 1)
		printf("괄호검사성공\n");

	return 0;
}