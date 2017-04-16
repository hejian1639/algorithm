// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "utility.h"
#include <malloc.h>

using namespace std;




void MergeArray(int a[], int  an, int b[], int bn, int dest[])
{
	int i = 0, j = 0;
	while (i < an &&  j < bn)
	{
		if (a[i] < b[j])
		{
			dest[i + j] = a[i];
			++i;
		}
		else
		{
			dest[i + j] = b[j];
			++j;

		}
	}
	if (i < an)
	{
		memcpy(dest + i + j, a + i, (an - i) * sizeof(int));

	}
	if (j < bn)
	{
		memcpy(dest + i + j, b + j, (bn - j) * sizeof(int));

	}
}

void MergeSort(int a[], int n)
{
	int* origin = a;
	int* copy = (int*)_alloca(sizeof(int)*n);

	for (int step = 1; step < n; step *= 2)
	{
		for (int j = 0; j < n; j += 2*step)
		{
			if (j + step > n)
			{
				break;
			}
			else if (j + 2*step > n)
			{
				MergeArray(origin + j, step, origin + j + step, n - j - step, copy + j);

			}
			else
			{
				MergeArray(origin + j, step, origin + j + step, step, copy + j);

			}
		}
		swap(origin, copy);
		print(origin, n, 100);
	}
	if (origin != a)
	{
		memcpy(a, origin, n*sizeof(int));
	}
}


