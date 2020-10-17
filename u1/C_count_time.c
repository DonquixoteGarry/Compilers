////about 编译原理第一章预习作业1
//C程序优化
#include<windows.h>
#include<stdio.h>

//change size here
int N = 300000000;
int a[300000000];

int* b, i;
LARGE_INTEGER start1, start2, end1, end2, step;

void init()
{
	for (i = 0; i < N; i++) a[i] = N * 5;
}

void loop1()
{
	for (i = 0; i < N; i++)
	{
		a[i] = a[i] * 2000;
		a[i] = a[i] / 10000;
	}
}

void loop2()
{
	for (i = 0; i < N; i++)
	{
		*b = *b * 2000;
		*b = *b / 10000;
		b++;
	}
}

int main()
{


	QueryPerformanceFrequency(&step);//获得计时频率

	init();
	QueryPerformanceCounter(&start1);
	loop1();
	QueryPerformanceCounter(&end1);

	init();
	b = a;
	QueryPerformanceCounter(&start2);
	loop2();
	QueryPerformanceCounter(&end2);

	//get result
	double time1 = ((end1.QuadPart - start1.QuadPart) * 1.0 / step.QuadPart);
	double time2 = ((end2.QuadPart - start2.QuadPart) * 1.0 / step.QuadPart);
	printf("\nloop1_runtime: %1f cycle\n", time1);
	printf("\nloop2_runtime: %1f cycle\n", time2);

	if (time1 > time2)
		printf("\nat size of %d , loop2 (using pointer) is quicker.\n\n", N);
	else
		printf("\nat size of %d , loop1 (using array) is quicker.\n\n", N);

	system("pause");
	return 0;

}