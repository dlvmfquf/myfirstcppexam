#include <iostream>

using namespace std;

void main()
{	
	
	int year = 2042;
	if (year == 2024)
	{
		printf("���� �⵵�� 2024��\n");
	}
	else
	{
		printf("���� �⵵�� 2024���� �ƴϳ�\n");
	}


	int score = 50;

	if (score >= 90)
	{
		printf("�� �л��� A\n");
	}
	else if (score >= 80)
	{
		printf("�� �л��� B\n");
	}
	else if (score >= 70)
	{
		printf("�� �л��� C\n");
	}
	else if (score >= 60)
	{
		printf("�� �л��� D\n");
	}
	else
	{
		printf("�� �л��� F\n");
	}
}