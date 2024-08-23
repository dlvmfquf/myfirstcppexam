#include <iostream>
#define DEV_MODE

using namespace std;

int comBingo[5][5] = {};
int myBingo[5][5] = {};

int isGamePlaying = true;

int playerChoice = 0;

int comNumber[25] = {};
int playerNumber[25] = {0};

int turnTimes = 0;
int reverseTurnTimes = 24;

int comChoice = 0;

int comRowBingoCount = 0;
int comColBingoCount = 0;
int comLowRightBingoCount = 0;
int comHighRightBingoCount = 0;
int comBingoCount = 0;

int myRowBingoCount = 0;
int myColBingoCount = 0;
int myLowRightBingoCount = 0;
int myHighRightBingoCount = 0;
int myBingoCount = 0;

int countCount = 0;

int firstComRowBingoTurn = 0;
int firstComColBingoTurn = 0;
int firstComLowRightBingoTurn = 0;
int firstComHighRightBingoTurn = 0;


int firstMyRowBingoTurn = 0;
int firstMyColBingoTurn = 0;
int firstMyLowRightBingoTurn = 0;
int firstMyHighRightBingoTurn = 0;


void InitBingo()
{
	for (int i = 0; i < 25; i++)
	{
		comBingo[i / 5][i % 5] = i + 1;
	}

	for (int i = 0; i < 25; i++)
	{
		myBingo[i / 5][i % 5] = i + 1;
	}

}
void InitComChoice() 
{
	for (int i = 0; i < 25; i++)
	{
		comNumber[i] = i + 1;
	}

	srand(time(NULL));

	for (int i = 0; i < 2000; i++)
	{
		int firstIndex = rand() % 25;
		int secondIndex = rand() % 25;

		int temp;
		temp = comNumber[firstIndex];
		comNumber[firstIndex]= comNumber[secondIndex];
		comNumber[secondIndex] = temp;

	}

}
void ShuffleComBingo()
{
	srand(time(NULL));
	for (int i = 0; i < 1333; i++)
	{
		int firstIndex = rand() % 5;
		int secondIndex = rand() % 5;
		int thirdIndex = rand() % 5;
		int forthIndex = rand() % 5;

		int temp;
		temp = comBingo[firstIndex][secondIndex];
		comBingo[firstIndex][secondIndex] = comBingo[thirdIndex][forthIndex];
		comBingo[thirdIndex][forthIndex] = temp;

	}
}

void ShuffleMyBingo()
{
	srand(time(NULL));

	for (int i = 0; i < 2333; i++)
	{
		int firstIndex = rand() % 5;
		int secondIndex = rand() % 5;
		int thirdIndex = rand() % 5;
		int forthIndex = rand() % 5;

		int temp;
		temp = myBingo[firstIndex][secondIndex];
		myBingo[firstIndex][secondIndex] = myBingo[thirdIndex][forthIndex];
		myBingo[thirdIndex][forthIndex] = temp;

	}
}

void MarkX()
{
	cout << endl;
	cout << "��ǻ���� ������" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			if (playerChoice == comBingo[i][j])
			{
				cout << "X" << "\t";
				comBingo[i][j] = -1;
			}

			else if (comChoice == comBingo[i][j] && playerChoice != comChoice)
			{
				cout << "X" << "\t";
				comBingo[i][j] = -1;
			}

			else if (comBingo[i][j] == -1)
			{
				cout << "X" << "\t";
			}

			else
			{
				cout << comBingo[i][j] << "\t";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << "���� ������" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			if (playerChoice == myBingo[i][j])
			{
				cout << "X" << "\t";
				myBingo[i][j] = -1;
			}

			else if (comChoice == myBingo[i][j] && playerChoice != comChoice)
			{
				cout << "X" << "\t";
				myBingo[i][j] = -1;
			}

			else if (myBingo[i][j] == -1)
			{
				cout << "X" << "\t";
			}
			else
			{
				cout << myBingo[i][j] << "\t";
			}

		}
		cout << endl;
	}
}
void CountComRowBingo()
{
	//���� ���� ���
	countCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (comBingo[i][j] == -1)
			{
				countCount++;

			}
		}
		if (countCount == 5)
		{
			comRowBingoCount++;
			countCount = 0;
		}
		else
		{
			countCount = 0;
		}
	}

	countCount = 0;
}
void CountComColBingo()
{
	//���� ���� ���
	countCount = 0;
	for (int j = 0; j < 5; j++)
	{

		for (int i = 0; i < 5; i++)
		{
			if (comBingo[i][j] == -1)
			{
				countCount++;
			}
		}
		if (countCount == 5)
		{
			comColBingoCount++;
			countCount = 0;
		}
		else
		{
			countCount = 0;
		}
	}

	countCount = 0;
}

void CountComLowRightBingo() 
{
	//������ �밢���� ���� ���
	countCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j && comBingo[i][j] == -1)
			{
				countCount++;
			}
		}
	}
	if (countCount == 5)
	{
		comLowRightBingoCount++;
		countCount = 0;
	}
	else if (countCount != 5)
	{
		countCount = 0;
	}

	countCount = 0;
}

void CountComHighRightBingo()
{
	//����� �밢���� ���� ���
	countCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i + j == 4 && comBingo[i][j] == -1)
			{
				countCount++;
			}
		}
	}
	if (countCount == 5)
	{
		comHighRightBingoCount++;
		countCount = 0;
	}
	else if (countCount != 5)
	{
		countCount = 0;
	}

	countCount = 0;
}

