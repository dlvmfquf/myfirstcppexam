#include <iostream>

using namespace std;

void main()
{
	float height = 0.0;
	float weight = 0.0;
	float BMI = 0.0;
		printf("Ű(m)�� �Է����ּ���: ");
		scanf_s("%f", &height);
		printf("�����Ը� �Է����ּ���: ");
		scanf_s("%f", &weight);
		BMI = weight / (height * height);
		printf("BMI������: %f�̰�, ", BMI);
	if (0 <= BMI && 18.5 >= BMI)
		{
			printf("��ü���Դϴ�.\n");
		}
	else if (23 >=BMI)
		{
		printf("����ü���Դϴ�.\n");
		}
	else if (25 >= BMI)
		{
		printf("��ü���Դϴ�.\n");
		}
	else if (30 >= BMI)
	{
		printf("��ü���Դϴ�.\n");
	}
	else if (BMI > 30)
	{
		printf("�����Դϴ�.\n");
	}
	else
	{
		printf("���Ŀ� �´� Ű�� �����Ը� �Է����ּ���.");
	}
}