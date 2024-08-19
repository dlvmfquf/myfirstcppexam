#include <iostream>

using namespace std;


void main()
{
	srand(time(NULL));

	int playerWinRate = 1 + (rand() % 99);
	int goblinLv = 1, playerLv = 1;
	float goblinWinRate = 100 * (goblinLv /(float)(1 + playerLv * 2));


	// 배열, 반복문

	/*
	카멜 케이스 습관 들이기
	myName

	스네이크
	my_name

	파스칼
	MyName

	헝가리안
	맨 앞에 자료형이 뭔지 붙여주는 케이스
	int iMyName;
	int m_ImyName;
	이제 기능 발달로 굳이 쓸 필요가 없음
	*/
	

}