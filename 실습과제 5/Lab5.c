#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
// 504�� C289044 �̿���

typedef char element;		// char -> element�� ��ü


// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100


typedef struct {                // ����ü
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








int check_matching(const char* in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= ���ڿ��� ����
	init_stack(&s);			// ������ �ʱ�ȭ
	int count = 0;
	char a;

	for (i = 0; i < n; i++)
	{
		ch = in[i];		// ch = ���� ����
		if (ch != ' ')
			count++;
		int k = 0;  // stack�� �Է��ߴ� ��ȣ�� ¦�� �ִ��� �˻��Ҷ� ������ ����


		switch (ch) 
		{
		case '(':  // push �Լ� 
		case '[':    
		case '{':  
			push(&s, ch);
			break;

		case ')':   
		case ']':    
		case '}':
			if (is_empty(&s))  // ������ ����ִµ� �ݴ°�ȣ�� ����� (3��° ����)
			{
				printf("���� ��ĵ�� %d��° ���� '%c'�� �����µ� ���ÿ��� ���� ��ȣ�� ����.\n", count, ch);
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
					open_ch = pop(&s);   // stack �������� �Էµ� ��ȣ ���ؼ� �ƴѰ�� 
					if ((open_ch == '(' && ch != ')') ||
						(open_ch == '[' && ch != ']') ||
						(open_ch == '{' && ch != '}')) {

						// (4��° ����)
						printf("���� ��ĵ�� %d��° ���� '%c'�� �����µ� ���������� \"%c\"�� �־� ���� ���� ����.\n", count, ch, open_ch);
						return 0;
					}
				}

				else
				{
					printf("���� ��ĵ�� %d��° ���� '%c'�� �����µ� ���ÿ��� ���� ��ȣ�� ����.\n", count, ch);
					return 0;
				}

				break;
			}
		}
	}
	if (!is_empty(&s))
	{
		printf("������ ������ ��ĵ��������, ���ÿ� ���� ���°�ȣ���� ��������. ���� ����: ");
		for (int l = 0; l <= s.top; l++)
			printf("%c", s.data[l]);
		return 0; // ���ÿ� ���������� ����
	}
	return 1;
}


int main(void)
{
	char* p = "{ A[(i+1)]=0; }(";
	printf("�˻� ��: %s\n", p);
	if (check_matching(p) == 1)
		printf("��ȣ�˻缺��\n");

	return 0;
}