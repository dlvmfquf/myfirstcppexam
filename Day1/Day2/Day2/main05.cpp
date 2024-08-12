#include <iostream>

using namespace std;

void main()
{
	float first = 0.0;
	float second = 0.0;
	float result = 0.0;
	int oper = 0;
	while (1) 
	{
		printf("첫번째 숫자를 입력해주세요: ");
		scanf_s("%f", &first);
		printf("두번째 숫자를 입력해주세요: ");
		scanf_s("%f", &second);
		printf("실행할 연산(번호)을 입력해주세요(0: 프로그램 종료, 1:+, 2:-, 3:*, 4:/): ");
		scanf_s("%d", &oper);
		if (oper == 1)
		{
			result = first + second;
			printf("%f + %f = %f\n", first, second, result);
		}
		else if (oper == 2)
		{
			result = first - second;
			printf("%f - %f = %f\n", first, second, result);
		}
		else if (oper == 3)
		{
			result = first * second;
			printf("%f * %f = %f\n", first, second, result);
		}
		else if (oper == 4)
		{
			if (second == 0)
			{
				printf("0으로 나눌 수는 없습니다.\n");
			}
			result = first / second;
			printf("%f / %f = %f\n", first, second, result);
		}
		else if (oper == 0)
		{
			break;
		}
		else
		{
			printf("올바른 연산자를 입력해주세요.\n");
		}

	}


}