#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list1[MAX_SIZE];
int list2[MAX_SIZE];
int n;

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


// 이진 탐색
int search_binary2(int key, int low, int high, int list[])
{
	int middle;

	while (low <= high) {       // 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;   // 발견되지 않음 
}


// 순차탐색
int seq_search(int key, int low, int high, int list[])
{
	int i;

	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;  // 탐색에 성공하면 키 값의 인덱스 반환 
	return -1;    // 탐색에 실패하면 -1 반환 
}


int main(void)
{
	int i, a, b;
	clock_t start, stop;
	double duration1, duration2;

	n = MAX_SIZE;
	srand(time(NULL));

	int key = rand();
	//printf("%d\n", key);

	for (i = 0; i < n; i++)
		list1[i] = list2[i] = rand();

	quick_sort(list2, 0, n - 1);
	

	start = clock();
	for (int o = 0; o < 100000; o++) //10만번 반복
		seq_search(key, 0, n, list1);
	stop = clock();
	duration1 = (double)(stop - start) / CLOCKS_PER_SEC;
	//printf("인덱스: %d\n", a);


	start = clock();
	for (int o = 0; o < 100000; o++) //10만번 반복
		search_binary2(key, 0, n, list2);
	stop = clock();
	duration2 = (double)(stop - start) / CLOCKS_PER_SEC;
	//printf("인덱스: %d\n", b);

	printf("순차탐색 수행시간 %f \n", duration1);
	printf("이차탐색 수행시간 %f \n", duration2);

	return 0;
}




/*
for (i = 0; i < n; i++)
		printf("%d ", list2[i]);
	printf("\n");
*/