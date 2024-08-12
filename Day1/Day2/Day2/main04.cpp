#include <iostream>

using namespace std;

void main()
{	
	
	int year = 2042;
	if (year == 2024)
	{
		printf("현재 년도는 2024년\n");
	}
	else
	{
		printf("현재 년도는 2024년이 아니네\n");
	}


	int score = 50;

	if (score >= 90)
	{
		printf("이 학생은 A\n");
	}
	else if (score >= 80)
	{
		printf("이 학생은 B\n");
	}
	else if (score >= 70)
	{
		printf("이 학생은 C\n");
	}
	else if (score >= 60)
	{
		printf("이 학생은 D\n");
	}
	else
	{
		printf("이 학생은 F\n");
	}
}