#include <iostream>

using namespace std;

void main()
{
	float middle = 0.0;
	float last = 0.0;
	float attend = 0.0;
	float assign = 0.0;
	float result;

	printf("중간고사 점수를 입력해주세요: ");
	scanf_s("%f", &middle);
	printf("기말고사 점수를 입력해주세요: ");
	scanf_s("%f", &last);
	printf("출석 점수를 입력해주세요: ");
	scanf_s("%f", &attend);
	printf("과제 점수를 입력해주세요: ");
	scanf_s("%f", &assign);
	result = (middle + last + attend + assign) / 4;

	if (60 >= result && 0 <= result)
	{
		printf("F입니다.\n");
	}
	else if (70 >= result)
	{
		printf("D입니다.\n");
	}
	else if (80 >= result)
	{
		printf("C입니다.\n");
	}
	else if (90 >= result)
	{
		printf("B입니다.\n");
	}
	else if (100 >= result)
	{
		printf("A입니다.\n");
	}
	else
	{
		printf("올바른 점수를 입력해주세요.");
	}
}