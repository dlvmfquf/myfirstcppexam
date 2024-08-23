#include <iostream>

using namespace std;

void main()
{
	//반복문. while , do-while
	// continue, break


	//사용법
	//while (조건문) {실행문}
	//조건식이 참이면 실행구문 실행

	//bool isGamePlaying = true;
	//while (isGamePlaying == true)
	//{
	//	cout << "게임을 종료하시겠습니까? (0: 예, 그 외: 아니요) ";

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
		cout << "게임을 종료하시겠습니까? (0: 예, 그 외: 아니요) ";

		int choice;
		cin >> choice;
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}

	for (int i = 1; i >= 1; i++)
	{
		cout << "게임을 종료하시겠습니까? (0: 예, 그 외: 아니요) ";

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