// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;



void print(int a[], int n, int highlight);


void InsertSort(int a[], int n);

int main()
{
	int a[] = { 3,1,5,7,2,4,9,6 };
	InsertSort(a, sizeof(a) / sizeof(int));
	print(a, sizeof(a) / sizeof(int), 100);
	return 0;
}

