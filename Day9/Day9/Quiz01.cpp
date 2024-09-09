#include "Quiz.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

/*
0. 기본 베팅금액을 냄 (2500) - 저장할 변수 startMoney
0-1. 화투패 초기화 및 섞기 - 화투패 저장 - Card board;
1. 한장을 받음 - 변수 card playerDeck[2]
1-1. 컴퓨터도 한장 받음 - 변수  card comDeck[2]
2. 베팅 (다이, 콜, 하프, 쿼터) - 키보드 입력 후 누른 것에 따라 행동
2-1.다이(1) - 해당 라운드에서 지금까지 투자한 돈과 승리를 모두 포기 후 게임에서 빠짐 -- 1ㄷ1이라 다이하면 그 라운드가 끝남.

2-2. 콜(2) - 베팅한 만큼의 돈을 걸고 판 끝내기 신청 - 상대방은 콜/다이만 가능

2-3. 하프(3) - 깔린 돈의 절반만큼 베팅

2-4. 쿼터(4) - 깔린 돈의 25% 베팅

3. 한장을 또 받음
4. 패를 오픈해 높은 족보면 돈을 따감
5. 콜 또는 다이를 하면 그 라운드를 끝냄(1ㄷ1이라서)
6. 라운드가 끝남
7. 누가 이겼는지 계산
8. 돈 지급
9. 다음 라운드를 할 것인지 질문
10. 한다고 했을 시 보유 자금이 기본 베팅금액보다 적으면 게임이 불가능하다며 보유 자금을 보여주고 게임을 끝냄
10-1. 한다고 했을 시 보유 자금에서 기본 베팅금액 차감후 다음 라운드 시작
10-2. 안한다고 했을 시 보유 자금을 보여주며 게임을 끝냄

특수규칙
땡잡이 - 3월 광+ 7월 열끗 - 장땡 미만의 땡을 다 잡을 수 있음 그런데 땡이 없으면 최하위 패

*/
void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MainQuizGame::StartGame()
{
	srand(time(NULL));

	GotoXY(10, 5); cout << "섯다(2장) 게임입니다." << endl;

	for (int i = 3; i >= 1; i--)
	{
		GotoXY(10, 6); cout << i << "초후에 시작하겠습니다." << endl;
		Sleep(1000);
	}
	system("cls");
}

void MainQuizGame::InitCards()
{

	//월 초기화
	for (int i = 0; i < 10; i++)
	{
		board[i].month = i + 1;
		board[i + 10].month = i + 1;
	}


	//광 또는 10끗 초기화
	for (int i = 0; i < 20; i++)
	{
		if (board[i].month == 1 || board[i].month == 3 || board[i].month == 7 || board[i].month == 8)
		{
			board[i].lightOrAnimal = 1;
		}
		else
		{
			board[i].lightOrAnimal = 0;
		}
	}

	/*for (int i = 0; i < 20; i++)
	{
		cout << board[i].month <<", "<< board[i].lightOrAnimal << endl;
	}*/


}

void MainQuizGame::ShuffleCards()
{
	srand(time(NULL));

	Card temp = {};

	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 20;
		int index2 = rand() % 20;

		temp = board[index1];
		board[index1] = board[index2];
		board[index2] = temp;
	}

	//for (int i = 0; i < 20; i++)
	//{
	//	cout << board[i].month <<", "<< board[i].lightOrAnimal << endl;
	//}

}

void MainQuizGame::ShowMoney()
{
	GotoXY(50, 0); cout << "                                                ";
	GotoXY(50, 0); cout << "현재 컴퓨터 보유 금액: " << comMoney;

	GotoXY(10, 10); cout << "현재 베팅 금액: " << betMoney;

	GotoXY(50, 20); cout << "                                                ";
	GotoXY(50, 20); cout << "현재 내 보유 금액: " << playerMoney;
}

void MainQuizGame::RunGame()
{
	while (isGamePlaying)
	{
		InitCards();
		ShuffleCards();

		ShowMoney();
		BetStartMoney();


		ShowMoney();

		GiveCard();
		GiveCard();

		ShowFirstCard();

		actPlayer();
		ActCom();

		ShowSecondCard();

		CalPlayerCards();
		CalComCards();
		GiveMoney();

		ShowMoney();

		ReSetAct();
		PrintResult();
		Continue();
	}
	system("cls");
	GotoXY(50, 16); cout << "게임이 끝났습니다(보유금: " << playerMoney << ") ";
}

