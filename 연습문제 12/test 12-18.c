/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high, mid;

	low = left;
	high = right;
	mid = left + right;

	if (list[left] > list[mid]) SWAP(list[left], list[mid], temp);
	if (list[mid] > list[right]) SWAP(list[mid], list[right], temp);
	if (list[left] > list[mid]) SWAP(list[left], list[mid], temp);

	pivot = list[mid];

	low = left + 1;
	high = right - 1;

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
	int number[MAX_SIZE] = { 4,5,8,2,10,14,32,19,43,3 };

	quick_sort(number, 0, 9);

	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", number[i]);

	return 0;
}
*/


