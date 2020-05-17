#include "Test_Gather.cpp"

int main()
{
	int Size;
	cout << "please enter the size of array: ";
	cin >> Size;
	int* list = new int[Size];
	cout << "Enter" << Size << "values(integer)" << endl;
	for (int i = 0; i < Size; i++) cin >> list[i];
}