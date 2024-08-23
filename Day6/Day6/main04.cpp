#include <iostream>


typedef int 정수;
typedef __int8 int8;
typedef __int16 int16;
typedef __int32 int32;
typedef __int64 int64;

using namespace std;

void main()
{
	//typedef - 타입을 선언해주는 역할
	// type define
	//define - 매크로 전역으로 무언가를 선언하는 역할


	정수 a = 0;
	int16 id = 103;


	//그냥 int는 21억까지밖에 담음
	//모든 변수는 RAM(메모리)에 기억함
	// 저장하려면 특정 공간을 할당 받아야함
	// int는 RAM에서 4byte만을 할당받아 씀
	// 4byte에서 표현할 수 있는 숫자의 한계가 있음
	// 컴퓨터는 모든걸 0과 1로 표현하는데, 그 0과 1은 1bit임
	// 8bit -> 1byte가 되고, 1024byte는 1kb가 됨
	// 0000 0000 -> 2진수로
	// 1111 1111 -> 0 ~ 511까지 표현함
	// 즉
	// 0000 0000 0000 0000 0000 0000 0000 0000
	//이 4byte가 표현하는 숫자의 한계임
	// 2^32-1 ->42억쯤 되는데
	// 음수도 표현해야 하므로 
	// -21억부터 21억까지임

	//__int64는 64비트짜리 정수라는 뜻



}