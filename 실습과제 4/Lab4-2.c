#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 120000
#define size 500000

//희소행렬 표현방법 #1 - 2차원 배열을 이용하여 배열의 전체 요소를 저장하는 방법
// 행렬 전치 함수
/*
#include <stdio.h>
#define ROWS 3  // 행
#define COLS 3  // 열

void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			B[c][r] = A[r][c];
}

void matrix_print(int A[ROWS][COLS])
{
	printf("==========================\n");
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
			printf("%d", A[r][c]);
		printf("\n");
	}
	printf("==========================\n");
}

int main(void)
{
	int array1[ROWS][COLS] = { {2,3,0},
		{8,9,1},
		{7,0,5} };
	int array2[ROWS][COLS];
	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);

	return 0;
}
*/

// 추가 복습 요망
//희소행렬 표현방법 #2 - 0이 아닌 요소들만 저장하는 방법 (대부분 이거 사용, 각종행렬 연산들의 구현이 복잡해지지만, 희소행렬의 경우 메모리공간의 절약)
/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100

typedef struct {
	int row;
	int col;
	int value;
}element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows; // 행의 개수
	int cols; // 열의 개수
	int terms; // 항의 개수
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;

	int bindex; //행렬 b에서 현재 저장 위치
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	if (a.terms > 0)
	{
		bindex = 0;
		for (int c = 0; c < a.cols; c++)
		{
			for (int i = 0; i < a.terms; i++)
			{
				if (a.data[i].col == c)
				{
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("==========================\n");
	for (int i = 0; i < a.terms; i++)
	{
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("==========================\n");
}

int main(void)
{
	SparseMatrix m = {
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	};
	SparseMatrix result;

	result = matrix_transpose2(m);
	matrix_print(result);
	return 0;
}
*/


//int 형
int sum_Array(int A[])
{
	int sum = 0;
	int result = 0;
	
	for (int i = 0; i < SIZE; i++)
		sum += A[i];

	result = sum / SIZE;

	return sum;
}

/*
long long sum_Array(int A[])
{
	long long sum = 0;
	long long result = 0;

	for (long long i = 0; i < size; i++)
		sum += A[i];

	result = sum / size;

	return sum;
}
*/

int main(void)
{
	int list[SIZE];
	int R = 0;

	srand((unsigned)time(NULL)); // 초기화

	for (int i = 0; i < SIZE; i++)
		list[i] = rand();

	R = sum_Array(list);
	printf("%d", R);	

	return 0;
}