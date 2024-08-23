#include <iostream>
//#define DEV_MODE
#define SIZE 15

using namespace std;
//함수 전방선언
//위에서 부터 읽기 때문에 위에서 먼저 선언함

//함수는 세분화 하는 게 중요함

// Ctrl + r + r - 이름바꾸기

void main()
{
#ifdef DEV_MODE

	cout << "디버깅 모드 입니다."<<endl;


#endif // DEV_MODE

	cout << "디버깅 모드에 상관없이 나옵니다." << endl;
	cout << SIZE<<endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j >= i)
			{
				cout << "*";
			}
		}
		cout << endl;
	}



	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= 4 -j)
			{
				cout << "*";
			}
			else 
			{
				cout << " ";
			}
		}
		cout << endl;
	}

}