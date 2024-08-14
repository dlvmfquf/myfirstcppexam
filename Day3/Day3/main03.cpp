#include <iostream>

using namespace std;

void main()
{
	srand(time(NULL));

	int choice;

	int huchoi;


	while (1) 
	{
		cout << "안내면진다 가위바위보! (0: 프로그램 종료, 1: 가위, 2: 바위, 3: 보) ";
		cin >> huchoi;

		if (huchoi == 0)
			break;

		choice = rand() % 3;
		if (choice == 0)
		{
			cout << "컴퓨터는 보를 냄" << endl;

			if (huchoi == 1)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (huchoi == 2)
				cout << "유감입니다. 졌습니다." << endl;

			else if (huchoi == 3)
				cout << "아쉽습니다. 비겼습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;

		}
		if (choice == 1)
		{
			cout << "컴퓨터는 바위를 냄" << endl;

			if (huchoi == 1)
				cout << "유감입니다. 졌습니다." << endl;

			else if (huchoi == 2)
				cout << "아쉽습니다. 비겼습니다." << endl;

			else if (huchoi == 3)
				cout << "축하합니다 이겼습니다!" << endl;

			else
				cout << "똑바로 입력해주세요" << endl;

		}
		if (choice == 2)
		{
			cout << "컴퓨터는 가위를 냄" << endl;

			if (huchoi == 1)
				cout << "아쉽습니다. 비겼습니다." << endl;

			else if (huchoi == 2)
				cout << "축하합니다. 이겼습니다!" << endl;

			else if (huchoi == 3)
				cout << "유감입니다. 졌습니다." << endl;

			else
				cout << "똑바로 입력해주세요" << endl;

		}
	}

}