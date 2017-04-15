// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "utility.h"

using namespace std;

void ArrayCopy(int src[], int dest[], int n)
{
	for (int i = n - 1; i >= 0; --i)
	{
		dest[i] = src[i];
	}
}

int BinarySearch(int a[], int start, int end, int value)
{
	if (end < start + 2)
	{
		if (value < a[start])
		{
			return start;
		}
		else if (value < a[end])
		{
			return end;

		}
		return end + 1;

	}
	int mid = (start + end) / 2;
	if (value < a[mid])
	{
		return BinarySearch(a, start, mid, value);
	}
	else if (value > a[mid])
	{
		return BinarySearch(a, mid, end, value);
	}
	return mid;
}





void InsertSort(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int value = a[i + 1];
		print(a, n, i+1);
		int position = BinarySearch(a, 0, i, value);
		ArrayCopy(a + position, a + position + 1, i - position + 1);
		a[position] = value;
		print(a, n, position);
		cout << '\n';
	}
}


