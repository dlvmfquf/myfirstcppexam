#include <iostream>

using namespace std;

void main()
{
	int number;
	printf("����(����)�� �Է����ּ���: ");
	scanf_s("%d", &number);
	if (number % 2 == 0)
		printf("%d��(��) ¦���Դϴ�.\n", number);
	else
		printf("%d��(��) Ȧ���Դϴ�.\n", number);
}