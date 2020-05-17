#ifndef QUICK_H
#define QUICK_H
#include "tool.h"
#include "Insert_Sort.h"

//��������ֻ�������ݹ�ģ�Ƚϴ��ʱ�򣬲������ֳ��䡮���١�
//����ģ�Ƚ�С��Ӧ��ѡ���������򷽷�
const int Cutoff = 200;

template<typename T>
T Median(T list[], int L, int R)
{
	int Center = (L + R) / 2;
	if (list[L] > list[Center]) swap(list[L], list[Center]);
	if (list[L] > list[R]) swap(list[L], list[R]);
	if (list[Center] > list[R]) swap(list[Center], list[R]);
	//ʹlist[L]<=list[C]<=list[R]
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
	swap(list[i], list[R - 1]);//ʹ��Ŧ��λ
	QuickS(list, L, i - 1);
	QuickS(list, i + 1, R);

}







#endif
