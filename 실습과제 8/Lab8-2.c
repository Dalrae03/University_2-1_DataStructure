#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 500000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list1[MAX_SIZE];
int list2[MAX_SIZE];
int n;

// ������
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


// ���� Ž��
int search_binary2(int key, int low, int high, int list[])
{
	int middle;

	while (low <= high) {       // ���� ���ڵ��� ���� ������
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;   // �߰ߵ��� ���� 
}


// ����Ž��
int seq_search(int key, int low, int high, int list[])
{
	int i;

	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;  // Ž���� �����ϸ� Ű ���� �ε��� ��ȯ 
	return -1;    // Ž���� �����ϸ� -1 ��ȯ 
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
	for (int o = 0; o < 100000; o++) //10���� �ݺ�
		seq_search(key, 0, n, list1);
	stop = clock();
	duration1 = (double)(stop - start) / CLOCKS_PER_SEC;
	//printf("�ε���: %d\n", a);


	start = clock();
	for (int o = 0; o < 100000; o++) //10���� �ݺ�
		search_binary2(key, 0, n, list2);
	stop = clock();
	duration2 = (double)(stop - start) / CLOCKS_PER_SEC;
	//printf("�ε���: %d\n", b);

	printf("����Ž�� ����ð� %f \n", duration1);
	printf("����Ž�� ����ð� %f \n", duration2);

	return 0;
}




/*
for (i = 0; i < n; i++)
		printf("%d ", list2[i]);
	printf("\n");
*/