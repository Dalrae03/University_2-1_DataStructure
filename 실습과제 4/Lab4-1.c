/*
#include <stdio.h>
#define M 3
#define N 2

// C = A + B
void matrix_Add(int A[M][N], int B[M][N], int C[M][N])
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];

	return 0;
}


// C = A * B
void matrix_multiply(int A[M][N], int B[N][M], int C[M][M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int h = 0; h < N; h++)
				C[i][j] += A[i][h] * B[h][j];
		}
	}

	return 0;
}


// µ¡¼À ÇÁ¸°Æ®
void matrix_print(int C[M][N])
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
			
	return 0;
}

// °ö¼À ÇÁ¸°Æ®
void matrix_print1(int C[M][M])
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}

	return 0;
}
*/


// µ¡¼À Áõ¸í
/*
int main(void)
{

	int a[M][N] = { {0,10},{7,7},{9,2} };
	int b[M][N] = { {1,5},{19,24},{4,50} };
	int c[M][N] = { 0 };

	matrix_Add(a, b, c);
	matrix_print(c);

	return 0;
}
*/



// °ö¼À Áõ¸í
/*
int main(void)
{
	int a[M][N] = { {2,1},{0,7},{5,2} };
	int b[N][M] = { {5,3,7},{1,1,0} };
	int c[M][M] = { 0 };
	int d[M][N] = { {20,18},{10,7},{3,1} };
	int e[N][M] = { {1,21,5},{34,16,0} };
	int f[M][M] = { 0 };

	matrix_multiply(a, b, c);
	matrix_multiply(d, e, f);
	matrix_print1(c);
	matrix_print1(f);

	return 0;
}
*/