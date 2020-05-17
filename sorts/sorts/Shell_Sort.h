#ifndef SHELL_H
#define SHELL_H
#include "tool.h"

template<typename T>
void Shell_Sort(T list[], int size)
{
	double a = log(size) / log(2);
	for (int D = pow(2,a)-1; D > 0; D /= 2) //希尔增量序列互质
	{
		for (int P = D; P < size; P++) //插入排序
		{
			T temp = list[P]; int i = P;
			for (; i >= D && list[i - D > temp]; i -= D)
				list[i] = list[i - D];
			list[i] = temp;
		}
	}
}









#endif