void CountMyRowBingo()
{
	//���� ���� ���
	countCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (myBingo[i][j] == -1)
			{
				countCount++;

			}
		}
		if (countCount == 5)
		{
			myRowBingoCount++;
			countCount = 0;
		}
		else
		{
			countCount = 0;
		}
	}
	countCount = 0;
}
void CountMyColBingo() 
{
	//���� ���� ���
	countCount = 0;
	for (int j = 0; j < 5; j++)
	{

		for (int i = 0; i < 5; i++)
		{
			if (myBingo[i][j] == -1)
			{
				countCount++;
			}
		}
		if (countCount == 5)
		{
			myColBingoCount++;
			countCount = 0;
		}
		else
		{
			countCount = 0;
		}
	}
	countCount = 0;
}

void CountMyLowRightBingo() 
{
	//������ �밢���� ���� ���
	countCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j && myBingo[i][j] == -1)
			{
				countCount++;
			}
		}
	}
	if (countCount == 5)
	{
		myLowRightBingoCount++;
		countCount = 0;
	}
	else if (countCount != 5)
	{
		countCount = 0;
	}

	countCount = 0;
}

void CountMyHighRightBingo() 
{
	//����� �밢���� ���� ���
	countCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i + j == 4 && myBingo[i][j] == -1)
			{
				countCount++;
			}
		}
	}
	if (countCount == 5)
	{
		myHighRightBingoCount++;
		countCount = 0;
	}
	else if (countCount != 5)
	{
		countCount = 0;
	}

	countCount = 0;
}

void ShowBingo()
{
	cout << "��ǻ���� ������" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << comBingo[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;

	cout << "���� ������" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << myBingo[i][j] << "\t";
		}
		cout << endl;
	}
}

void main()
{	

	//������ �迭

	//������ �ʱ�ȭ
	InitBingo();
	//��ǻ�� ���� �ʱ�ȭ
	InitComChoice();

	//��ǻ�� ������ ����
	ShuffleComBingo();

	//�� ������ ����
	ShuffleMyBingo();

	//ó�� ������ �����ֱ�
	ShowBingo();

	//���� ��
	while (isGamePlaying)
	{	
		
		cout << "Xǥ �� ���ڸ� �Է����ּ���: ";
		cin >> playerChoice;

		if (playerChoice > 25 || playerChoice <= 0)
		{
			cout << "�ùٸ� ���ڸ� �Է����ּ���." << endl;
		}

		else 
		{
			playerNumber[turnTimes] = playerChoice;

			//Xǥ���ϱ�
			MarkX();

			comChoice = comNumber[turnTimes];

			//��ǻ�Ͱ� �� ���ڰ� �÷��̾�� �� ���ڶ� ������ �ٲٱ�
			for (int i = 0; i < 25; i++)
			{
				if (playerNumber[i] == comChoice)
				{
					comChoice = comNumber[reverseTurnTimes];
					break;
				}
			}
			cout << "��ǻ�Ͱ� ������ ����: " << comChoice << endl;
			//Xǥ���ϱ�
			MarkX();
			turnTimes++;
			reverseTurnTimes--;


			/*	��ǻ�� ���� �� ����(��, ��, �밢��)*/
			CountComRowBingo();
			if (comRowBingoCount > 1)
			{
				firstComRowBingoTurn++;
			}

			CountComColBingo();
			if (comColBingoCount > 1)
			{
				firstComColBingoTurn++;
			}

			CountComLowRightBingo();
			if (comLowRightBingoCount > 1)
			{
				firstComLowRightBingoTurn++;
			}

			CountComHighRightBingo();
			if (comHighRightBingoCount > 1)
			{
				firstComHighRightBingoTurn++;
			}

			comBingoCount = (comRowBingoCount - firstComRowBingoTurn) + (comColBingoCount - firstComColBingoTurn) + (comLowRightBingoCount - firstComLowRightBingoTurn) + (comHighRightBingoCount - firstComHighRightBingoTurn);
			cout << "��ǻ���� ���� ���� ��:" << comBingoCount << endl;

			/*�� ����� ����(��, ��, �밢��)*/
			CountMyRowBingo();
			if (myRowBingoCount > 1)
			{
				firstMyRowBingoTurn++;
			}

			CountMyColBingo();
			if (myColBingoCount > 1)
			{
				firstMyColBingoTurn++;
			}

			CountMyLowRightBingo();
			if (myLowRightBingoCount > 1)
			{
				firstMyLowRightBingoTurn++;
			}

			CountMyHighRightBingo();
			if (myHighRightBingoCount > 1)
			{
				firstMyHighRightBingoTurn++;
			}
			myBingoCount = (myRowBingoCount - firstMyRowBingoTurn) + (myColBingoCount - firstMyColBingoTurn) + (myLowRightBingoCount - firstMyLowRightBingoTurn) + (myHighRightBingoCount - firstMyHighRightBingoTurn);
			cout << "�÷��̾��� ���� ���� ��:" << myBingoCount << endl;

			if (comBingoCount != 3 && myBingoCount >= 3)
			{
				cout << "�����մϴ�. �¸��ϼ̽��ϴ�." << endl;
				isGamePlaying = false;
			}
			else if (comBingoCount >= 3 && myBingoCount != 3)
			{
				cout << "�ƽ����ϴ�. �й��ϼ̽��ϴ�." << endl;
				isGamePlaying = false;
			}
			else if (comBingoCount >= 3 && myBingoCount >= 3)
			{
				cout << "��.. �����ϴ�." << endl;
				isGamePlaying = false;
			}
		}
	}

}