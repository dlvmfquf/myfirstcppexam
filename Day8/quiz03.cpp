//����3.
//������ũ���� 
// �������Ӱ� �޸� (����ڰ� �Է��ؾ߸� ���� ����)
// ����Ÿ�� ����

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void UpdateGame();
void GotoXY(int x, int y);

void main()
{
	//���� �ð��� ����Ѵ�
	int oldGameTime = ::GetTickCount64();
	// GetTickCount64 ������ ����ǰ� ��ms�� �����°�?

	while (true)
	{
		//���� ���ӽð��� �޾ƿ´�.
		int currentGameTime = ::GetTickCount64();

		//����ð� - �����ð�
		if (300 < currentGameTime - oldGameTime)
		{
			UpdateGame();
			oldGameTime = currentGameTime;
		}
	}

	while (true)
	{

		if (_kbhit())	//Ű���带 �����ٸ�
		{
			char inputkey = _getch();	//�������� inputkey�� ��ڴ�.
			GotoXY(3, 2 + choice);
			cout << "�Ԥ�";	//�����Ÿ� �����ְ�
			if (inputkey == 's')
			{
				choice++;
			}
			else if (inputkey == 'w')
			{
				choice--;
			}
			GotoXY(3, 2 + choice);
			cout << "����";	// ���� �� ��ġ�� �׸���.
		}
	}
}

void UpdateGame()
{
	cout << "���� ������ �ð�" << endl;
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
