#include <iostream>
#include "Quiz.h"

using namespace std;

void main()
{
	MainQuizGame* quiz01 = new MainQuizGame();

	quiz01->StartGame();
	quiz01->RunGame();

	delete quiz01;
	quiz01 = nullptr;
}