void MainQuizGame::BetStartMoney()
{
	GotoXY(10, 11); cout << "스타트 머니(2500)를 베팅합니다";
	Sleep(2000);
	comMoney -= 2500;
	playerMoney -= 2500;
	betMoney += 5000;
	system("cls");
}

void MainQuizGame::GiveCard()
{
	comDeck[0] = board[index];
	comDeck[1] = board[index + 1];

	playerDeck[0]= board[index + 2];
	playerDeck[1] = board[index + 3];
	index++;
}

void MainQuizGame::ShowFirstCard()
{
	switch (playerDeck[0].lightOrAnimal)
	{
	case 0:
		GotoXY(50, 19); cout << "현재 내 패: " << playerDeck[0].month << "월";
		break;
	case 1:
		if (playerDeck[0].month == 1 || playerDeck[0].month == 3 || playerDeck[0].month == 8)
		{
			GotoXY(50, 19); cout << "현재 내 패: " << playerDeck[0].month << "월(광)";
		}
		else if (playerDeck[0].month == 7)
		{
			GotoXY(50, 19); cout << "현재 내 패: " << playerDeck[0].month << "월(열끗)";
		}
		break;
	default:
		break;
	}
}

void MainQuizGame::ShowSecondCard()
{
	switch (playerDeck[1].lightOrAnimal)
	{
	case 0:
		GotoXY(50, 18); cout << "현재 내 패: " << playerDeck[1].month << "월";
		break;
	case 1:
		if (playerDeck[1].month == 1 || playerDeck[1].month == 3 || playerDeck[1].month == 8)
		{
			GotoXY(50, 18); cout << "현재 내 패: " << playerDeck[1].month << "월(광)";
		}
		else if (playerDeck[0].month == 7)
		{
			GotoXY(50, 18); cout << "현재 내 패: " << playerDeck[1].month << "월(열끗)";
		}
		break;
	default:
		break;
	}
}

void MainQuizGame::actPlayer()
{
	bool isInvalid = true;
	//플레이어가 선턴일때
	if (playerTurn > comTurn)
	{
		GotoXY(40, 10); cout << "다이(d), 콜(c), 하프(h), 쿼터(q)";
		while (isInvalid)
			if (_kbhit())
			{
				char inputKey = _getch();
				switch (inputKey)
				{
				case 'd':
					cout << "다이";
					playerAct = 1;
					Die();

					isInvalid = false;
					break;
				case 'c':
					cout << "콜";
					playerAct = 2;
					Call();

					isInvalid = false;
					break;
				case 'h':
					cout << "하프";
					playerAct = 3;
					ActHalf();

					isInvalid = false;
					break;
				case 'q':
					cout << "쿼터";
					playerAct = 4;
					ActQuarter();

					isInvalid = false;
					break;
				default:
					GotoXY(40, 9); cout << "4개 행동중 하나를 골라주세요";
					break;
				}
			}
	}
	//컴터가 선턴일때
	else if (comTurn > playerTurn)
	{
		//컴터가 다이(1) 또는 콜(2)을 골랐을 때
		if (comAct == 1 || comAct == 2)
		{
			GotoXY(40, 10); cout << "다이(d), 콜(c)";
			while (isInvalid)
			if (_kbhit())
			{
				char inputKey = _getch();
				switch (inputKey)
				{
				case 'd':
					cout << "다이";
					playerAct = 1;
					Die();

					isInvalid = false;
					break;
				case 'c':
					cout << "콜";
					playerAct = 2;
					Call();

					isInvalid = false;
					break;
				default:
					GotoXY(40, 9); cout << "2개 행동중 하나를 골라주세요";
					break;
				}
			}
		}

		//컴터가 하프(3), 쿼터(4)를 골랐을 때
		else if(comAct == 3 || comAct == 4)
		{
			GotoXY(40, 10); cout << "다이(d), 하프(h), 쿼터(q)";
			while (isInvalid)
			if (_kbhit())
			{
				char inputKey = _getch();
				switch (inputKey)
				{
				case 'd':
					cout << "다이";
					playerAct = 1;
					Die();

					isInvalid = false;
					break;
				case 'h':
					cout << "하프";
					playerAct = 3;
					ActHalf();

					isInvalid = false;
					break;
				case 'q':
					cout << "쿼터";
					playerAct = 4;
					ActQuarter();
					isInvalid = false;
					break;
				default:
					GotoXY(40, 9); cout << "4개 행동중 하나를 골라주세요";
					break;
				}
			}
		}
	}

}

