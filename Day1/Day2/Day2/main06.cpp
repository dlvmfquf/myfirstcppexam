#include <iostream>

using namespace std;

void main()
{
	float height = 0.0;
	float weight = 0.0;
	float BMI = 0.0;
		printf("키(m)를 입력해주세요: ");
		scanf_s("%f", &height);
		printf("몸무게를 입력해주세요: ");
		scanf_s("%f", &weight);
		BMI = weight / (height * height);
		printf("BMI지수는: %f이고, ", BMI);
	if (0 <= BMI && 18.5 >= BMI)
		{
			printf("저체중입니다.\n");
		}
	else if (23 >=BMI)
		{
		printf("정상체중입니다.\n");
		}
	else if (25 >= BMI)
		{
		printf("과체중입니다.\n");
		}
	else if (30 >= BMI)
	{
		printf("저체중입니다.\n");
	}
	else if (BMI > 30)
	{
		printf("고도비만입니다.\n");
	}
	else
	{
		printf("형식에 맞는 키와 몸무게를 입력해주세요.");
	}
}