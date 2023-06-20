#include <stdio.h>
#include <time.h>

int main(void) 
{
	int students[30] = { 10, 30, 80, 33, 40, 77, 90, 80, 40, 50, 55, 80, 86, 78, 20, 74, 64, 67, 92, 11, 34, 80, 70, 15, 29, 64, 58, 73, 46, 8 };
	int maxnum, all, j;
	float average = 0;
	double start, stop;

	maxnum = students[0];
	all = students[0];
	j = 0;

	start = clock();
	while (j < 100000)
	{
		for (int i = 1; i < 30; i++) {
			all += students[i];
			if (maxnum < students[i])
				maxnum = students[i];
		};

		average = all / 30;
		
		if (j == 0)
			printf("최대값: %d, 평균: %f \n", maxnum, average);

		j += 1;
	}
	stop = clock();

	double duration = (double)(stop - start) / CLOCKS_PER_SEC;

	printf("실행시간: %lf \n", duration);
	printf("실제 실행시간은 %lf / 100000", duration);

	return 0;
}