//숙제2.
//학생부 시스템
//영어, 수학, 국어 성적 입력하게 끔해주고
//입력을 모두했으면, 학생의 평균점수를 확인해주는 프로그램
// Gotoxy 

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct StudentInfo
{
	int engScore;
	int mathScore;
	int languageScore;

};

void GotoXY(int x, int y);

void main()
{
	StudentInfo student = { };
	int average;

	GotoXY(0, 0); cout << "┌────────────────────┐";
	GotoXY(0, 1); cout << "│    학생부 시스템   │";
	GotoXY(0, 2); cout << "└────────────────────┘";

	GotoXY(0, 3);
	cout << "영어: ";
	cin >> student.engScore;
	cout << "수학: ";
	cin >> student.mathScore;
	cout << "국어: ";
	cin >> student.languageScore;

	system("cls");
	GotoXY(0, 0); cout << "┌────────────────────┐";
	GotoXY(0, 1); cout << "│    평균 산출중..   │";
	GotoXY(0, 2); cout << "└────────────────────┘";
	//■
	for (int i = 3; i < 51; i += 2)
	{
		GotoXY(i, 4); cout << "□";
		Sleep(10);
	}
	for (int j = 0; j < 3; j++) 
	{
		for (int i = 3; i < 50; i += 2)
		{
			GotoXY(i, 4); cout << "■";
			Sleep(25);
		}
		for (int k = 3; k < 50; k += 2)
		{
			GotoXY(k, 4); cout << "□";
			Sleep(25);
		}
	}

	average = (student.engScore + student.mathScore + student.languageScore) / 3;
	system("cls");

	GotoXY(0, 2);  cout << "평균: " << average;
	GotoXY(0, 4);

}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
