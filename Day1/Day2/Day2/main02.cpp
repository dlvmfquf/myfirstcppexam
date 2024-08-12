#include <iostream>

using namespace std;

void main()
{
	int year = 05;
	char name[100] = "이플별";
	char phone[100] = "삼성";
	float height = 172.7;
	char hometown[100] = "수원";

	/*
	정수 - %d
	실수 - %f
	문자열 - %s
	문자 - %c
	*/
	printf("year: %d, name: %s, phone: %s, height: %.1f, place: %s", year, name, phone, height, hometown);
}