//����1,2
// ���� �ǽ��Ѱ� (���Ϳ� �÷��̾�)
// // GotoXY Ȱ��
#include <iostream>
#include <Windows.h>
#include <conio.h>

//���̶� �ο��
// �� ���ݷ� 5 ~ 15 ���� �� ���� ���� ����
// �� ü���� 30 ~ 60 
// �÷��̾� ���ݷ� 10
// �÷��̾� ü���� 50 ����
// �÷��̾ ���� ������(Goto Ȱ��)
// ���� �İ�(Goto Ȱ��)
// ���� �װų� �÷��̾ ������ �� ��
//
using namespace std;

void GotoXY(int x, int y);


struct Entity
{
	float hp;
	float attack;
};

void main()
{
	srand(time(NULL));

	Entity snake = { };
	Entity player = { };
	player.hp = 50;
	player.attack = 10;
	snake.hp = 31 + ( rand() % 30);



	GotoXY(0, 0); cout << "������������������������������������������������������������������������������������������������������������";
	GotoXY(0, 1); cout << "���ԤԤ�  �� �ԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤ� �ԤԦ�";
	GotoXY(0, 2); cout << "���Ԥ�                 �ԤԤԤԤԤԤԤԤԤԤԤԤ� �ԤԦ�";
	GotoXY(0, 3); cout << "���ԤԤ�      �������ٰ� ���� �������ϴ�!�� �Ԥ� �Ԥ� ��";
	GotoXY(0, 4); cout << "���ԤԤ�  �Ԥ� �ԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤ� ��  ��";
	GotoXY(0, 5); cout << "���ԤԤ�  �Ԥ� �ԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤԤ� �ԤԦ�";
	GotoXY(0, 6); cout << "������������������������������������������������������������������������������������������������������������";


	//1�ʱ�ٸ���
	Sleep(1000);
	//ȭ�� �����
	system("cls");


	while (player.hp > 0 && snake.hp > 0)
	{
		snake.attack = 5 + rand() % 11;

		GotoXY(0, 8); cout << "����������������������������������������������������������������������";
		GotoXY(0, 9); cout << "�Ԥ�    �÷��̾�   ü��: " << player.hp <<"           ";
		GotoXY(0, 10); cout <<"�ԤԤ�  �÷��̾� ���ݷ�: " << player.attack <<"           ";
		GotoXY(0, 11); cout <<"����������������������������������������������������������������������";
		

		GotoXY(70, 8); cout << "��������������������������������������������������������";
		GotoXY(70, 9); cout << "�Ԥ�    ��   ü��: " << snake.hp <<"           ";
		GotoXY(70, 10); cout <<"�ԤԤ�  �� ���ݷ�: " << snake.attack <<"           ";
		GotoXY(70, 11); cout <<"��������������������������������������������������������";


		for (int i = 0; i < 40; i++)
		{
			GotoXY(40 + i, 5); cout << "�÷��̾��� ����" << endl;
			GotoXY(30 + i, 5); cout << "          " << endl;
			Sleep(1);
		}
		GotoXY(79, 6); cout << player.attack << "�� ���ظ� ����!" << endl;
		snake.hp -= player.attack;
		Sleep(1000);
		system("cls");
		GotoXY(0, 8); cout << "����������������������������������������������������������������������";
		GotoXY(0, 9); cout << "�Ԥ�    �÷��̾�   ü��: " << player.hp <<"           ";
		GotoXY(0, 10); cout << "�ԤԤ�  �÷��̾� ���ݷ�: " << player.attack <<"           ";
		GotoXY(0, 11); cout << "����������������������������������������������������������������������";
		cout << endl;



		GotoXY(70, 8); cout << "��������������������������������������������������������";
		GotoXY(70, 9); cout << "�Ԥ�    ��   ü��: " << snake.hp <<"           ";
		GotoXY(70, 10); cout << "�ԤԤ�  �� ���ݷ�: " << snake.attack <<"           ";
		GotoXY(70, 11); cout << "��������������������������������������������������������";
		cout << endl;

		if (snake.hp <= 0)
			break;

		for (int i = 0; i < 30; i++)
		{
			GotoXY(40-i, 13); cout << "���� ����" << endl;
			GotoXY(49- i, 13); cout << "        " << endl;
			Sleep(1);
		}
		GotoXY(11, 14); cout << snake.attack << "�� ���ظ� ����!" << endl;
		player.hp -= snake.attack;
		GotoXY(0, 8); cout << "����������������������������������������������������������������������";
		GotoXY(0, 9); cout << "�Ԥ�    �÷��̾�   ü��: " << player.hp << "           ";
		GotoXY(0, 10); cout << "�ԤԤ�  �÷��̾� ���ݷ�: " << player.attack << "           ";
		GotoXY(0, 11); cout << "����������������������������������������������������������������������";
		cout << endl;



		GotoXY(70, 8); cout << "��������������������������������������������������������";
		GotoXY(70, 9); cout << "�Ԥ�    ��   ü��: " << snake.hp << "           ";
		GotoXY(70, 10); cout << "�ԤԤ�  �� ���ݷ�: " << snake.attack << "           ";
		GotoXY(70, 11); cout << "��������������������������������������������������������";
		cout << endl;

		Sleep(1000);
		system("cls");

	}

	if (player.hp > snake.hp)
	{
		system("cls");
		GotoXY(0, 8); cout << "����������������������������������������������������������������������";
		GotoXY(0, 9); cout << "�Ԥ�    �÷��̾�   ü��: " << player.hp;
		GotoXY(0, 10); cout << "�ԤԤ�  �÷��̾� ���ݷ�: " << player.attack;
		GotoXY(0, 11); cout << "����������������������������������������������������������������������";
		cout << endl;



		GotoXY(70, 8); cout << "��������������������������������������������������������";
		GotoXY(70, 9); cout << "�Ԥ�    ��   ü��: " << 0;
		GotoXY(70, 10); cout << "�ԤԤ�  �� ���ݷ�: " << snake.attack;
		GotoXY(70, 11); cout << "��������������������������������������������������������";
		cout << endl;

		cout << "ġ���� ���� ���� ü���� "<< player.hp <<"����� �¸��߽��ϴ�." << endl;
		cout << "���� ������ ���ư��ϴ�." << endl;
	}

	else
	{
		system("cls");
		GotoXY(0, 8); cout << "����������������������������������������������������������������������";
		GotoXY(0, 9); cout << "�Ԥ�    �÷��̾�   ü��: " << 0;
		GotoXY(0, 10); cout << "�ԤԤ�  �÷��̾� ���ݷ�: " << player.attack;
		GotoXY(0, 11); cout << "����������������������������������������������������������������������";
		cout << endl;



		GotoXY(70, 8); cout << "��������������������������������������������������������";
		GotoXY(70, 9); cout << "�Ԥ�    ��   ü��: " << snake.hp;
		GotoXY(70, 10); cout << "�ԤԤ�  �� ���ݷ�: " << snake.attack;
		GotoXY(70, 11); cout << "��������������������������������������������������������";
		cout << endl;

		cout << "���� �̱��� ���ϰ� ���ش��߽��ϴ�." << endl;
		cout << "���� �� ü��: " << snake.hp << endl;
	}


}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}