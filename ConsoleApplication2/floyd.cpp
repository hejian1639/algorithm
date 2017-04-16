// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "utility.h"

using namespace std;





const int map_size = 6;

void Floyd(int map[][map_size])
{
    int shortDistance[map_size][map_size]= { 0};
    for (int i = 0; i < map_size; ++i)
	{
		for (int j = 0; j < map_size; ++j)
		{
				shortDistance[i][j] = map[i][j];

		}
	}

    int path[map_size][map_size] = {0};

	for(int k =0 ; k < map_size; ++k)
	{
		for(int i = 0; i < map_size; ++i)
		{
			for (int j = 0; j < map_size; ++j)
			{
				if (shortDistance[i][j] > shortDistance[i][k] + shortDistance[k][j])
				{
					shortDistance[i][j] = shortDistance[i][k] + shortDistance[k][j];
					if(shortDistance[k][j] == map[k][j])
					{
						path[i][j] = k+1;
					}
					else
					{
						path[i][j] = path[k][j];
					}
				}
			}
		}
		//print(shortDistance, map_size);
		//print(path, map_size);
	}
    print(shortDistance, map_size);
    print(path, map_size);
}


