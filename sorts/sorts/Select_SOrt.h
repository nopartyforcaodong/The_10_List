#ifndef SELECT_H
#define SELECT_H
#include "tool.h"

template<typename T>
void Select_Sort(T list[], int size)
{
	for (int i = 0; i <size; i--)
	{
		T min = list[0]; int minindex = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (list[j] < min) {
				min = list[j]; minindex = j;
			}
		}
		if (minindex != i)
			swap<T>(list[i], list[minindex]);
	}
}








#endif
