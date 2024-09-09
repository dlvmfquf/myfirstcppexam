#include "Quiz.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

/*
0. �⺻ ���ñݾ��� �� (2500) - ������ ���� startMoney
0-1. ȭ���� �ʱ�ȭ �� ���� - ȭ���� ���� - Card board;
1. ������ ���� - ���� card playerDeck[2]
1-1. ��ǻ�͵� ���� ���� - ����  card comDeck[2]
2. ���� (����, ��, ����, ����) - Ű���� �Է� �� ���� �Ϳ� ���� �ൿ
2-1.����(1) - �ش� ���忡�� ���ݱ��� ������ ���� �¸��� ��� ���� �� ���ӿ��� ���� -- 1��1�̶� �����ϸ� �� ���尡 ����.

2-2. ��(2) - ������ ��ŭ�� ���� �ɰ� �� ������ ��û - ������ ��/���̸� ����

2-3. ����(3) - �� ���� ���ݸ�ŭ ����

2-4. ����(4) - �� ���� 25% ����

3. ������ �� ����
4. �и� ������ ���� ������ ���� ����
5. �� �Ǵ� ���̸� �ϸ� �� ���带 ����(1��1�̶�)
6. ���尡 ����
7. ���� �̰���� ���
8. �� ����
9. ���� ���带 �� ������ ����
10. �Ѵٰ� ���� �� ���� �ڱ��� �⺻ ���ñݾ׺��� ������ ������ �Ұ����ϴٸ� ���� �ڱ��� �����ְ� ������ ����
10-1. �Ѵٰ� ���� �� ���� �ڱݿ��� �⺻ ���ñݾ� ������ ���� ���� ����
10-2. ���Ѵٰ� ���� �� ���� �ڱ��� �����ָ� ������ ����

Ư����Ģ
������ - 3�� ��+ 7�� ���� - �嶯 �̸��� ���� �� ���� �� ���� �׷��� ���� ������ ������ ��

*/
void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void MainQuizGame::StartGame()
{
	srand(time(NULL));

	GotoXY(10, 5); cout << "����(2��) �����Դϴ�." << endl;

	for (int i = 3; i >= 1; i--)
	{
		GotoXY(10, 6); cout << i << "���Ŀ� �����ϰڽ��ϴ�." << endl;
		Sleep(1000);
	}
	system("cls");
}

void MainQuizGame::InitCards()
{

	//�� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		board[i].month = i + 1;
		board[i + 10].month = i + 1;
	}


	//�� �Ǵ� 10�� �ʱ�ȭ
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
	GotoXY(50, 0); cout << "���� ��ǻ�� ���� �ݾ�: " << comMoney;

	GotoXY(10, 10); cout << "���� ���� �ݾ�: " << betMoney;

	GotoXY(50, 20); cout << "                                                ";
	GotoXY(50, 20); cout << "���� �� ���� �ݾ�: " << playerMoney;
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
	GotoXY(50, 16); cout << "������ �������ϴ�(������: " << playerMoney << ") ";
}

void MainQuizGame::BetStartMoney()
{
	GotoXY(10, 11); cout << "��ŸƮ �Ӵ�(2500)�� �����մϴ�";
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
		GotoXY(50, 19); cout << "���� �� ��: " << playerDeck[0].month << "��";
		break;
	case 1:
		if (playerDeck[0].month == 1 || playerDeck[0].month == 3 || playerDeck[0].month == 8)
		{
			GotoXY(50, 19); cout << "���� �� ��: " << playerDeck[0].month << "��(��)";
		}
		else if (playerDeck[0].month == 7)
		{
			GotoXY(50, 19); cout << "���� �� ��: " << playerDeck[0].month << "��(����)";
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
		GotoXY(50, 18); cout << "���� �� ��: " << playerDeck[1].month << "��";
		break;
	case 1:
		if (playerDeck[1].month == 1 || playerDeck[1].month == 3 || playerDeck[1].month == 8)
		{
			GotoXY(50, 18); cout << "���� �� ��: " << playerDeck[1].month << "��(��)";
		}
		else if (playerDeck[0].month == 7)
		{
			GotoXY(50, 18); cout << "���� �� ��: " << playerDeck[1].month << "��(����)";
		}
		break;
	default:
		break;
	}
}

