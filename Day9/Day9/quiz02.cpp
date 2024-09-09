// 새로운 트럼프카드게임
// 1. 베팅을 합니다.
//	3장을 뽑을건데,
//	3번째 카드가 1번카드와 2번카드 사이의 값인지 맞추는 게임
//	1번카드가 10이고 2	번카드 3이다, 3번카드가 5
//	3번카드는 10과 2사이에 있으니 베팅합격 두배 돈땀.
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

//카드 덱 초기화
void InitDeck();

//덱 셔플
void ShuffleDeck();

//베팅
void BetMoney();

//플레이어 카드 주기
void GiveCards();

//카드 값 계산
void CalCards();

//돈계산
void CalMoney();

//컨티뉴
void Continue();

//플레이어 카드 보여주기
void ShowPlayerCards();

//결과 보여주기
void ShowResult();

//게임 상황초기화
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
		cout << "얼마를 베팅하시겠습니까(보유금:" << playerMoney << ")? " ;
		cin >> playerBettingMoney; 
		if (playerBettingMoney > playerMoney)
		{
			cout << "가진돈 보다 더 많이 베팅할 수는 없습니다." << endl;
			playerBettingMoney = 0;
		}
		else
		{
			playerMoney -= playerBettingMoney;
			cout << "차감되었습니다." << endl;
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
	cout << "계속하시겠습니까?(y/n)";
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
					GotoXY(5, 5); cout << "자금이 부족하여 게임을 진행할 수 없습니다.";
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
				GotoXY(10, 5); cout << "보유금: "<<playerMoney;
				isGamePlaying = false;
				isInvalid = false;
				break;
			default:
				GotoXY(40, 14); cout << "y또는 n을 눌러주세요";
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
		GotoXY(10, 10); cout << "맞추셨습니다. 베팅한 돈의 2배를 가져갑니다.";
	}
	else
	{
		GotoXY(10, 10); cout << "맞추지 못했습니다. 베팅한 돈을 잃습니다.";
	}
}

void ResetGame()
{
	playerBettingMoney = 0;
	index = 0;
	playerWin = 0;
	ShuffleDeck();
}