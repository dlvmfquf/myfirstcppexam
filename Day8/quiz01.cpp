//熨薯1,2
// 螃棺 褒蝗и剪 (跨蝶攪諦 Ы溯檜橫)
// // GotoXY �倏�
#include <iostream>
#include <Windows.h>
#include <conio.h>

//寢檜嫌 諄辦晦
// 寢 奢問溘 5 ~ 15 餌檜 欐 葆棻 楠渾 撲薑
// 寢 羹溘擎 30 ~ 60 
// Ы溯檜橫 奢問溘 10
// Ы溯檜橫 羹溘擎 50 堅薑
// Ы溯檜橫陛 試盪 陽葬堅(Goto �倏�)
// 寢檜 �襤�(Goto �倏�)
// 寢檜 避剪釭 Ы溯檜橫陛 避戲賊 啞 部
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



	GotoXY(0, 0); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
	GotoXY(0, 1); cout << "弛夭夭夭  夭 夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭 夭夭弛";
	GotoXY(0, 2); cout << "弛夭夭                 夭夭夭夭夭夭夭夭夭夭夭夭夭 夭夭弛";
	GotoXY(0, 3); cout << "弛夭夭夭      雖釭陛棻陛 寢擊 虜陬蝗棲棻!夭 夭夭 夭夭 弛";
	GotoXY(0, 4); cout << "弛夭夭夭  夭夭 夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭 夭  弛";
	GotoXY(0, 5); cout << "弛夭夭夭  夭夭 夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭夭 夭夭弛";
	GotoXY(0, 6); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";


	//1蟾晦棻葬晦
	Sleep(1000);
	//�飛� 雖辦晦
	system("cls");


	while (player.hp > 0 && snake.hp > 0)
	{
		snake.attack = 5 + rand() % 11;

		GotoXY(0, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(0, 9); cout << "夭夭    Ы溯檜橫   羹溘: " << player.hp <<"           ";
		GotoXY(0, 10); cout <<"夭夭夭  Ы溯檜橫 奢問溘: " << player.attack <<"           ";
		GotoXY(0, 11); cout <<"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		

		GotoXY(70, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(70, 9); cout << "夭夭    寢   羹溘: " << snake.hp <<"           ";
		GotoXY(70, 10); cout <<"夭夭夭  寢 奢問溘: " << snake.attack <<"           ";
		GotoXY(70, 11); cout <<"戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎";


		for (int i = 0; i < 40; i++)
		{
			GotoXY(40 + i, 5); cout << "Ы溯檜橫曖 奢問" << endl;
			GotoXY(30 + i, 5); cout << "          " << endl;
			Sleep(1);
		}
		GotoXY(79, 6); cout << player.attack << "曖 Яп蒂 陛л!" << endl;
		snake.hp -= player.attack;
		Sleep(1000);
		system("cls");
		GotoXY(0, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(0, 9); cout << "夭夭    Ы溯檜橫   羹溘: " << player.hp <<"           ";
		GotoXY(0, 10); cout << "夭夭夭  Ы溯檜橫 奢問溘: " << player.attack <<"           ";
		GotoXY(0, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;



		GotoXY(70, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(70, 9); cout << "夭夭    寢   羹溘: " << snake.hp <<"           ";
		GotoXY(70, 10); cout << "夭夭夭  寢 奢問溘: " << snake.attack <<"           ";
		GotoXY(70, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;

		if (snake.hp <= 0)
			break;

		for (int i = 0; i < 30; i++)
		{
			GotoXY(40-i, 13); cout << "寢曖 奢問" << endl;
			GotoXY(49- i, 13); cout << "        " << endl;
			Sleep(1);
		}
		GotoXY(11, 14); cout << snake.attack << "曖 Яп蒂 嫡擠!" << endl;
		player.hp -= snake.attack;
		GotoXY(0, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(0, 9); cout << "夭夭    Ы溯檜橫   羹溘: " << player.hp << "           ";
		GotoXY(0, 10); cout << "夭夭夭  Ы溯檜橫 奢問溘: " << player.attack << "           ";
		GotoXY(0, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;



		GotoXY(70, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(70, 9); cout << "夭夭    寢   羹溘: " << snake.hp << "           ";
		GotoXY(70, 10); cout << "夭夭夭  寢 奢問溘: " << snake.attack << "           ";
		GotoXY(70, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;

		Sleep(1000);
		system("cls");

	}

	if (player.hp > snake.hp)
	{
		system("cls");
		GotoXY(0, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(0, 9); cout << "夭夭    Ы溯檜橫   羹溘: " << player.hp;
		GotoXY(0, 10); cout << "夭夭夭  Ы溯檜橫 奢問溘: " << player.attack;
		GotoXY(0, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;



		GotoXY(70, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(70, 9); cout << "夭夭    寢   羹溘: " << 0;
		GotoXY(70, 10); cout << "夭夭夭  寢 奢問溘: " << snake.attack;
		GotoXY(70, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;

		cout << "纂翮и 蕾瞪 部縑 羹溘擊 "<< player.hp <<"陴晦堅 蝓葬ц蝗棲棻." << endl;
		cout << "檜薯 餵戲煎 給嬴骨棲棻." << endl;
	}

	else
	{
		system("cls");
		GotoXY(0, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(0, 9); cout << "夭夭    Ы溯檜橫   羹溘: " << 0;
		GotoXY(0, 10); cout << "夭夭夭  Ы溯檜橫 奢問溘: " << player.attack;
		GotoXY(0, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;



		GotoXY(70, 8); cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式忖";
		GotoXY(70, 9); cout << "夭夭    寢   羹溘: " << snake.hp;
		GotoXY(70, 10); cout << "夭夭夭  寢 奢問溘: " << snake.attack;
		GotoXY(70, 11); cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式戎";
		cout << endl;

		cout << "寢擊 檜晦雖 跤ж堅 髦п渡ц蝗棲棻." << endl;
		cout << "陴擎 寢 羹溘: " << snake.hp << endl;
	}


}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
