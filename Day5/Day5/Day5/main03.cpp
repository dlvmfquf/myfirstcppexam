#include <iostream>

using namespace std;

void main()
{
	//�ݺ���. while , do-while
	// continue, break


	//����
	//while (���ǹ�) {���๮}
	//���ǽ��� ���̸� ���౸�� ����

	//bool isGamePlaying = true;
	//while (isGamePlaying == true)
	//{
	//	cout << "������ �����Ͻðڽ��ϱ�? (0: ��, �� ��: �ƴϿ�) ";

	//	int choice;
	//	cin >> choice;
	//	if (choice == 0)
	//	{
	//		isGamePlaying = false;
	//	}
	//}


	bool isGamePlaying = true;
	for (;isGamePlaying;)
	{
		cout << "������ �����Ͻðڽ��ϱ�? (0: ��, �� ��: �ƴϿ�) ";

		int choice;
		cin >> choice;
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}

	for (int i = 1; i >= 1; i++)
	{
		cout << "������ �����Ͻðڽ��ϱ�? (0: ��, �� ��: �ƴϿ�) ";

		int choice;
		cin >> choice;
		if (choice == 0)
		{
			i *= -1;
		}
	}


	int j = 0;
	while (j < 10)
	{
		cout << j << endl;
		j++;
	}


}