#include <iostream>
#define SIZE 1

using namespace std;

void main()
{
	srand(time(NULL));

	int comLeftChoice, comRightChoice, comLastChoice;
	int leftChoice, rightChoice, lastChoice;
	int SCISSOR = 1;
	int ROCK = 2;
	int PAPER = 3;
	int RSASystem[3];
	
	

	printf("�ȳ������� ����������(�ϳ�����)! (1: ����, 2: ����, 3: ��, ����� �������ּ���) ");
	scanf_s("%d %d", &leftChoice, &rightChoice);

	for (int i = 0; i < 3; i++)
	{
		RSASystem[i] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		int firstIndex = rand() % 3;
		int secondIndex = rand() % 3;
		int temp;
		temp = RSASystem[firstIndex];
		RSASystem[firstIndex] = RSASystem[secondIndex];
		RSASystem[secondIndex] = temp;
	}

	/*for (int i = 0; i < 3; i++)
	{
		cout << "RSASystem " << i << ", " << RSASystem[i] << endl;
	}*/

	comLeftChoice = RSASystem[0];
	comRightChoice = RSASystem[1];
	comLastChoice = RSASystem[(rand() % 2)];

	if (comLeftChoice == SCISSOR)
	{

		if (comRightChoice == ROCK)
		{
				
			cout << "��ǻ�ʹ� ������ ������ ������ϴ�." << endl;
			cout << "�ϳ�����! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "�ƽ����ϴ� �����ϴ�." << endl;
			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "�����Դϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;
		}

		else if (comRightChoice == PAPER)
		{
			cout << "��ǻ�ʹ� ������ ���� ������ϴ�." << endl;
			cout << "�ϳ�����! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "�ƽ����ϴ� �����ϴ�." << endl;
			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == PAPER)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == ROCK && comLastChoice == PAPER)
				cout << "�����Դϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;
		}

	}

	else if (comLeftChoice == ROCK)
	{
		if (comRightChoice == SCISSOR)
		{
			cout << "��ǻ�ʹ� ������ ������ ������ϴ�." << endl;
			cout << "�ϳ�����! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "�ƽ����ϴ� �����ϴ�." << endl;
			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "�����Դϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;
		}

		else if (comRightChoice == PAPER)
		{
			cout << "��ǻ�ʹ� ������ ���� ������ϴ�." << endl;
			cout << "�ϳ�����! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "�ƽ����ϴ� �����ϴ�." << endl;
			else if (lastChoice == SCISSOR && comLastChoice == PAPER || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (lastChoice == ROCK && comLastChoice == PAPER || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "�����Դϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;
		}


	}

	else if (comLeftChoice == PAPER)
	{
		if (comRightChoice == SCISSOR)
		{
			cout << "��ǻ�ʹ� ������ ���� ������ϴ�." << endl;
			cout << "�ϳ�����! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "�ƽ����ϴ� �����ϴ�." << endl;

			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == PAPER)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == ROCK && comLastChoice == PAPER)
				cout << "�����Դϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;
		}

		else if (comRightChoice == ROCK)
		{
			cout << "��ǻ�ʹ� ������ ���� ������ϴ�." << endl;
			cout << "�ϳ�����! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "�ƽ����ϴ� �����ϴ�." << endl;
			else if (lastChoice == SCISSOR && comLastChoice == PAPER || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "�����մϴ� �̰���ϴ�!" << endl;

			else if (lastChoice == ROCK && comLastChoice == PAPER || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "�����Դϴ�. �����ϴ�." << endl;
			else
				cout << "�ȹٷ� �Է����ּ���" << endl;
		}
	}


	//cout << "��ǻ�ʹ� ���� ������ ������ϴ�." << endl;

	//cout << "�ϳ�����! ";
	//cin >> lastChoice;

	//if (lastChoice == leftChoice && leftChoice == )
	//	cout << "�����մϴ� �̰���ϴ�!" << endl;

	//else if (lastChoice == rightChoice)
	//	cout << "�����Դϴ�. �����ϴ�." << endl;
	//else
	//	cout << "�ȹٷ� �Է����ּ���" << endl;

}