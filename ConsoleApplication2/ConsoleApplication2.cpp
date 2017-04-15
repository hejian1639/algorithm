// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>

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


unsigned short SetConsoleColor(unsigned short ForeColor, unsigned short BackGroundColor)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo))
	{
		printf("GetConsoleScreenBufferInfo error!\n");
		return 0;
	}
	if (!SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ForeColor | BackGroundColor))
	{
		printf("SetConsoleTextAttribute error!\n");
		return 0;
	}
	return csbiInfo.wAttributes;
}

inline std::ostream&  red(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_RED, 0);
	return ostr;
}

inline std::ostream&  white(std::ostream& ostr)
{
	SetConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE, 0);
	return ostr;
}

void print(int a[], int n, int highlight) {
	for (int j = 0; j < n; j++) 
	{
		if (j == highlight)
		{
			cout << red << a[j] << " ";
		}
		else
		{
			cout << white << a[j] << " ";
		}

	}
	cout << endl;
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

int main()
{
	int a[] = { 3,1,5,7,2,4,9,6 };
	InsertSort(a, sizeof(a) / sizeof(int));
	print(a, sizeof(a) / sizeof(int), 100);
	return 0;
}

