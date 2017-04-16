// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "utility.h"

using namespace std;



void Heapify(int heap[], int n)
{
	while (n > 0)
	{
		int parent = (n + 1) / 2 - 1;
		if (heap[n] > heap[parent])
		{
			swap(heap[n], heap[parent]);
			n = parent;
		}
		else
		{
			break;
		}
	}
}

void HeapAdjust(int heap[], int n)
{
	int i = 0;
	while (i < n)
	{
		int left = (i + 1) * 2 -1;
		int right = (i + 1) * 2;
		if (left >= n)
		{
			break;
		}
		if (right >= n)
		{
			if (heap[i] < heap[left])
			{
				swap(heap[i], heap[left]);

			}
			break;
		}
		if (heap[left] > heap[right])
		{
			if (heap[i] > heap[left])
			{
				break;
			}
			swap(heap[i], heap[left]);
			i = left;
		}
		else
		{
			if (heap[i] > heap[right])
			{
				break;
			}
			swap(heap[i], heap[right]);
			i = right;

		}
	}
}

void MakeHeap(int heap[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		print(heap, n, i);
		Heapify(heap, i);
		print(heap, n, i);
		cout << '\n';
	}

}

void HeapSort(int a[], int n)
{
	MakeHeap(a, n);
	for (int i = 1; i < n; ++i)
	{
		print(a, n, n - i);
		swap(a[0], a[n - i]);
		HeapAdjust(a, n - i);
		print(a, n, n - i);
		cout << '\n';
	}
}


