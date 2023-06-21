/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list1[MAX_SIZE];
int list2[MAX_SIZE];
int n;


// 버블정렬
void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}


// 퀵정렬
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}
void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}


int main(void)
{
	int i;
	clock_t start, stop;
	double duration1, duration2;
	n = MAX_SIZE;
	srand(time(NULL));

	for (i = 0; i < n; i++)
		list1[i] = list2[i] = rand();
	
	start = clock();
	bubble_sort(list1, n);
	stop = clock();
	duration1 = (double)(stop - start) / CLOCKS_PER_SEC;

	start = clock();
	quick_sort(list2, 0, n - 1);
	stop = clock();
	duration2 = (double)(stop - start) / CLOCKS_PER_SEC;

	printf("버블정렬 수행시간 %f \n", duration1);
	printf("퀵정렬 수행시간 %f \n", duration2);

	return 0;
}
*/
