#include <iostream>
#define SIZE 10

using namespace std;
 
void main()
{
	//�ڷ��� ������[����] = {};
	int array[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << endl;
	}

	int a = 100;
	int b = 30;
	int temp = 0;
	cout << "�ٲٱ� �� a = " << a << ", b = " << b << endl;

	temp = a;
	a = b;
	b = temp;
	cout << "�ٲ� �� a = " << a << ", b = " << b << endl;
	


}