void MainQuizGame::actPlayer()
{
	bool isInvalid = true;
	//�÷��̾ �����϶�
	if (playerTurn > comTurn)
	{
		GotoXY(40, 10); cout << "����(d), ��(c), ����(h), ����(q)";
		while (isInvalid)
			if (_kbhit())
			{
				char inputKey = _getch();
				switch (inputKey)
				{
				case 'd':
					cout << "����";
					playerAct = 1;
					Die();

					isInvalid = false;
					break;
				case 'c':
					cout << "��";
					playerAct = 2;
					Call();

					isInvalid = false;
					break;
				case 'h':
					cout << "����";
					playerAct = 3;
					ActHalf();

					isInvalid = false;
					break;
				case 'q':
					cout << "����";
					playerAct = 4;
					ActQuarter();

					isInvalid = false;
					break;
				default:
					GotoXY(40, 9); cout << "4�� �ൿ�� �ϳ��� ����ּ���";
					break;
				}
			}
	}
	//���Ͱ� �����϶�
	else if (comTurn > playerTurn)
	{
		//���Ͱ� ����(1) �Ǵ� ��(2)�� ����� ��
		if (comAct == 1 || comAct == 2)
		{
			GotoXY(40, 10); cout << "����(d), ��(c)";
			while (isInvalid)
			if (_kbhit())
			{
				char inputKey = _getch();
				switch (inputKey)
				{
				case 'd':
					cout << "����";
					playerAct = 1;
					Die();

					isInvalid = false;
					break;
				case 'c':
					cout << "��";
					playerAct = 2;
					Call();

					isInvalid = false;
					break;
				default:
					GotoXY(40, 9); cout << "2�� �ൿ�� �ϳ��� ����ּ���";
					break;
				}
			}
		}

		//���Ͱ� ����(3), ����(4)�� ����� ��
		else if(comAct == 3 || comAct == 4)
		{
			GotoXY(40, 10); cout << "����(d), ����(h), ����(q)";
			while (isInvalid)
			if (_kbhit())
			{
				char inputKey = _getch();
				switch (inputKey)
				{
				case 'd':
					cout << "����";
					playerAct = 1;
					Die();

					isInvalid = false;
					break;
				case 'h':
					cout << "����";
					playerAct = 3;
					ActHalf();

					isInvalid = false;
					break;
				case 'q':
					cout << "����";
					playerAct = 4;
					ActQuarter();
					isInvalid = false;
					break;
				default:
					GotoXY(40, 9); cout << "4�� �ൿ�� �ϳ��� ����ּ���";
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
	//�� �Ѵ� ��(����)�϶� (1, 3, 7, 8) - ����
	if (playerDeck[0].lightOrAnimal == 1 && playerDeck[1].lightOrAnimal == 1)
	{
		//�ϻﱤ�� 2000�� (1, 3)
		if ((playerDeck[0].month == 1 && playerDeck[1].month == 3) || (playerDeck[0].month == 3 && playerDeck[1].month == 1))
		{
			playerScore = 2000;
		}
		//���ȱ��� 2500��(1,8)
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 8) || (playerDeck[0].month == 8 && playerDeck[1].month == 1))
		{
			playerScore = 2500;
		}
		//���ȱ��� 3000��(3,8)
		else if ((playerDeck[0].month == 3 && playerDeck[1].month == 8) || (playerDeck[0].month == 8 && playerDeck[1].month == 3))
		{
			playerScore = 3000;
		}
		//��ĥ ������ (3,7)
		else if ((playerDeck[0].month == 3 && playerDeck[1].month == 7) || (playerDeck[0].month == 7 && playerDeck[1].month == 3))
		{
			//��밡 �嶯(1000��) �̸� ��(100��~900��)�� ���� �� ��ĥ ������ (950��) ������ (-10��)
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

	//�� �� �ϳ��� ��(����)�϶�
	//��(ȭ���� 2���� ���� ���� ��)-��*100��(100��~1000��)
	else if (playerDeck[0].lightOrAnimal == 1 || playerDeck[1].lightOrAnimal == 1)
	{
		if (playerDeck[0].month == playerDeck[1].month)
		{
			playerScore = playerDeck[0].month * 100;
		}

		//���(1,10)-60��
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 10) || (playerDeck[0].month == 10 && playerDeck[1].month == 1))
		{
			playerScore = 60;
		}
		//����(1,9)-70��
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 9) || (playerDeck[0].month == 9 && playerDeck[1].month == 1))
		{
			playerScore = 70;
		}
		//����(1,4)-80��
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 4) || (playerDeck[0].month == 4 && playerDeck[1].month == 1))
		{
			playerScore = 80;
		}
		//�˸�(1,2)-90��
		else if ((playerDeck[0].month == 1 && playerDeck[1].month == 2) || (playerDeck[0].month == 2 && playerDeck[1].month == 1))
		{
			playerScore = 90;
		}
		//�̵����� �ƴ� ��
		else
		{
			playerScore = (playerDeck[0].month + playerDeck[1].month) % 10;
		}

		//�� - (�� ���� ��) % 10��
	}
	//�Ѵ� ��(����)�� �ƴҶ�
	else
	{
		//��
		if (playerDeck[0].month == playerDeck[1].month)
		{
			playerScore = playerDeck[0].month * 100;
		}
		//�߰����� ���(4,10)-50��
		else if ((playerDeck[0].month == 4 && playerDeck[1].month == 10) || (playerDeck[0].month == 10 && playerDeck[1].month == 4))
		{
			playerScore = 50;
		}
		//�̵����� �ƴ� ��
		else
		{
			playerScore = (playerDeck[0].month + playerDeck[1].month) % 10;
		}
		
	}

	//GotoXY(30, 6);  cout << "����: " << playerScore;
}

