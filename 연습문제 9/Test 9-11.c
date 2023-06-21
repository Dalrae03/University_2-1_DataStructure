/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
	char todo[100];
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}
// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void)
{
	char s;

	element e1, e2;
	HeapType* heap;

	heap = create(); 	// ���� ����
	init(heap);	// �ʱ�ȭ


	while (1)
	{
		printf("����(i), ����(d): ");
		scanf(" %c", &s);

		if (s == 'i')
		{
			printf("����: ");
			scanf("%s", e1.todo);
			printf("�켱����: ");
			scanf("%d", &e1.key);

			insert_max_heap(heap, e1);
		}

		else if (s == 'd')
		{
			if (heap->heap_size != 0)
			{
				e2 = delete_max_heap(heap);
				printf("���� �켱������ ���� ���� \"%s\" \n", e2.todo);
			}
			else
				break;
		}
	}

	free(heap);
	return 0;
}
*/
