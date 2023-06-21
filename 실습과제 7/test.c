#include <stdio.h>
#include <stdlib.h>

int rfact(int n) {
	int f;
	printf("n=%d \n", n);
	if (n == 1)
		f = 1;
	else
		f = n * rfact(n - 1);
	printf("%d != %d \n", n, f);
	return f;
}

void main() {
	int k, r;
	k = 4;
	r = rfact(k);
	printf("Factorial of %d = %d \n", k, r);
}