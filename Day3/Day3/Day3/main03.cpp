#include <iostream>

using namespace std;

void main()
{
	srand(time(NULL));

	int choice;

	int huchoi;


	while (1) 
	{
		cout << "�ȳ������� ����������! (0: ���α׷� ����, 1: ����, 2: ����, 3: ��) ";
		cin >> huchoi;

		if (huchoi == 0)
			break;

		choice = rand() % 3;
		if (choice == 0)
		{
			cout << "��ǻ�ʹ� ���� ��" << endl;

			if (huchoi == 1)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (huchoi == 2)
				cout << "�����Դϴ�. �����ϴ�." << endl;

			else if (huchoi == 3)
				cout << "�ƽ����ϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;

		}
		if (choice == 1)
		{
			cout << "��ǻ�ʹ� ������ ��" << endl;

			if (huchoi == 1)
				cout << "�����Դϴ�. �����ϴ�." << endl;

			else if (huchoi == 2)
				cout << "�ƽ����ϴ�. �����ϴ�." << endl;

			else if (huchoi == 3)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else
				cout << "�ȹٷ� �Է����ּ���" << endl;

		}
		if (choice == 2)
		{
			cout << "��ǻ�ʹ� ������ ��" << endl;

			if (huchoi == 1)
				cout << "�ƽ����ϴ�. �����ϴ�." << endl;

			else if (huchoi == 2)
				cout << "�����մϴ�. �̰���ϴ�!" << endl;

			else if (huchoi == 3)
				cout << "�����Դϴ�. �����ϴ�." << endl;

			else
				cout << "�ȹٷ� �Է����ּ���" << endl;

		}
	}

}