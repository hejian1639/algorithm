// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <iostream>

unsigned short SetConsoleColor(unsigned short ForeColor, unsigned short BackGroundColor);

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

void print(int a[], int n, int highlight);

const int MAX = 0x0FFFFFFF;

template<int N>
void print(int m[][N], int n) {
	for (int i = 0; i < n; i++)
	{
			cout << "{ ";
		for (int j = 0; j < n; j++)
		{
			if(m[i][j] == MAX)
			{
				cout << "MAX,";
			}
			else
			{
				cout << m[i][j] << ",";

			}
				cout << "\t";
		}
		cout << "}\n";

	}
	cout << '\n';
}
