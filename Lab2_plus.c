#include <stdio.h>
#include <time.h>


int fib(int n) // 피보나치 수열 순환적 구성 
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (fib(n - 1) + fib(n - 2));
}



int fib_iter(int n) // 피보나치 수열 반복적 구성
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


// 순환적 구성 실행시간 구하기

int main(void)
{
	double start, stop;

	start = clock();
	printf("피보나치 값: %d\n", fib(30));
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);


	return 0;
}


// 반복적 구성 실행시간 구하기
/*
int main(void)
{
	double start, stop;

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		fib_iter(30);
		if (i == 99999)
			printf("피보나치 값: %d\n", fib_iter(30));
	}
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);


	return 0;
}
*/

// 순환적 구성 최댓값 구하기 + 시간
/*
int main(void)
{
	double start, stop;

	start = clock();
	printf("피보나치 값: %d\n", fib(46));
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);

	return 0;
}
*/

// 반복적 구성 최댓값 구하기 + 시간
/*
int main(void)
{
	double start, stop;

	start = clock();
	for (int i = 0; i < 100000; i++)
	{
		fib_iter(30);
		if (i == 99999)
			printf("피보나치 값: %d\n", fib_iter(46));
	}
	stop = clock();
	double duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("%lf", duration);

	return 0;
}
*/