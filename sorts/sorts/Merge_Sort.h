#ifndef MERGE_H
#define MERGE_H
#include "tool.h"

template<typename T>
void Merge(T list[], T temp[],int L,int R,int REnd)
{
	int LEnd = R - 1;//假设归并的左右两列紧挨着，表左终点位置
	int primary = L;
	int Size = REnd - L + 1;
	while (L <= LEnd && R <= REnd){
		if (list[L] <= list[R])
			temp[primary++] = list[L++];
		else temp[primary++] = list[R++];
	}
	while(L<=LEnd) 	temp[primary++] = list[L++];
	while(R<REnd)   temp[primary++] = list[R++];//直接复制左右两边剩下的元素
	for (int i = 0; i < Size; i++, REnd--)
		list[REnd] = temp[REnd];
}

template<typename T>
void MSort(T list[], T temp[], int L, int REnd)
{
	int Center;
	if (L<REnd)
	{
		Center = (L + REnd) / 2;
		MSort(list, temp, L, Center);
		MSort(list, temp, Center + 1, REnd);
		Merge(list, temp, L, Center + 1, REnd);
	}
}


template<typename T>
void Merge_Sort(T list[], int size)
{
	try{
		T* temp= new int[size];
		MSort(list, temp, 0, size - 1);
		delete[] temp;

	}
	catch (bad_alloc){
		cout << "空间不足！" << endl;
	}

}

#endif
