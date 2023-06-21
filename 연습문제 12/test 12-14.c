/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// 삽입정렬
void insertion_sort(int list[], int n)
{
	int i, j, key, k;

	printf("( )");
	printf("            (");
	for (int i = 0; i < n-1; i++)
		printf("%d,", list[i]);
	printf("%d)\n", list[n-1]);

	printf("(%d)",list[0]);
	printf("            (");
	for (int l = 1; l < n - 1; l++)
		printf("%d,", list[l]);
	printf("%d)            %d삽입\n", list[n-1], list[0]);


	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;

		printf("(");
		for (k = 0; k < i; k++)
			printf("%d,", list[k]);
		printf("%d)", list[i]);

		printf("            (");
		for (int p = k + 1; p < n - 1; p++)
			printf("%d,", list[p]);

		if (i == n - 1)
			printf(" )");
		else
			printf("%d)", list[n - 1]);

		printf("            %d삽입\n",key);
	}
}


// 14번
int main(void)
{
	int n;
	int number[100];

	printf("숫자 개수 입력: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &number[i]);
	
	insertion_sort(number, n);

	return 0;
}
*/

