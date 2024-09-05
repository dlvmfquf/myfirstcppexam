//숙제3.
//스네이크게임 
// 기존게임과 달리 (사용자가 입력해야만 게임 진행)
// 리얼타임 게임

#include <iostream>
#include <Windows.h>
#include <conio.h>

//정 가운데에서 시작
// 아무키나 누르면 시작
// 가만히 있으면 기본적으로 동쪽으로 이동,
// W를 누르면 위를 향하며 움직임 w를 한 번 누른 후 한 번 더 눌렀을 시 변화 x
// S는 아래,
// A는 서,
// D는 동 
// 벽에 부딪치거나 자기 몸에 닿으면 게임 끝
// 일정 시간이 지날 때 마다 몸 길이 한 칸 증가
// 게임이 끝나면 몇초 버텼는지 기록도 알려주기
//


using namespace std;

int xAxis = 0;
int yAxis = 0;
bool isGameNotStarted = true;
bool isGamePlaying = false;
int halfSec = 0;
int currentX = 50;
int currentY = 14;	
int delayCount = 2;
int* pastX = new int[delayCount] {54};
int* pastY = new int[delayCount] {14};
int i = 0;
int j = 0;


void UpdateGame();
void GotoXY(int x, int y);

void main()
{
	int oldGameTime1 = ::GetTickCount64();
	int oldGameTime2 = ::GetTickCount64();
	// GetTickCount64 게임이 진행되고 몇ms가 지났는가?
	GotoXY(10, 5); cout << "스네이크 게임을 시작하려면 아무키나 누르세요." << endl;

	while (isGameNotStarted)
	{
		if (_kbhit())	//키보드를 눌렀다면
		{
				system("cls");
				GotoXY(10, 5); cout << "게임을 시작합니다." << endl;
				Sleep(1000);
				system("cls");
				isGameNotStarted = false;
				isGamePlaying = true;
		}
	}

	//틀 설정
	GotoXY(0, 0); cout << "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────┐";
	for (int i = 1; i < 28; i++) 
	{
		GotoXY(0, i); cout << "│ㅤㅤㅤ  ㅤ ㅤㅤㅤㅤㅤㅤ                              ㅤㅤㅤㅤ                        ㅤㅤㅤㅤㅤㅤㅤㅤ ㅤㅤ│";
	}

	GotoXY(0, 28); cout <<"└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘";
	GotoXY(50, 14);


	while (isGamePlaying)
	{

		if (_kbhit())	//키보드를 눌렀다면
		{
			char inputkey = _getch();	//누른값을 inputkey에 담겠다.
			if (inputkey == 'w')
			{
				yAxis = -1;
				xAxis = 0;
			}
			else if (inputkey == 's')
			{
				yAxis = 1;
				xAxis = 0;
			}
			else if (inputkey == 'a')
			{
				xAxis = -1;
				yAxis = 0;
			}
			else if (inputkey == 'd')
			{
				xAxis = 1;
				yAxis = 0;
			}
			else if (inputkey == 'p')
			{
				isGamePlaying = false;
			}
		}

		if ((currentX <= 0 || currentX >= 100) && (currentY == 0 || currentY >= 28))
		{
			isGamePlaying = false;
		}
		//현재 게임시간을 받아온다.
		int currentGameTime1 = ::GetTickCount64();
		int currentGameTime2 = ::GetTickCount64();
	
		if (400 < currentGameTime1 - oldGameTime1)
		{
			halfSec += 1;
			//int delay = (currentGameTime - oldGameTime)/100;
			if (yAxis > 0)
			{
				pastX[i] = currentX;
				pastY[i] = currentY;


				currentY += yAxis;
				GotoXY(currentX, currentY); cout << "■";

				if (i == delayCount)
				{
					delayCount += 4;
				}
			}
			else if (yAxis < 0)
			{
				pastX[i] = currentX;
				pastY[i] = currentY;


				currentY += yAxis;
				GotoXY(currentX, currentY); cout << "■";

				if (i == delayCount)
				{
					delayCount += 4;
				}

			}
			if (xAxis > 0)
			{

				pastX[i] = currentX;
				pastY[i] = currentY;


				currentX += xAxis * 2;
				GotoXY(currentX, currentY); cout << "■";

				if (i == delayCount)
				{
					delayCount += 4;
				}


			}
			else if (xAxis < 0)
			{
				pastX[i] = currentX;
				pastY[i] = currentY;


				currentX += xAxis * 2;
				GotoXY(currentX, currentY); cout << "■";

				if (i == delayCount)
				{
					delayCount += 4;
				}

			}
			oldGameTime1 = currentGameTime1;
			i++;

			if (halfSec == 2)
			{
				GotoXY(pastX[j], pastY[j]); cout << "  ";
				//cout << "X: " << pastX[j]<< endl << "Y: " << pastY[j] << endl;
				//cout << "X: " << pastX[j+1]<< endl << "Y: " << pastY[j+1] << endl;
				j++;
				halfSec = 0;
			}
		}
	}
	delete []pastX;
	delete []pastY;
}

void UpdateGame()
{
	cout << "꼬리가 추가 될 시간" << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
