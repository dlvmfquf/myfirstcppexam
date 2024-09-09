// ���ο� Ʈ����ī�����
// 1. ������ �մϴ�.
//	3���� �����ǵ�,
//	3��° ī�尡 1��ī��� 2��ī�� ������ ������ ���ߴ� ����
//	1��ī�尡 10�̰� 2	��ī�� 3�̴�, 3��ī�尡 5
//	3��ī��� 10�� 2���̿� ������ �����հ� �ι� ����.
#include <iostream>
#include <Windows.h>
#include <conio.h>

int playerDeck[3] = {};
int playerMoney = 10000;
int playerBettingMoney = 0;
int deck[52] = {};
int index = 0;
int playerWin = 0;
bool isGamePlaying = true;


using namespace std;

//ī�� �� �ʱ�ȭ
void InitDeck();

//�� ����
void ShuffleDeck();

//����
void BetMoney();

//�÷��̾� ī�� �ֱ�
void GiveCards();

//ī�� �� ���
void CalCards();

//�����
void CalMoney();

//��Ƽ��
void Continue();

//�÷��̾� ī�� �����ֱ�
void ShowPlayerCards();

//��� �����ֱ�
void ShowResult();

//���� ��Ȳ�ʱ�ȭ
void ResetGame();

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void main()
{
	while (isGamePlaying)
	{
		InitDeck();
		ShuffleDeck();

		BetMoney();

		GiveCards();

		CalCards();

		CalMoney();
		ShowPlayerCards();
		ShowResult();

		ResetGame();
		Continue();
	}
}


void InitDeck()
{
	for (int i = 0; i < 13; i++)
	{
		deck[i] = i + 1;
		deck[i + 13] = i + 1;
		deck[i + 26] = i + 1;
		deck[i + 39] = i + 1;
	}
	/*for (int i = 0; i < 52; i++)
	{
		cout << deck[i]<<endl;
	}*/
}

void ShuffleDeck()
{
	srand(time(NULL));

	int temp;
	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 52;
		int index2 = rand() % 52;
		temp = deck[index1];
		deck[index1] = deck[index2];
		deck[index2] = temp;
	}
	/*for (int i = 0; i < 52; i++)
	{
		cout << deck[i] << endl;
	}*/
}

void BetMoney()
{
	bool isInvalid = true;
	while (isInvalid)
	{
		cout << "�󸶸� �����Ͻðڽ��ϱ�(������:" << playerMoney << ")? " ;
		cin >> playerBettingMoney; 
		if (playerBettingMoney > playerMoney)
		{
			cout << "������ ���� �� ���� ������ ���� �����ϴ�." << endl;
			playerBettingMoney = 0;
		}
		else
		{
			playerMoney -= playerBettingMoney;
			cout << "�����Ǿ����ϴ�." << endl;
			isInvalid = false;
		}
	}
}

void GiveCards()
{
	for (int i = 0; i < 3; i++)
	{
		playerDeck[i] = deck[index];
		index++;
	}
}

void CalCards()
{
	if ((playerDeck[2] > playerDeck[0] && playerDeck[2] < playerDeck[1])
		|| ((playerDeck[2] > playerDeck[1] && playerDeck[2] < playerDeck[0])))
	{
		playerWin = 1;
	}
	else 
	{
		playerWin = 0;
	}
}

void CalMoney()
{
	if (playerWin == 1)
	{
		playerMoney += playerBettingMoney * 2;
	}

}

void Continue() 
{
	cout << "����Ͻðڽ��ϱ�?(y/n)";
	bool isInvalid = true;
	while (isInvalid)
	{
		if (_kbhit())
		{
			char inputKey = _getch();
			switch (inputKey)
			{
			case 'y':
				if (playerMoney <= 0)
				{
					GotoXY(5, 5); cout << "�ڱ��� �����Ͽ� ������ ������ �� �����ϴ�.";
					isGamePlaying = false;
					isInvalid = false;
				}
				else
				{
					system("cls");
					isInvalid = false;
				}
				break;
			case 'n':
				system("cls");
				GotoXY(10, 5); cout << "������: "<<playerMoney;
				isGamePlaying = false;
				isInvalid = false;
				break;
			default:
				GotoXY(40, 14); cout << "y�Ǵ� n�� �����ּ���";
				break;
			}
		}
	}
}

void ShowPlayerCards()
{
	GotoXY(10, 5); cout << playerDeck[0] << ", " << playerDeck[1] <<  ", " << playerDeck[2];
}

void ShowResult()
{
	if (playerWin == 1)
	{
		GotoXY(10, 10); cout << "���߼̽��ϴ�. ������ ���� 2�踦 �������ϴ�.";
	}
	else
	{
		GotoXY(10, 10); cout << "������ ���߽��ϴ�. ������ ���� �ҽ��ϴ�.";
	}
}

void ResetGame()
{
	playerBettingMoney = 0;
	index = 0;
	playerWin = 0;
	ShuffleDeck();
}