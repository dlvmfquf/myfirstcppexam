#include <iostream>
#define SIZE 10

using namespace std;
 
void main()
{
	//자료형 변수명[길이] = {};
	int array[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << endl;
	}

	int a = 100;
	int b = 30;
	int temp = 0;
	cout << "바꾸기 전 a = " << a << ", b = " << b << endl;

	temp = a;
	a = b;
	b = temp;
	cout << "바꾼 후 a = " << a << ", b = " << b << endl;
	


}