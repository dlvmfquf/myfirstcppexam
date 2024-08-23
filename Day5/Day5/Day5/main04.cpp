#include <iostream>

using namespace std;

void main()
{
	// continue, break

	//continue - 이번 분기를 skip하고 계속 진행

	//break; 반복문 종료.


	int arr[1000] = {};
	for (int i = 0; i < 1000; i++)
	{
			arr[i] = i;
	}	


	for (int i = 0; i < 1000; i++)
	{

		if (arr[i] % 3 != 0)
		{
			continue;
		}
		else
		{
			cout << arr[i] << endl;
		}

	}

}