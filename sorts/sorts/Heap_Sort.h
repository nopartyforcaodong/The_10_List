#pragma once
#include "tool.h"
//��������Ҫ�����ⲿ���ݽṹ��С��


template<typename T>
void HeapAdjust(T list[], int root, int size)
{
	T temp = list[root - 1];
	//iΪroot�����ӣ�
	int i = 2 * root;
	while (i <= size)
	{
		//��iָ�����������д���Ǹ�
		if (i + 1 <= size && list[i] > list[i - 1])i++;
		//���i��ֵ����root��ֵ����i��ֵ����root
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
void Heap_Sort(T list[], int size)//�������±��1��ʼ���㣬���Զ������ĸ������Ϊroot=1������ֵ��s1->data[root-1];(��Ϊ�����±��0��ʼ)��
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
	

