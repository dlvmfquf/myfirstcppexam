#include <iostream>

using namespace std;

void main()
{
	//왼쪽 아래 직각 삼각형
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	//왼쪽 위 직각 삼각형
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	//피라미드
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = i; j < 4; j++)
		{
			cout << " ";
		}
		for (int k = 0; k <= (i*2); k++)
		{
			cout << "*";
		}
		cout << endl;;
		
	}

	cout << endl;

	//오른쪽 아래 직각 삼각형
	for (int i = 0; i < 5; i++)
	{

		for (int j = i; j < 5; j++)
		{
			cout << " ";
		}
		for (int k = 0; k <= i; k++)
		{
			cout << "*";
		}
		cout << endl;;

	}

	cout << endl;
	
	//오른쪽 위 직각 삼각형
	for (int i = 0; i < 5; i++)
	{

		for (int k = 0; k <= i; k++)
		{
			cout << " ";
		}

		for (int j = i; j < 5; j++)
		{
			cout << "*";
		}
		
		cout << endl;;
	}

}