#include <iostream>

using namespace std;

void main()
{
	float middle = 0.0;
	float last = 0.0;
	float attend = 0.0;
	float assign = 0.0;
	float result;

	printf("�߰���� ������ �Է����ּ���: ");
	scanf_s("%f", &middle);
	printf("�⸻��� ������ �Է����ּ���: ");
	scanf_s("%f", &last);
	printf("�⼮ ������ �Է����ּ���: ");
	scanf_s("%f", &attend);
	printf("���� ������ �Է����ּ���: ");
	scanf_s("%f", &assign);
	result = (middle + last + attend + assign) / 4;

	if (60 >= result && 0 <= result)
	{
		printf("F�Դϴ�.\n");
	}
	else if (70 >= result)
	{
		printf("D�Դϴ�.\n");
	}
	else if (80 >= result)
	{
		printf("C�Դϴ�.\n");
	}
	else if (90 >= result)
	{
		printf("B�Դϴ�.\n");
	}
	else if (100 >= result)
	{
		printf("A�Դϴ�.\n");
	}
	else
	{
		printf("�ùٸ� ������ �Է����ּ���.");
	}
}