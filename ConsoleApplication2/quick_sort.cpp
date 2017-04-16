// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "utility.h"

using namespace std;




int Partition(int a[], int n)
{
	int mid = a[0];
	int start = 0;
	int end = n -1;
	bool forward = true;
	while(end > start)
	{
		if(forward)
		{
			if(a[start+1]<mid)
			{
				a[start] = a[start+1];
				++start;
			}
			else
			{
				forward = false;
			}
		}
		else
		{
			if(a[end]>mid)
			{
				--end;
			}
			else
			{
				a[start]=a[end];
				a[end]=a[start+1];
				++start;
				forward = true;
			}

		}
	}
	a[start] = mid;
	return start;
}

void QuickSort(int a[], int n)
{
	if(n < 2)
	{
		return;
	}
	int mid = Partition(a, n);
	print(a, n, mid);
	QuickSort(a, mid);
	QuickSort(a + mid+1, n-mid-1);


}


