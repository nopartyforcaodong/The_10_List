#pragma once
#include "tool.h"
#include "Insert_Sort.h"
//�����������ڴ���Ԫ�طǳ��࣬�������ƶ���ʱ��,Ϊ����Ӧͳһ�ӿڣ������Զ�����������


template<typename T>
void TableS(T list[], T table[], int size) {
    //��table��Ԫ����λ
    Insert_SortforTable(table, list, size);
    for (int i = 0; i < size; i++)
    {
        T temp = list[i];
        int j = i;
        while (table[j] != j) {
            list[j] = list[table[j]];   // ��ʵ�ʸ�����jλ�õ�Ԫ������J
            int NextIndex = table[j];   //  ��¼��һ��Ԫ�ص�λ��
            table[j] = j;
            j = NextIndex;          // ��j������һ��Ԫ��
        }
        if (list[j] != temp) // ˵���û���ֹһ��Ԫ�أ���Ҫ����temp�ĸ�ֵ
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
        cout << "�ռ䲻�㣡" << endl;
    }

    }