void MainQuizGame::CalComCards()
{
	//�� �Ѵ� ��(����)�϶� (1, 3, 7, 8) - ����
	if (comDeck[0].lightOrAnimal == 1 && comDeck[1].lightOrAnimal == 1)
	{
		//�ϻﱤ�� 2000�� (1, 3)
		if ((comDeck[0].month == 1 && comDeck[1].month == 3) || (comDeck[0].month == 3 && comDeck[1].month == 1))
		{
			comScore = 2000;
		}
		//���ȱ��� 2500��(1,8)
		else if ((comDeck[0].month == 1 && comDeck[1].month == 8) || (comDeck[0].month == 8 && comDeck[1].month == 1))
		{
			comScore = 2500;
		}
		//���ȱ��� 3000��(3,8)
		else if ((comDeck[0].month == 3 && comDeck[1].month == 8) || (comDeck[0].month == 8 && comDeck[1].month == 3))
		{
			comScore = 3000;
		}
		//��ĥ ������ (3,7)
		else if ((comDeck[0].month == 3 && comDeck[1].month == 7) || (comDeck[0].month == 7 && comDeck[1].month == 3))
		{
			//��밡 �嶯(1000��) �̸� ��(100��~900��)�� ���� �� ��ĥ ������ (950��) ������ (-10��)
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

	//�� �� �ϳ��� ��(����)�϶�
	//��(ȭ���� 2���� ���� ���� ��)-��*100��(100��~1000��)
	else if (comDeck[0].lightOrAnimal == 1 || comDeck[1].lightOrAnimal == 1)
	{
		if (comDeck[0].month == comDeck[1].month)
		{
			comScore = comDeck[0].month * 100;
		}

		//���(1,10)-60��
		else if ((comDeck[0].month == 1 && comDeck[1].month == 10) || (comDeck[0].month == 10 && comDeck[1].month == 1))
		{
			comScore = 60;
		}
		//����(1,9)-70��
		else if ((comDeck[0].month == 1 && comDeck[1].month == 9) || (comDeck[0].month == 9 && comDeck[1].month == 1))
		{
			comScore = 70;
		}
		//����(1,4)-80��
		else if ((comDeck[0].month == 1 && comDeck[1].month == 4) || (comDeck[0].month == 4 && comDeck[1].month == 1))
		{
			comScore = 80;
		}
		//�˸�(1,2)-90��
		else if ((comDeck[0].month == 1 && comDeck[1].month == 2) || (comDeck[0].month == 2 && comDeck[1].month == 1))
		{
			comScore = 90;
		}
		//�̵����� �ƴ� ��
		else
		{
			comScore = (comDeck[0].month + comDeck[1].month) % 10;
		}

		//�� - (�� ���� ��) % 10��
	}
	//�Ѵ� ��(����)�� �ƴҶ�
	else
	{
		//��
		if (comDeck[0].month == comDeck[1].month)
		{
			comScore = comDeck[0].month * 100;
		}
		//�߰����� ���(4,10)-50��
		else if ((comDeck[0].month == 4 && comDeck[1].month == 10) || (comDeck[0].month == 10 && comDeck[1].month == 4))
		{
			comScore = 50;
		}
		//�̵����� �ƴ� ��
		else
		{
			comScore = (comDeck[0].month + comDeck[1].month) % 10;
		}

	}

	//GotoXY(60, 6);  cout << "����: " << comScore;
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
		GotoXY(40, 1); cout << "��ǻ�ʹ� ���̸� ����";
		Die();
		break;
	
	case 2:
		GotoXY(40, 1); cout << "��ǻ�ʹ� ���� ����";
		Call();
		break;
	case 3:
		GotoXY(40, 1); cout << "��ǻ�ʹ� ������ ����";
		ActHalf();
		break;
	case 4:
		GotoXY(40, 1); cout << "��ǻ�ʹ� ���͸� ����";
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
		GotoXY(40, 12); cout << "���� �������ϴ�";
	}
	else if (playerScore < comScore && comAct != 1)
	{
		GotoXY(40, 12); cout << "��ǻ�Ͱ� ���� �������ϴ�";
	}
	else if (playerAct == 1 && comAct == 2)
	{
		GotoXY(40, 12); cout << "��ǻ�Ͱ� ���� �������ϴ�";
	}
	else if (playerAct == 2 && comAct == 1)
	{
		GotoXY(40, 12); cout << "���� �������ϴ�";
	}
}

void MainQuizGame::Continue()
{
	GotoXY(40, 13); cout << "����Ͻðڽ��ϱ�?(y/n)";
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
					GotoXY(40, 14); cout << "�ڱ��� �����Ͽ� ������ ������ �� �����ϴ�.";
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
				GotoXY(40, 14); cout << "y�Ǵ� n�� �����ּ���";
				break;
			}
		}
	}
}