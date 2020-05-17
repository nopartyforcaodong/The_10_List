#ifndef INSERT_H
#define INSERT_H
#include "tool.h"

template<typename T>
void Insert_Sort(T list[], int size)
{
	
	for (int P = 1; P < size; P++)
	{
		T temp = list[P]; int i = P;
		for (; i > 0 && list[i - 1] > temp; i--)
			list[i] = list[i - 1];  //��λ
		list[i] = temp; //����
	}
}

template<typename T>
void Insert_SortforTable(T table[],T list[], int size)
{

	for (int P = 1; P < size; P++)
	{
		T temp = list[table[P]]; int i = P;
		for (; i > 0 && list[table[i - 1]] > temp; i--)
			table[i] = table[i - 1];  //��λ
		table[i] = P; //����
	}
}






#endif
