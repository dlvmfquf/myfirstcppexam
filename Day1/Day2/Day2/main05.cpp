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
		printf("ù��° ���ڸ� �Է����ּ���: ");
		scanf_s("%f", &first);
		printf("�ι�° ���ڸ� �Է����ּ���: ");
		scanf_s("%f", &second);
		printf("������ ����(��ȣ)�� �Է����ּ���(0: ���α׷� ����, 1:+, 2:-, 3:*, 4:/): ");
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
				printf("0���� ���� ���� �����ϴ�.\n");
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
			printf("�ùٸ� �����ڸ� �Է����ּ���.\n");
		}

	}


}