void MainQuizGame::ChangeTurn()
{
	int temp;
	temp = playerTurn;
	playerTurn = comTurn;
	comTurn = temp;
}

void MainQuizGame::Die()
{
	if (playerTurn > comTurn && comAct != 1)
	{
		comMoney += betMoney;
		playerBettingMoney = 0;
		comBettingMoney = 0;
		betMoney = 0;

	}
	else if (playerTurn < comTurn && playerAct != 1)
	{
		playerMoney += betMoney;
		playerBettingMoney = 0;
		comBettingMoney = 0;
		betMoney = 0;
	}
	else if (playerAct == 1 && comAct == 1)
	{
		isGamePlaying = false;
	}

	ChangeTurn();
}

void MainQuizGame::Call()
{
	//call == 2, die == 1
	if (playerAct == 2 && comAct == 2)
	{
		playerBettingMoney = 0;
		comBettingMoney = 0;
		isGamePlaying = false;
	}
	else if (playerAct == 1 && comAct == 2)
	{
		playerBettingMoney = 0;
		comBettingMoney = 0;
		comMoney += betMoney;
		betMoney = 0;
		isGamePlaying = false;
	}
	else if (playerAct == 2 && comAct == 1)
	{
		playerBettingMoney = 0;
		comBettingMoney = 0;
		playerMoney += betMoney;
		betMoney = 0;
		isGamePlaying = false;
	}
	ChangeTurn();
}

void MainQuizGame::ActHalf()
{
	if (playerTurn > comTurn)
	{
		playerBettingMoney = betMoney / 2;
		playerMoney -= playerBettingMoney;
		betMoney += playerBettingMoney;
	}
	else if (playerTurn < comTurn)
	{
		comBettingMoney = betMoney / 2;
		comMoney -= comBettingMoney;
		betMoney += comBettingMoney;
	}
	ChangeTurn();
}

void MainQuizGame::ActQuarter()
{
	if (playerTurn > comTurn)
	{
		playerBettingMoney = betMoney / 4;
		playerMoney -= playerBettingMoney;
		betMoney += playerBettingMoney;
	}
	else if (playerTurn < comTurn)
	{
		comBettingMoney = betMoney / 4;
		comMoney -= comBettingMoney;
		betMoney += comBettingMoney;
	}
	ChangeTurn();
}

