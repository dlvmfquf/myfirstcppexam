//����3.
//������ũ���� 
// �������Ӱ� �޸� (����ڰ� �Է��ؾ߸� ���� ����)
// ����Ÿ�� ����

#include <iostream>
#include <Windows.h>
#include <conio.h>

//�� ������� ����
// �ƹ�Ű�� ������ ����
// ������ ������ �⺻������ �������� �̵�,
// W�� ������ ���� ���ϸ� ������ w�� �� �� ���� �� �� �� �� ������ �� ��ȭ x
// S�� �Ʒ�,
// A�� ��,
// D�� �� 
// ���� �ε�ġ�ų� �ڱ� ���� ������ ���� ��
// ���� �ð��� ���� �� ���� �� ���� �� ĭ ����
// ������ ������ ���� ������� ��ϵ� �˷��ֱ�
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
	// GetTickCount64 ������ ����ǰ� ��ms�� �����°�?
	GotoXY(10, 5); cout << "������ũ ������ �����Ϸ��� �ƹ�Ű�� ��������." << endl;

	while (isGameNotStarted)
	{
		if (_kbhit())	//Ű���带 �����ٸ�
		{
				system("cls");
				GotoXY(10, 5); cout << "������ �����մϴ�." << endl;
				Sleep(1000);
				system("cls");
				isGameNotStarted = false;
				isGamePlaying = true;
		}
	}

	//Ʋ ����
	GotoXY(0, 0); cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	for (int i = 1; i < 28; i++) 
	{
		GotoXY(0, i); cout << "���ԤԤ�  �� �ԤԤԤԤԤ�                              �ԤԤԤ�                        �ԤԤԤԤԤԤԤ� �ԤԦ�";
	}

	GotoXY(0, 28); cout <<"������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������";
	GotoXY(50, 14);


	while (isGamePlaying)
	{

		if (_kbhit())	//Ű���带 �����ٸ�
		{
			char inputkey = _getch();	//�������� inputkey�� ��ڴ�.
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
		//���� ���ӽð��� �޾ƿ´�.
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
				GotoXY(currentX, currentY); cout << "��";

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
				GotoXY(currentX, currentY); cout << "��";

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
				GotoXY(currentX, currentY); cout << "��";

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
				GotoXY(currentX, currentY); cout << "��";

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
	cout << "������ �߰� �� �ð�" << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
