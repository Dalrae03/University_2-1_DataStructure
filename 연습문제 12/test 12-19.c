/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500

int sorted[MAX_SIZE];   // �߰� ������ �ʿ�

// 1 i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
// j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε��� 
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	printf("merge_sort(%d, %d)\n", list[left], list[mid+1]); // �� ���ҹ迭�� ù��° �μ� ���

	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)	// ���� �ִ� ���ڵ��� �ϰ� ���� 
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else	//���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹�� 
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
//
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;     // ����Ʈ�� �յ� ����
		merge_sort(list, left, mid);    // �κ� ����Ʈ ����
		merge_sort(list, mid + 1, right); // �κ� ����Ʈ ���� 
		merge(list, left, mid, right);    // �պ� 
	}
}

int main(void)
{
	int num[8] = { 27,10,12,20,25,13,15,22 };
	
	merge_sort(num, 0, 7);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", num[i]);
	}

	return 0;
}
*/
