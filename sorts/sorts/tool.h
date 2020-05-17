#ifndef TOOL_H
#define TOOL_H

#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = a;
}

#endif