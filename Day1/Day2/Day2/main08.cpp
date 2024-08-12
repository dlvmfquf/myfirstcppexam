#include <iostream>

using namespace std;

void main()
{
	int number;
	printf("숫자(정수)를 입력해주세요: ");
	scanf_s("%d", &number);
	if (number % 2 == 0)
		printf("%d은(는) 짝수입니다.\n", number);
	else
		printf("%d은(는) 홀수입니다.\n", number);
}