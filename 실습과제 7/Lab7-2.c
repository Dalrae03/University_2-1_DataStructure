/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list1[MAX_SIZE];
int list2[MAX_SIZE];
int list3[MAX_SIZE];
int n;


// ��������
void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}

// ��������
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}


// ��������
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// �ּҰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
		
	}
	for (int j = 0; j < n; j++)
		printf("%d ", list[j]);
	printf("\n");
}


int main(void)
{
	int i;
	//clock_t start, stop;
	//double duration1, duration2, duration3;
	//n = MAX_SIZE;
	//srand(time(NULL));
	

	for (i = 0; i < n; i++)      	 
		list1[i] = list2[i] = list3[i] = rand();

	start = clock();
	selection_sort(list1, n); 
	stop = clock();
	duration1 = (double)(stop - start) / CLOCKS_PER_SEC;

	start = clock();
	insertion_sort(list2, n); 
	stop = clock();
	duration2 = (double)(stop - start) / CLOCKS_PER_SEC;

	start = clock();
	bubble_sort(list3, n);
	stop = clock();
	duration3 = (double)(stop - start) / CLOCKS_PER_SEC;

	printf("�������� ����ð� %f \n", duration1);
	printf("�������� ����ð� %f \n", duration2);
	printf("�������� ����ð� %f \n", duration3);

	int list2[8] = { 5,7,4,8,9,1,6,3 };
	for (int j = 0; j < n; j++)
		printf("%d ", list2[j]);
	printf("\n");
	insertion_sort(list2, 8);

	
	for (i = 0; i < n; i++)
		printf("%d ", list2[i]);

	printf("\n");

	return 0;
}
*/
