#pragma once
#include "tool.h"
//堆排序需要借助外部数据结构最小堆


template<typename T>
void HeapAdjust(T list[], int root, int size)
{
	T temp = list[root - 1];
	//i为root的左孩子；
	int i = 2 * root;
	while (i <= size)
	{
		//将i指向两个孩子中大的那个
		if (i + 1 <= size && list[i] > list[i - 1])i++;
		//如果i的值大于root的值，则将i的值赋给root
		if (list[i] > temp)
		{
			list[root - 1] = list[i - 1];
			root = i;
			i *= 2;
		}
		else break;
	}
	list[root - 1] = temp;
}


template<typename T>
void Heap_Sort(T list[], int size)//堆排序下标从1开始方便，所以定义树的根的序号为root=1，根的值是s1->data[root-1];(因为数组下标从0开始)；
{
	for (int i = size/ 2; i > 0; i--)
	{
		HeapAdjust(list, i, size);
	}
	swap(list[0], list[size - 1]);
	for (int j = size- 2; j > 0; j--)
	{
		HeapAdjust(list, 1, j + 1);
		Swap(list[0], list[j]);
	}
}
	

