#include <iostream>

using namespace std;

void main()
{

	//�ʱ�ȭ�� �� �Ǿ����� Ȯ���ϴ� ��
	//1. �α� ���
	//2. ������ϱ� 

	int hand[2] = {};
	cout << "����(0), ����(1), ��(2) �߿� �� ���� �� �� ����ּ���:" << endl;

	for (int i = 0; i < 2; i++)
	{
		cin >> hand[i];
	}

	int comHand[2] = {};

	srand(time(NULL));

	comHand[0] = rand() % 3;
	comHand[1] = rand() % 3;
		

	cout << "�޼�(0) ������(1) �߿� ����ּ��� ";
	int handChoice;
	cin >> handChoice;

	int finalHand[2] = {};

	finalHand[0] = hand[handChoice];
	finalHand[1] = comHand[rand()%2];


}