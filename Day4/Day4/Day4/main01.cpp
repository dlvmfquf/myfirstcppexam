#include <iostream>

using namespace std;


void main()
{
	srand(time(NULL));

	int playerWinRate = 1 + (rand() % 99);
	int goblinLv = 1, playerLv = 1;
	float goblinWinRate = 100 * (goblinLv /(float)(1 + playerLv * 2));


	// �迭, �ݺ���

	/*
	ī�� ���̽� ���� ���̱�
	myName

	������ũ
	my_name

	�Ľ�Į
	MyName

	�밡����
	�� �տ� �ڷ����� ���� �ٿ��ִ� ���̽�
	int iMyName;
	int m_ImyName;
	���� ��� �ߴ޷� ���� �� �ʿ䰡 ����
	*/
	

}