void MainQuizGame::CalPlayerCards()
{
	//패 둘다 광(열끗)일때 (1, 3, 7, 8) - 광땡
	if (playerDeck[0].lightOrAnimal == 1 && playerDeck[1].lightOrAnimal == 1)
	{
		//일삼광땡 2000점 (1, 3)
		if ((playerDeck[0].month == 1 && playerDeck[1].month == 3) || (playerDeck[0].month == 3 && playerDeck[1].month == 1))
		{
			playerScore = 2000;
		}
		//일팔광땡 2500점(1,8)
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 8) || (playerDeck[0].month == 8 && playerDeck[1].month == 1))
		{
			playerScore = 2500;
		}
		//삼팔광땡 3000점(3,8)
		else if ((playerDeck[0].month == 3 && playerDeck[1].month == 8) || (playerDeck[0].month == 8 && playerDeck[1].month == 3))
		{
			playerScore = 3000;
		}
		//삼칠 땡잡이 (3,7)
		else if ((playerDeck[0].month == 3 && playerDeck[1].month == 7) || (playerDeck[0].month == 7 && playerDeck[1].month == 3))
		{
			//상대가 장땡(1000점) 미만 땡(100점~900점)이 있을 때 삼칠 땡잡이 (950점) 없으면 (-10점)
			if ((comDeck[0].month == comDeck[1].month) && comDeck[0].month < 10)
			{
				playerScore = 950;
			}
			else
			{
				playerScore = -10;
			}
		}
	}

	//둘 중 하나만 광(열끗)일때
	//땡(화투패 2개가 월이 같을 때)-월*100점(100점~1000점)
	else if (playerDeck[0].lightOrAnimal == 1 || playerDeck[1].lightOrAnimal == 1)
	{
		if (playerDeck[0].month == playerDeck[1].month)
		{
			playerScore = playerDeck[0].month * 100;
		}

		//장삥(1,10)-60점
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 10) || (playerDeck[0].month == 10 && playerDeck[1].month == 1))
		{
			playerScore = 60;
		}
		//구삥(1,9)-70점
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 9) || (playerDeck[0].month == 9 && playerDeck[1].month == 1))
		{
			playerScore = 70;
		}
		//독사(1,4)-80점
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 4) || (playerDeck[0].month == 4 && playerDeck[1].month == 1))
		{
			playerScore = 80;
		}
		//알리(1,2)-90점
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 2) || (playerDeck[0].month == 2 && playerDeck[1].month == 1))
		{
			playerScore = 90;
		}
		//이도저도 아닌 끗
		else
		{
			playerScore = (playerDeck[0].month + playerDeck[1].month) % 10;
		}

		//끗 - (두 월의 합) % 10점
	}
	//둘다 광(열끗)이 아닐때
	else
	{
		//땡
		if (playerDeck[0].month == playerDeck[1].month)
		{
			playerScore = playerDeck[0].month * 100;
		}
		//중간족보 장사(4,10)-50점
		else if ((playerDeck[0].month == 4 && playerDeck[1].month == 10) || (playerDeck[0].month == 10 && playerDeck[1].month == 4))
		{
			playerScore = 50;
		}
		//이도저도 아닌 끗
		else
		{
			playerScore = (playerDeck[0].month + playerDeck[1].month) % 10;
		}
		
	}

	//GotoXY(30, 6);  cout << "점수: " << playerScore;
}

void MainQuizGame::CalComCards()
{
	//패 둘다 광(열끗)일때 (1, 3, 7, 8) - 광땡
	if (comDeck[0].lightOrAnimal == 1 && comDeck[1].lightOrAnimal == 1)
	{
		//일삼광땡 2000점 (1, 3)
		if ((comDeck[0].month == 1 && comDeck[1].month == 3) || (comDeck[0].month == 3 && comDeck[1].month == 1))
		{
			comScore = 2000;
		}
		//일팔광땡 2500점(1,8)
		else if ((comDeck[0].month == 1 && comDeck[1].month == 8) || (comDeck[0].month == 8 && comDeck[1].month == 1))
		{
			comScore = 2500;
		}
		//삼팔광땡 3000점(3,8)
		else if ((comDeck[0].month == 3 && comDeck[1].month == 8) || (comDeck[0].month == 8 && comDeck[1].month == 3))
		{
			comScore = 3000;
		}
		//삼칠 땡잡이 (3,7)
		else if ((comDeck[0].month == 3 && comDeck[1].month == 7) || (comDeck[0].month == 7 && comDeck[1].month == 3))
		{
			//상대가 장땡(1000점) 미만 땡(100점~900점)이 있을 때 삼칠 땡잡이 (950점) 없으면 (-10점)
			if ((comDeck[0].month == comDeck[1].month) && comDeck[0].month < 10)
			{
				comScore = 950;
			}
			else
			{
				comScore = -10;
			}
		}
	}

	//둘 중 하나만 광(열끗)일때
	//땡(화투패 2개가 월이 같을 때)-월*100점(100점~1000점)
	else if (comDeck[0].lightOrAnimal == 1 || comDeck[1].lightOrAnimal == 1)
	{
		if (comDeck[0].month == comDeck[1].month)
		{
			comScore = comDeck[0].month * 100;
		}

		//장삥(1,10)-60점
		else if ((comDeck[0].month == 1 && comDeck[1].month == 10) || (comDeck[0].month == 10 && comDeck[1].month == 1))
		{
			comScore = 60;
		}
		//구삥(1,9)-70점
		else if ((comDeck[0].month == 1 && comDeck[1].month == 9) || (comDeck[0].month == 9 && comDeck[1].month == 1))
		{
			comScore = 70;
		}
		//독사(1,4)-80점
		else if ((comDeck[0].month == 1 && comDeck[1].month == 4) || (comDeck[0].month == 4 && comDeck[1].month == 1))
		{
			comScore = 80;
		}
		//알리(1,2)-90점
		else if ((comDeck[0].month == 1 && comDeck[1].month == 2) || (comDeck[0].month == 2 && comDeck[1].month == 1))
		{
			comScore = 90;
		}
		//이도저도 아닌 끗
		else
		{
			comScore = (comDeck[0].month + comDeck[1].month) % 10;
		}

		//끗 - (두 월의 합) % 10점
	}
	//둘다 광(열끗)이 아닐때
	else
	{
		//땡
		if (comDeck[0].month == comDeck[1].month)
		{
			comScore = comDeck[0].month * 100;
		}
		//중간족보 장사(4,10)-50점
		else if ((comDeck[0].month == 4 && comDeck[1].month == 10) || (comDeck[0].month == 10 && comDeck[1].month == 4))
		{
			comScore = 50;
		}
		//이도저도 아닌 끗
		else
		{
			comScore = (comDeck[0].month + comDeck[1].month) % 10;
		}

	}

	//GotoXY(60, 6);  cout << "점수: " << comScore;
}

