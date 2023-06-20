#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MAX_DEGREE 101 // 다항식의 최대차수 + 1
#define MAX_TERMS 101

// 다항식 덧셈 프로그램 1번째
/*
typedef struct {
	int degree; //차수
	float coef[MAX_DEGREE];
}polynomial;


// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다.
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C; // 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b)
		{ // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}

		else if (degree_a == degree_b)
		{ // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}

		else
		{ // B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f\n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("------------------------------------------------------------------------------------\n");
	print_poly(c);

	return 0;
}
*/


// 다항식 덧셈 프로그램 2번째
/*
typedef struct {
	float coef;
	int expon;
}polynomial;

polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int avail = 6;

// 두개의 정수를 비교
char compare(int a, int b)
{
	if (a > b)
		return'>';
	else if (a == b)
		return '=';
	else
		return '<';
}

// 새로운 항을 A, B가 들어있는 기존 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		printf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be)
	{
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
		case'>': // A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++;

		case '=': // A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++;
			Bs++;
			break;

		case '<': // A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
			break;
		}
	}
	// A의 나머지 항들을 이동함
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	// B의 나머지 항들을 이동함
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1f \n", terms[e].coef, terms[e].expon); // 더하기 출력하지않기위해 마지막수는 따로 빼줌
}


int main(void)
{
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------------------------------------------------------------------\n");
	print_poly(Cs, Ce);

	return 0;
}
*/



// (1)sub_poly()
/*
typedef struct {
	int degree; //차수
	float coef[MAX_DEGREE];
}polynomial;

polynomial sub_poly(polynomial A, polynomial B)
{
	polynomial C; // 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수
	while (Apos <= A.degree && Bpos <= B.degree)
	{
		if (degree_a > degree_b)
		{ // A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}

		else if (degree_a == degree_b)
		{ // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}

		else
		{ // B항 > A항
			C.coef[Cpos++] = - B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		if (p.coef[p.degree - i] != 0)
			printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	if(p.coef[p.degree] != 0)
		printf("%3.1f\n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a = { 5,{8,0,0,2,1,10} };
	polynomial b = { 5,{0,9,0,5,0,11} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = sub_poly(a, b);
	printf("------------------------------------------------------------------------------------\n");
	print_poly(c);

	return 0;
}
*/


// (4)print_poly() 수정
/*
void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		if (p.coef[p.degree - i] != 0)
			printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	if(p.coef[p.degree] != 0)
		printf("%3.1f\n", p.coef[p.degree]);
}
*/



// (2)multi_poly()
/*
typedef struct {
	int degree; //차수
	float coef[MAX_DEGREE];
}polynomial;


polynomial multi_poly(polynomial A, polynomial B)
{
	polynomial C; // 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = A.degree + B.degree; // 결과 다항식 차수 최대차항


	for (int i = 0; i < C.degree + 1; i++)
		C.coef[i] = 0;


	for (int i = 0; i < degree_a + 1; i++)
		for (int j = 0; j < degree_b + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];

	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f\n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a = { 2,{2,1,10} };
	polynomial b = { 3,{3,0,-1,1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = multi_poly(a, b);
	printf("------------------------------------------------------------------------------------\n");
	print_poly(c);

	return 0;
}
*/


// (3)trim_poly()
/*
typedef struct {
	int degree; //차수
	float coef[MAX_DEGREE];
}polynomial;

void trim_poly(polynomial* p) // 변수의 원본이 함수에 간다.
{
	int s = 0;
	int N = p->degree;

	for (int i = 0; i < N+1; i++)
	{
		if (p->coef[i] != 0)
		{
			s = i;
			break;
		}
	}

	for (int i = N-s; i > 0; i--)
		printf("%3.1fx^%d + ", p->coef[N-i], i);
	printf("%3.1f\n", p->coef[p->degree]);
		
}


int main(void)
{
	polynomial a = { 5,{0,9,0,5,0,11} };
	trim_poly(&a);

	return 0;
}
*/