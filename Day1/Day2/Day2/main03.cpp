#include <iostream>

using namespace std;

void main()
{

	int year = 0;
	printf("연도를 입력해주세요: ");
	scanf_s("%d", &year);
	printf("현재 년도: %d\n", year);

	char name[100] = "";
	printf("이름을 입력해주세요: ");
	scanf_s("%s", name, (int)sizeof(name));
	printf("이름: %s\n", name);

}