#include <iostream>

using namespace std;


void main()
{
	int lotto[45];
	srand(time(NULL));
	for(int i = 0; i < 45; i++)
	{
		lotto[i] = i+1;
	}
	for (int i = 0; i < 100000; i++)
	{
		int firstIndex =  rand() % 45;
		int secondIndex = rand() % 45;
		int temp;
		temp = lotto[firstIndex];
		lotto[firstIndex] = lotto[secondIndex];
		lotto[secondIndex] = temp;
	}


	for (int i = 1; i <= 7; i++)
	{
		cout << "로또 번호" << i << ". " << lotto[i] << endl;
	}

}