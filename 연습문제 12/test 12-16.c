/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	int i, j, least, temp, k;

	printf("( )");
	printf("            (");
	for (int i = 0; i < n - 1; i++)
		printf("%d,", list[i]);
	printf("%d)            �ʱ����\n", list[n - 1]);


	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// �ּҰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);


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

		printf("            %d���� �� %d�� ��ȯ\n", list[i],list[least]);
	}

	printf("(");
	for (int a = 0; a < n - 1; a++)
		printf("%d,", list[a]);
	printf("%d)            ()            %d���� �� %d�� ��ȯ", list[n - 1], list[n - 1], list[n - 1]);
}



int main(void)
{
	int n;
	int number[100];

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &number[i]);

	selection_sort(number, n);

	return 0;
}
*/
