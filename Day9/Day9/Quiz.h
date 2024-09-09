#pragma once

/*
0. �⺻ ���ñݾ��� �� - ������ ���� bettingMoney
0-1. ȭ���� �ʱ�ȭ �� ���� - ȭ���� ���� - Card board;
1. ������ ���� - ���� card playerDeck[2]
1-1. ��ǻ�͵� ���� ���� - ����  card comDeck[2]
2. ���� (����, ��, ����, ����, ����) - Ű���� �Է� �� ���� �Ϳ� ���� �ൿ
2-1.����(d) - �ش� ���忡�� ���ݱ��� ������ ���� �¸��� ��� ���� �� ���ӿ��� ���� -- 1��1�̶� �����ϸ� �� ���尡 ����.
2-1-1. �������� �� ���Ͱ� ���ϸ� ���Ϳ� ���� �Ѿ 
2-2. ��(c) - ������ ��ŭ�� ���� �ɰ� �� ������ ��û - ������ ��/���̸� ����
2-3. ����(h) - �� ���� ���ݸ�ŭ ����
2-4. ����(q) - �� ���� 25% ����
2-5. ����(t) - �ջ���� �� ���� 2�� ����
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
���� - 4��+9�� - ���� ���� ��� �� �� ���º� �� ���� �״�� ���� ä ����
������ - 3�� ��+ 7�� ���� - �嶯 �̸��� ���� �� ���� �� ���� �׷��� ���� ������ ������ ��

*/

//ȭ���д� ��(1�� ~ 10��), ���� �ƴ� ��(��, ���� = 1/�Ϲ� = 0)���� ����
struct Card
{
	int month;
	int lightOrAnimal;
};

class MainQuizGame
{
public:
	
	//���� ����
	void StartGame();

	//ȭ���� �ʱ�ȭ
	void InitCards();

	//ȭ���� ����
	void ShuffleCards();
	
	//������
	void RunGame();

	//�ݾ� �����ֱ�
	void ShowMoney();

	//ù��° ī�� �����ֱ�
	void ShowFirstCard();

	//�ι�° ī�� �����ֱ�
	void ShowSecondCard();
	
	//�⺻ �ݾ� �����ϱ�
	void BetStartMoney();

	//ī�� ���� ����
	void GiveCard();

	//�÷��̾� �ൿ
	void actPlayer();

	//����
	void Die();

	//��
	void Call();

	//����
	void ActHalf();

	//����
	void ActQuarter();

	//�� ����
	void ChangeTurn();

	//��(�÷��̾�) ���
	void CalPlayerCards();

	//��(����) ���
	void CalComCards();

	//��� ���
	void PrintResult();

	//���� �ൿ
	void ActCom();

	//�� ����
	void GiveMoney();

	//�ൿ����
	void ReSetAct();

	//����Ұ��� ������
	void Continue();

public:
	int index = 0;
	int playerMoney = 10000;
	int comMoney = 10000;
	int betMoney = 0;
	int playerBettingMoney = 0;
	int comBettingMoney = 0;
	int playerTurn = 1;
	int comTurn = 0;
	int comAct = 0;
	int playerAct = 0;
	int playerScore = 0;
	int comScore = 0;
	int playerWin = 0;

	bool isGamePlaying = true;
	Card board[20] = {};
	Card playerDeck[2] = {};
	Card comDeck[2] = {};



};