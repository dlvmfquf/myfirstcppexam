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
	
	

	printf("안내면진다 가위바위보(하나빼기)! (1: 가위, 2: 바위, 3: 보, 띄어쓰기로 구분해주세요) ");
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
				
			cout << "컴퓨터는 가위와 바위를 골랐습니다." << endl;
			cout << "하나빼기! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "아쉽습니다 비겼습니다." << endl;
			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "유감입니다. 졌습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;
		}

		else if (comRightChoice == PAPER)
		{
			cout << "컴퓨터는 가위와 보를 골랐습니다." << endl;
			cout << "하나빼기! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "아쉽습니다 비겼습니다." << endl;
			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == PAPER)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == ROCK && comLastChoice == PAPER)
				cout << "유감입니다. 졌습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;
		}

	}

	else if (comLeftChoice == ROCK)
	{
		if (comRightChoice == SCISSOR)
		{
			cout << "컴퓨터는 가위와 바위를 골랐습니다." << endl;
			cout << "하나빼기! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "아쉽습니다 비겼습니다." << endl;
			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "유감입니다. 졌습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;
		}

		else if (comRightChoice == PAPER)
		{
			cout << "컴퓨터는 바위와 보를 골랐습니다." << endl;
			cout << "하나빼기! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "아쉽습니다 비겼습니다." << endl;
			else if (lastChoice == SCISSOR && comLastChoice == PAPER || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (lastChoice == ROCK && comLastChoice == PAPER || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "유감입니다. 졌습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;
		}


	}

	else if (comLeftChoice == PAPER)
	{
		if (comRightChoice == SCISSOR)
		{
			cout << "컴퓨터는 가위와 보를 골랐습니다." << endl;
			cout << "하나빼기! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "아쉽습니다 비겼습니다." << endl;

			else if (lastChoice == ROCK && comLastChoice == SCISSOR || lastChoice == SCISSOR && comLastChoice == PAPER)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (lastChoice == PAPER && comLastChoice == SCISSOR || lastChoice == ROCK && comLastChoice == PAPER)
				cout << "유감입니다. 졌습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;
		}

		else if (comRightChoice == ROCK)
		{
			cout << "컴퓨터는 바위와 보를 골랐습니다." << endl;
			cout << "하나빼기! ";
			cin >> lastChoice;

			if (lastChoice == comLastChoice)
				cout << "아쉽습니다 비겼습니다." << endl;
			else if (lastChoice == SCISSOR && comLastChoice == PAPER || lastChoice == PAPER && comLastChoice == ROCK)
				cout << "축하합니다 이겼습니다!" << endl;

			else if (lastChoice == ROCK && comLastChoice == PAPER || lastChoice == SCISSOR && comLastChoice == ROCK)
				cout << "유감입니다. 졌습니다." << endl;
			else
				cout << "똑바로 입력해주세요" << endl;
		}
	}


	//cout << "컴퓨터는 보와 바위를 골랐습니다." << endl;

	//cout << "하나빼기! ";
	//cin >> lastChoice;

	//if (lastChoice == leftChoice && leftChoice == )
	//	cout << "축하합니다 이겼습니다!" << endl;

	//else if (lastChoice == rightChoice)
	//	cout << "유감입니다. 졌습니다." << endl;
	//else
	//	cout << "똑바로 입력해주세요" << endl;

}