#include <iostream>

using namespace std;


int comNumber[3] = {};
int playerNumber = 0;
int breakedPlayerNumber[3] = {};
int strike = 0;
int ball = 0;


void ShuffleComNumber()
{
	srand(time(NULL));
	while (1)
	{
		comNumber[0] = 1 + (rand() % 9);
		comNumber[1] = 1 + (rand() % 9);
		comNumber[2] = 1 + (rand() % 9);

		if (comNumber[0] != comNumber[1] && comNumber[1] != comNumber[2] && comNumber[0] != comNumber[2])
			break;
	}

}

void BreakPlayerNumber()
{
	breakedPlayerNumber[0] = playerNumber / 100;
	breakedPlayerNumber[1] = (playerNumber % 100 - (playerNumber % 10)) / 10;
	breakedPlayerNumber[2] = playerNumber % 10;
}

void CountStrike()
{
	for (int i = 0; i < 3; i++)
	{
		if (breakedPlayerNumber[i] == comNumber[i])
		{
			strike++;
		}
	}
}
void CountBall()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != j && (breakedPlayerNumber[i] == comNumber[j] || breakedPlayerNumber[j] == comNumber[j]))
			{
				ball++;
			}
		}
	}


}

void main()
{

	/*for (int i = 0; i < 3; i++) 
	{
		cout << breakedPlayerNumber[i] << endl;
	}*/

	while (1)
	{
		cout << "숫자야구를 시작합니다! 겹치지 않는 숫자로 3자리 수를 입력해주세요(종료: 999)" << endl;
		cin >> playerNumber;
		ShuffleComNumber();
		BreakPlayerNumber();
		CountBall();
		CountStrike();

		if (playerNumber == 999)
			break;

		if (playerNumber > 999 || playerNumber <= 100)
		{
			cout << "겹치지 않는 숫자로 3자리 수를 입력해주세요" << endl;
			strike = 0;
			ball = 0;
		}
		else
		{

			if (strike == 3)
			{
				cout << "컴퓨터가 선택한 숫자: " << comNumber[0] << comNumber[1] << comNumber[2] << endl;
				cout << "플레이어가 선택한 숫자: " << playerNumber << endl;
				cout << "결과: " << strike << "strike, " << ball << "ball" << endl;
				cout << "축하합니다 승리하셨습니다." << endl;
				break;
			}
			else
			{
				cout << "컴퓨터가 선택한 숫자: " << comNumber[0] << comNumber[1] << comNumber[2] << endl;
				cout << "플레이어가 선택한 숫자: " << playerNumber << endl;
				cout << "결과: " << strike << "strike, " << ball << "ball" << endl;
				strike = 0;
				ball = 0;
			}
		}

	}
	
}
