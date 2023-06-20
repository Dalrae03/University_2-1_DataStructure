#include <stdio.h>
#include <time.h>


int fib(int n) // �Ǻ���ġ ���� ��ȯ�� ���� 
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (fib(n - 1) + fib(n - 2));
}



int fib_iter(int n) // �Ǻ���ġ ���� �ݺ��� ����
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}


// ��ȯ�� ���� ����ð� ���ϱ�

int main(void)
{
	double start, stop;

	start = clock();
	printf("�Ǻ���ġ ��: %d\n", fib(30));
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);


	return 0;
}


// �ݺ��� ���� ����ð� ���ϱ�
/*
int main(void)
{
	double start, stop;

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		fib_iter(30);
		if (i == 99999)
			printf("�Ǻ���ġ ��: %d\n", fib_iter(30));
	}
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);


	return 0;
}
*/

// ��ȯ�� ���� �ִ� ���ϱ� + �ð�
/*
int main(void)
{
	double start, stop;

	start = clock();
	printf("�Ǻ���ġ ��: %d\n", fib(46));
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);

	return 0;
}
*/

// �ݺ��� ���� �ִ� ���ϱ� + �ð�
/*
int main(void)
{
	double start, stop;

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		fib_iter(30);
		if (i == 99999)
			printf("�Ǻ���ġ ��: %d\n", fib_iter(46));
	}
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);

	return 0;
}
*/