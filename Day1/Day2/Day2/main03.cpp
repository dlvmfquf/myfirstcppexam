#include <iostream>

using namespace std;

void main()
{

	int year = 0;
	printf("������ �Է����ּ���: ");
	scanf_s("%d", &year);
	printf("���� �⵵: %d\n", year);

	char name[100] = "";
	printf("�̸��� �Է����ּ���: ");
	scanf_s("%s", name, (int)sizeof(name));
	printf("�̸�: %s\n", name);

}