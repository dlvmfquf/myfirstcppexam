#include <iostream>

using namespace std;

void main()
{
	int year = 05;
	char name[100] = "���ú�";
	char phone[100] = "�Ｚ";
	float height = 172.7;
	char hometown[100] = "����";

	/*
	���� - %d
	�Ǽ� - %f
	���ڿ� - %s
	���� - %c
	*/
	printf("year: %d, name: %s, phone: %s, height: %.1f, place: %s", year, name, phone, height, hometown);
}