//main 함수가 하나만 존재하는 main.cpp 파일 안

#include <iostream>
#include "CStudent.h"
using namespace std;
/*
패턴1: 멤버 변수가 포인터인 경우: 즉,
class 클래스이름
{
private: 자료형(클래스 이름 포함)*포인터이름;
}
패턴2: main 함수 또는 다른 함수에서 포인터 선언해서 사용하는 경우
int main()
{
	자료형(클래스 이름 포함)*포인터이름;
}
패턴1 사용한 경우
 - 학생 수 5 고정되어 있는 경우 -> int stud[5];
 - 반면 학생 수가 수시로 변하는 경우, 포인터 사용하는 것이 더 효율적
 - 즉, 메모리 공간의 낭비 또는 부족 현상을 없앨 수 있기 때문
*/

int main()
{
	CStudent students;

	students.setarr();

	return 0;
}

