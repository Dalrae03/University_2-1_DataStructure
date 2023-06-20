#include <stdio.h>
#include <time.h>

/*
double factorial(int n) // 팩토리얼 순환적 구성
{
	if (n <= 1)
		return 1;
	else
		return(n * factorial(n - 1));
}

int factorial_iter(int n) // 팩토리얼 반복적 구성
{
	int k, v = 1;
	for (k = n; k > 0; k--)
		v = v * k;
	return v;
}

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

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)
		printf("원판 1을 %c에서 %c으로 옮긴다. \n", from, to);
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다. \n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
*/

// (1) ~ (3) 과제
/*
int main(void)
{
	int N = 45;

	//printf("%d\n", factorial(N));
	//printf("%d\n", factorial_iter(N));
	printf("%d\n", fib(N));
	//printf("%d\n", fib_iter(N));
	// hanoi_tower(6, 'A', 'B', 'C');

	return 0;
}
*/


// 실습과제 4 - 1
/*
int factorial(int n) // 팩토리얼 순환적 구성, fact결합
{
	if (n <= 1)
	{
		printf("%d\n", n);
		printf("1\n");
		return 1;
	}
	else
	{
		printf("%d\n", n);
		printf("%d * factorial(%d - 1)\n", n, n);
		return (n * factorial(n - 1));
	}
}
*/

/*
int main(void)
{
	printf("팩토리얼 값: %lf", factorial(20));
	//printf("팩토리얼 값: %d", factorial_iter(12));

	return 0;
}
*/

/*
int fib(int n) // 피보나치 수열 순환적 구성, fact결합
{
	if (n == 0)
	{
		printf("%d\n", n);
		printf("fid(0) = 0\n");
		return 0;
	}
	if (n == 1)
	{
		printf("%d\n", n);
		printf("fid(1) = 1\n");
		return 1;
	}

	printf("%d\n", n);
	printf("fib(%d - 1) + fib(%d - 2)\n", n, n);
	return (fib(n - 1) + fib(n - 2));
}
*/

/*
int main(void)
{
	printf("피보나치 6의 값: %d", fib(6));
	return 0;
}
*/
// 총 50줄






/*
void asterisk(int i)
{
	if (i > 1)
	{
		asterisk(i / 2);
		asterisk(i / 2);
	}
	printf("*");
}

int main(void)
{
	asterisk(5);
	return 0;
}
*/

/*
double sumall(int n)
{
	if (n == 1)
		return 1;
	else
		return((double)1 / n + sumall(n - 1));
}

int main(void)
{
	printf("%lf", sumall(5));
	return 0;
}
*/

/*
int fib_1(int n)
{
	printf("fib(%d) is called\n", n);
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return(fib_1(n - 1) + fib_1(n - 2));
}
*/

/*
int sum(int n)
{
	int result = 0;

	for (int i = n; i > 0; i--)
		result += i;

	return result;
}
*/

/*
int confficient(int n, int k) // 순환구조
{
	if (k == 0 || k == n)
		return 1;
	else
		return(confficient(n - 1, k - 1) + confficient(n - 1, k));
}
*/

/*
int confficient(int n, int k) // 반복구조
{
	int a = 1, b = 1;
	for (int i = 0; i < k; i++)
		a *= (n - 1);
	for (int i = k; i > 0; i--)
		b *= i;
	return a / b;
}

int main(void)
{
	printf("%d", confficient(5, 2));
	return 0;
}
*/

