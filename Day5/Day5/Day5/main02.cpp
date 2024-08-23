#include <iostream>

using namespace std;

void main()
{

	//초기화가 잘 되었는지 확인하는 법
	//1. 로그 찍기
	//2. 디버깅하기 

	int hand[2] = {};
	cout << "가위(0), 바위(1), 보(2) 중에 낼 것을 두 개 골라주세요:" << endl;

	for (int i = 0; i < 2; i++)
	{
		cin >> hand[i];
	}

	int comHand[2] = {};

	srand(time(NULL));

	comHand[0] = rand() % 3;
	comHand[1] = rand() % 3;
		

	cout << "왼손(0) 오른손(1) 중에 골라주세요 ";
	int handChoice;
	cin >> handChoice;

	int finalHand[2] = {};

	finalHand[0] = hand[handChoice];
	finalHand[1] = comHand[rand()%2];


}