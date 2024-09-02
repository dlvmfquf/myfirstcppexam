//¼÷Á¦1,2
// ¿À´Ã ½Ç½ÀÇÑ°Å (¸ó½ºÅÍ¿Í ÇÃ·¹ÀÌ¾î)
// // GotoXY È°¿ë
#include <iostream>
#include <Windows.h>
#include <conio.h>

//¹ìÀÌ¶û ½Î¿ì±â
// ¹ì °ø°Ý·Â 5 ~ 15 »çÀÌ ÅÏ ¸¶´Ù ·£´ý ¼³Á¤
// ¹ì Ã¼·ÂÀº 30 ~ 60 
// ÇÃ·¹ÀÌ¾î °ø°Ý·Â 10
// ÇÃ·¹ÀÌ¾î Ã¼·ÂÀº 50 °íÁ¤
// ÇÃ·¹ÀÌ¾î°¡ ¸ÕÀú ¶§¸®°í(Goto È°¿ë)
// ¹ìÀÌ ÈÄ°ø(Goto È°¿ë)
// ¹ìÀÌ Á×°Å³ª ÇÃ·¹ÀÌ¾î°¡ Á×À¸¸é °× ³¡
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



	GotoXY(0, 0); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
	GotoXY(0, 1); cout << "¦¢¤Ô¤Ô¤Ô  ¤Ô ¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô ¤Ô¤Ô¦¢";
	GotoXY(0, 2); cout << "¦¢¤Ô¤Ô                 ¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô ¤Ô¤Ô¦¢";
	GotoXY(0, 3); cout << "¦¢¤Ô¤Ô¤Ô      Áö³ª°¡´Ù°¡ ¹ìÀ» ¸¸³µ½À´Ï´Ù!¤Ô ¤Ô¤Ô ¤Ô¤Ô ¦¢";
	GotoXY(0, 4); cout << "¦¢¤Ô¤Ô¤Ô  ¤Ô¤Ô ¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô ¤Ô  ¦¢";
	GotoXY(0, 5); cout << "¦¢¤Ô¤Ô¤Ô  ¤Ô¤Ô ¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô¤Ô ¤Ô¤Ô¦¢";
	GotoXY(0, 6); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";


	//1ÃÊ±â´Ù¸®±â
	Sleep(1000);
	//È­¸é Áö¿ì±â
	system("cls");


	while (player.hp > 0 && snake.hp > 0)
	{
		snake.attack = 5 + rand() % 11;

		GotoXY(0, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(0, 9); cout << "¤Ô¤Ô    ÇÃ·¹ÀÌ¾î   Ã¼·Â: " << player.hp <<"           ";
		GotoXY(0, 10); cout <<"¤Ô¤Ô¤Ô  ÇÃ·¹ÀÌ¾î °ø°Ý·Â: " << player.attack <<"           ";
		GotoXY(0, 11); cout <<"¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		

		GotoXY(70, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(70, 9); cout << "¤Ô¤Ô    ¹ì   Ã¼·Â: " << snake.hp <<"           ";
		GotoXY(70, 10); cout <<"¤Ô¤Ô¤Ô  ¹ì °ø°Ý·Â: " << snake.attack <<"           ";
		GotoXY(70, 11); cout <<"¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";


		for (int i = 0; i < 40; i++)
		{
			GotoXY(40 + i, 5); cout << "ÇÃ·¹ÀÌ¾îÀÇ °ø°Ý" << endl;
			GotoXY(30 + i, 5); cout << "          " << endl;
			Sleep(1);
		}
		GotoXY(79, 6); cout << player.attack << "ÀÇ ÇÇÇØ¸¦ °¡ÇÔ!" << endl;
		snake.hp -= player.attack;
		Sleep(1000);
		system("cls");
		GotoXY(0, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(0, 9); cout << "¤Ô¤Ô    ÇÃ·¹ÀÌ¾î   Ã¼·Â: " << player.hp <<"           ";
		GotoXY(0, 10); cout << "¤Ô¤Ô¤Ô  ÇÃ·¹ÀÌ¾î °ø°Ý·Â: " << player.attack <<"           ";
		GotoXY(0, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;



		GotoXY(70, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(70, 9); cout << "¤Ô¤Ô    ¹ì   Ã¼·Â: " << snake.hp <<"           ";
		GotoXY(70, 10); cout << "¤Ô¤Ô¤Ô  ¹ì °ø°Ý·Â: " << snake.attack <<"           ";
		GotoXY(70, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;

		if (snake.hp <= 0)
			break;

		for (int i = 0; i < 30; i++)
		{
			GotoXY(40-i, 13); cout << "¹ìÀÇ °ø°Ý" << endl;
			GotoXY(49- i, 13); cout << "        " << endl;
			Sleep(1);
		}
		GotoXY(11, 14); cout << snake.attack << "ÀÇ ÇÇÇØ¸¦ ¹ÞÀ½!" << endl;
		player.hp -= snake.attack;
		GotoXY(0, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(0, 9); cout << "¤Ô¤Ô    ÇÃ·¹ÀÌ¾î   Ã¼·Â: " << player.hp << "           ";
		GotoXY(0, 10); cout << "¤Ô¤Ô¤Ô  ÇÃ·¹ÀÌ¾î °ø°Ý·Â: " << player.attack << "           ";
		GotoXY(0, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;



		GotoXY(70, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(70, 9); cout << "¤Ô¤Ô    ¹ì   Ã¼·Â: " << snake.hp << "           ";
		GotoXY(70, 10); cout << "¤Ô¤Ô¤Ô  ¹ì °ø°Ý·Â: " << snake.attack << "           ";
		GotoXY(70, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;

		Sleep(1000);
		system("cls");

	}

	if (player.hp > snake.hp)
	{
		system("cls");
		GotoXY(0, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(0, 9); cout << "¤Ô¤Ô    ÇÃ·¹ÀÌ¾î   Ã¼·Â: " << player.hp;
		GotoXY(0, 10); cout << "¤Ô¤Ô¤Ô  ÇÃ·¹ÀÌ¾î °ø°Ý·Â: " << player.attack;
		GotoXY(0, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;



		GotoXY(70, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(70, 9); cout << "¤Ô¤Ô    ¹ì   Ã¼·Â: " << 0;
		GotoXY(70, 10); cout << "¤Ô¤Ô¤Ô  ¹ì °ø°Ý·Â: " << snake.attack;
		GotoXY(70, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;

		cout << "Ä¡¿­ÇÑ Á¢Àü ³¡¿¡ Ã¼·ÂÀ» "<< player.hp <<"³²±â°í ½Â¸®Çß½À´Ï´Ù." << endl;
		cout << "ÀÌÁ¦ ÁýÀ¸·Î µ¹¾Æ°©´Ï´Ù." << endl;
	}

	else
	{
		system("cls");
		GotoXY(0, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(0, 9); cout << "¤Ô¤Ô    ÇÃ·¹ÀÌ¾î   Ã¼·Â: " << 0;
		GotoXY(0, 10); cout << "¤Ô¤Ô¤Ô  ÇÃ·¹ÀÌ¾î °ø°Ý·Â: " << player.attack;
		GotoXY(0, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;



		GotoXY(70, 8); cout << "¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤";
		GotoXY(70, 9); cout << "¤Ô¤Ô    ¹ì   Ã¼·Â: " << snake.hp;
		GotoXY(70, 10); cout << "¤Ô¤Ô¤Ô  ¹ì °ø°Ý·Â: " << snake.attack;
		GotoXY(70, 11); cout << "¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥";
		cout << endl;

		cout << "¹ìÀ» ÀÌ±âÁö ¸øÇÏ°í »ìÇØ´çÇß½À´Ï´Ù." << endl;
		cout << "³²Àº ¹ì Ã¼·Â: " << snake.hp << endl;
	}


}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
