#include <iostream>
//#define DEV_MODE
#define SIZE 15

using namespace std;
//�Լ� ���漱��
//������ ���� �б� ������ ������ ���� ������

//�Լ��� ����ȭ �ϴ� �� �߿���

// Ctrl + r + r - �̸��ٲٱ�

void main()
{
#ifdef DEV_MODE

	cout << "����� ��� �Դϴ�."<<endl;


#endif // DEV_MODE

	cout << "����� ��忡 ������� ���ɴϴ�." << endl;
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