void MainQuizGame::ActCom()
{
	comAct = 1 + (rand() % 4);
	
	if (playerAct == 1 || playerAct == 2)
	{
		comAct = 1 + (rand() % 2);
	}
	switch (comAct)
	{
	case 1:
		GotoXY(40, 1); cout << "컴퓨터는 다이를 선택";
		Die();
		break;
	
	case 2:
		GotoXY(40, 1); cout << "컴퓨터는 콜을 선택";
		Call();
		break;
	case 3:
		GotoXY(40, 1); cout << "컴퓨터는 하프를 선택";
		ActHalf();
		break;
	case 4:
		GotoXY(40, 1); cout << "컴퓨터는 쿼터를 선택";
		ActQuarter();
		break;
	default:
		break;
	}
	if (playerAct == 1 && comAct == 1)
	{
		isGamePlaying = false;
	}
}

void MainQuizGame::GiveMoney()
{
	if (playerScore > comScore && playerAct != 1)
	{
		playerMoney += betMoney;
		betMoney = 0;
	}
	else if (playerScore < comScore && comAct != 1)
	{
		comMoney += betMoney;
		betMoney = 0;
	}
	else if (playerAct == 1 && comAct == 2)
	{
		comMoney += betMoney;
		betMoney = 0;
	}
	else if (playerAct == 2 && comAct == 1)
	{
		playerMoney += betMoney;
		betMoney = 0;
	}
	else if (comAct == 1 && playerAct == 1)
	{

	}
}

void MainQuizGame::ReSetAct()
{
	comAct = 0;
	playerAct = 0;
}

void MainQuizGame::PrintResult()
{
	if (playerScore > comScore && playerAct != 1)
	{
		GotoXY(40, 12); cout << "돈을 가져갑니다";
	}
	else if (playerScore < comScore && comAct != 1)
	{
		GotoXY(40, 12); cout << "컴퓨터가 돈을 가져갑니다";
	}
	else if (playerAct == 1 && comAct == 2)
	{
		GotoXY(40, 12); cout << "컴퓨터가 돈을 가져갑니다";
	}
	else if (playerAct == 2 && comAct == 1)
	{
		GotoXY(40, 12); cout << "돈을 가져갑니다";
	}
}

void MainQuizGame::Continue()
{
	GotoXY(40, 13); cout << "계속하시겠습니까?(y/n)";
	bool isInvalid = true;
	while (isInvalid)
	{
		if (_kbhit())
		{
			char inputKey = _getch();
			switch (inputKey)
			{
			case 'y':
				if (playerMoney < 2500 || comMoney < 2500)
				{
					GotoXY(40, 14); cout << "자금이 부족하여 게임을 진행할 수 없습니다.";
					isGamePlaying = false;
				}
				betMoney = 0;
				playerBettingMoney = 0;
				comBettingMoney = 0;
				playerAct = 0;
				comAct = 0;
				isInvalid = false;
				break;
			case 'n':

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