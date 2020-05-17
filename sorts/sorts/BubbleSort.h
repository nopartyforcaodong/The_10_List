#ifndef BUBBLE_H
#define BUBBLE_H
#include "tool.h"
template<typename T>
void Bubble_Sort(T list[], int size)
{
	for (int P = size - 1; P >= 0; P--)
	{
		short isSorted = 1;
		for (int i = 0; i < P; i++)
		{
			if (list[i] > list[i + 1]) {
				swap<T>(list[i], list[i + 1]);
				isSorted = 0;
			}
		}
		if (isSorted == 1) break;
	}
}






#endif
