#ifndef QUICK_H
#define QUICK_H
#include "tool.h"
#include "Insert_Sort.h"

//快速排序只有在数据规模比较大的时候，才能体现出其‘快速’
//当规模比较小，应该选用其他排序方法
const int Cutoff = 200;

template<typename T>
T Median(T list[], int L, int R)
{
	int Center = (L + R) / 2;
	if (list[L] > list[Center]) swap(list[L], list[Center]);
	if (list[L] > list[R]) swap(list[L], list[R]);
	if (list[Center] > list[R]) swap(list[Center], list[R]);
	//使list[L]<=list[C]<=list[R]
	swap(list[Center], list[R - 1]);
}


template<typename T>
void QuickS(T list[], int L, int R)
{
	if (R - L < Cutoff) {
		Insert_Sort(list, R - L + 1);
		return;
	}
	T pivot = Median(list, L, R);
	int i = L, j = R - 1;
	while (true)
	{
		while (list[++i] < pivot);
		while (list[--j] > pivot);
		if (i < j)
			swap(list[i], list[j]);
		else break;
	}
	swap(list[i], list[R - 1]);//使枢纽复位
	QuickS(list, L, i - 1);
	QuickS(list, i + 1, R);

}







#endif
