//숙제3.
//스네이크게임 
// 기존게임과 달리 (사용자가 입력해야만 게임 진행)
// 리얼타임 게임

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void UpdateGame();
void GotoXY(int x, int y);

void main()
{
	//현재 시간을 기억한다
	int oldGameTime = ::GetTickCount64();
	// GetTickCount64 게임이 진행되고 몇ms가 지났는가?

	while (true)
	{
		//현재 게임시간을 받아온다.
		int currentGameTime = ::GetTickCount64();

		//현재시간 - 옛날시간
		if (300 < currentGameTime - oldGameTime)
		{
			UpdateGame();
			oldGameTime = currentGameTime;
		}
	}

	while (true)
	{

		if (_kbhit())	//키보드를 눌렀다면
		{
			char inputkey = _getch();	//누른값을 inputkey에 담겠다.
			GotoXY(3, 2 + choice);
			cout << "ㅤㅤ";	//기존거를 지워주고
			if (inputkey == 's')
			{
				choice++;
			}
			else if (inputkey == 'w')
			{
				choice--;
			}
			GotoXY(3, 2 + choice);
			cout << "▶▷";	// 새로 그 위치에 그린다.
		}
	}
}

void UpdateGame()
{
	cout << "뱀이 움직일 시간" << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
