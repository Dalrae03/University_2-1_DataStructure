#include <stdio.h>
#include <stdlib.h>
/*
void insert(int array[], int loc, int value)
{
	int a, b;
	int items = 8;


	for (int i = 0; i < 101; i++)
	{
		if (array[i] != 0)
			items += 1;
		else
			break;
	}

	a = array[loc];
	b = array[loc + 1];
	array[loc] = value;
	array[loc + 1] = a;

	for (int i = loc + 2; i < items; i += 2)
	{
		a = array[i];
		array[i] = b;
		b = array[i + 1];
		array[i + 1] = a;
	}
	
	a = array[items];
	array[items] = b;



	// 거꾸로 가는 방법도 생각해봐야했어...
	for (int i = items - 1; i >= loc; i--)
	{
		array[i + 1] = array[i];
	}
	array[loc] = value;

	return 0;
}

int main(void)
{
	int array[101] = { 4,5,10,16,12,20,50,45 };
	int l = 2;
	int v = 11;

	for (int i = 0; i < 101; i++)
	{
		if (array[i] != 0)
			printf("%d ", array[i]);
		else
			break;
	}

	printf("\n");

	insert(array, l, v);

	for (int i = 0; i < 101; i++)
	{
		if (array[i] != 0)
			printf("%d ", array[i]);
		else
			break;
	}
	return 0;
}

*/

/*
void delete(int array[], int loc)
{
	int a, b;
	int items = 8;

	for (int i = loc; i < items - 1; i++)
		array[i] = array[i + 1];
	array[items - 1] = 0;
	items--;

	return 0;
}



int main(void)
{
	int array[101] = { 4,5,10,16,12,20,50,45 };
	int l = 2;

	for (int i = 0; i < 101; i++)
	{
		if (array[i] != 0)
			printf("%d ", array[i]);
		else
			break;
	}

	printf("\n");

	delete(array, l);

	for (int i = 0; i < 101; i++)
	{
		if (array[i] != 0)
			printf("%d ", array[i]);
		else
			break;
	}

	return 0;
}
*/

int main(void)
{
	typedef struct {
		int a;
		char str[21];
	}block;

	block* p;
	p = (block *)calloc(1, sizeof(block));

	if (p == NULL)
	{
		printf("동적 메모리 할당 오류");
		exit(1);
	}
	
	p[0].a = 100;
	strcpy(p[0].str, "just testing");

	free(p);

	return 0;
}