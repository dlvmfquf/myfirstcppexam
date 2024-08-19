#include <iostream>

using namespace std;


void main()
{

	int arr[10] = {};

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	//arr에 담긴 변수 섞어보기

	srand(time(NULL));

	
	for (int i = 0; i < 100000; i++)
	{
		int firstIndex = rand() % 10;
		int secondIndex = rand() % 10;
		int temp;
		temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;

	}

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}


}