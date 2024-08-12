//현재 소스 파일 이름: CStudent.cpp
#include "CStudent.h"

//void setarr 멤버함수 구현
// 함수의 반환형 클래스이름:: 함수이름(매개변수 선언) {}
void CStudent::setarr()
{
	/*
		먼저 포인터 변수인 m_parr가 갖는 주소 판단,
		ㄴNULL을 가지고 있다면 값을 저장하지 못함.
		NULL이 아닌 경우 값 저장 가능
		if 조건문을 추가하지 않으면 NULL인 경우 값을 저장하려 할 때 오류 발생
	*/
	if (m_parr != NULL)
	{
		cout << "포인터 변수 m_parr가 가리키는 배열 메모리 공간에 값을 저장합니다~ \n";
		for (int i = 1; i <= m_count; i++)
		{
			cout << "학생의 번호를 정수로 입력하고 엔터키: ";
			cin >> m_parr[i - 1];
			cout << "방금 입력한 학생의 번호는 " << m_parr[i - 1] << "입니다. " << endl;
		}
	}
}





CStudent::~CStudent()
{
	/*
		delete 연산자를 사용하는 문법 2가지
		모두 new 연산자를 사용할 때 어떤 명령어를 작성했냐에 따라 다름
		- m_parr = new int; 이렇게 하나의 메모리 공간만을 만들었다면-> delete 포인터변수이름;
		- m_parr = new int[5]; 또는 m_parr = new int[count]; 명령어를 작성한 경우-> delete[]포인터변수이름;

	delete 연산자를 사용할 때, 효율적으로 처리하기 위해서 if 조건문을 추가
	- 즉, 포인터 변수인 m_parr의 초기값인 NULL이 new 연산자를 실행해서 변했는지 여부를 판단
	-NULL인 경우면 메모리를 할당받지 못한 경우이므로 메모리 해제를 하지 않음
	*/
	if (m_parr != NULL)
	{
		delete[]m_parr;
		cout << "다 쓴 배열 메모리 공간을 시스템에 반환\n";
	}
}

