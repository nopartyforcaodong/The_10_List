#pragma once
#include "tool.h"
#include "Insert_Sort.h"
//表排序适用于待排元素非常多，不利于移动的时候,为了适应统一接口，这里仍对数据做交换


template<typename T>
void TableS(T list[], T table[], int size) {
    //把table中元素置位
    Insert_SortforTable(table, list, size);
    for (int i = 0; i < size; i++)
    {
        T temp = list[i];
        int j = i;
        while (table[j] != j) {
            list[j] = list[table[j]];   // 把实际该置于j位置的元素置于J
            int NextIndex = table[j];   //  记录下一个元素的位置
            table[j] = j;
            j = NextIndex;          // 让j跳到下一个元素
        }
        if (list[j] != temp) // 说明该环不止一个元素，需要进行temp的赋值
            list[j] = temp;
    }
}

template<typename T>
void Table_Sort(T list[], int size) {
    try{
        T* table = new T[size];
        for (int i = 0; i < size; i++) *(table + i) = i;
        TableS(list, table, size);
        delete[] table;

    }
    catch (bad_alloc)
    {
        cout << "空间不足！" << endl;
    }

    }
