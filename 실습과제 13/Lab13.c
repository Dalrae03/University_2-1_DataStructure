#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT 10000
#define max(a,b) (((a > b)) ? a : b)

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;






// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // 새로운 노드를 삽입
}
// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}



// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, int key)
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}





// 높이
int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}

// 개수
/*
int get_height(HeapType* h)
{
	int height = 0;
	height = h->heap_size;

	return height;
}
*/


// 만개 삽입, 20개 삭제, node계수, 높이 계산프로그램 돌리기
int main(void)
{
	element e;
	HeapType* heap;
	TreeNode* root = NULL;

	srand(time(NULL));

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

	for (int i = 0; i < 10000; i++)
	{
		int n;
		n = e.key = rand();
		insert_max_heap(heap, e);
		root = insert_node(root, n);
	}
	
	printf("히프의 개수: %d\n", heap->heap_size);
	printf("히프의 높이: %d\n", get_height(root));


	for (int i = 0; i < 20; i++)
	{
		element de;
		de = delete_max_heap(heap);
		printf("< %d > ", de.key);
	}


	free(heap);
	return 0;
}