#pragma once
#include <iostream>

using namespace std;

class CStudent
{
private:int m_count = 0;
	//무조건 학생 수가 5로 고정되어 있는 배열 선언
	//학생 번호는 정수 사용
private:int m_studentno[5];

	//생성자를 정의해서 위에서 선언한 배열에 5명 학생의 번호 저장
	//번호를 저장하지 않으면 다른 프로그램에서 사용했던 알 수 없는 값이 저장
	
	//학생 수가 가변적으로 변하는 경우 - 포인터 변수 사용
private:int* m_parr = NULL;
	   //NULL -> 주소값

public: 
	CStudent()
	{
		//for 반복문을 사용해서 배열 m_studentno에 5명 학생의 번호를 정수로 저장
		//1, 2, 3, 4, 5

		for (int i = 0; i < 5; i++)
		{
			m_studentno[i] = i + 1;
			cout << "배열의 인덱스: " << i << ", 학생의 번호: " << m_studentno[i] << endl;
		}

		//위에서 선언한 m_parr 포인터 변수와 사용자로부터 학생 수를 키보드로 입력 받아
		//프로그램이 실행하는 중간에 배열 공간 생성
		int count;

		cout << "학생 수가 몇명인가요? ";
		cin >> count;
		if (count <= 0)
		{
			cout << "입력하신 학생 수는 0이하네요~ 내맘대로 5명으로 하겠습니다~" << endl;
			m_parr = new int[5];
			m_count = 5;
			cout << "새로 생성한 배열의 시작 주소는 " << m_parr << endl;
		}
		else 
		{
			cout << "사용자가 입력한 학생 수는 " << count << endl;
			m_parr = new int[count];
			m_count = count;
			cout << "학생 수 만큼의 메모리 공간을 갖는 배열을 만들었습니다."<< endl;
			cout << "배열의 시작 주소는 " << m_parr << endl;
		}
	}
	~CStudent();
	/*
		멤버 함수 새로 추가
		수행할 기능 - m_parr 가 가리키는 배열 메모리 공간에 값 저장
		- 아까 생성자에서 new 연산자를 수행한 후 바로 값 저장,
		또는 새로운 멤버 함수를 정의해서 배열 메모리 공간에 값을 저장
		new 연산을 수행했을 때, 변수 count의 값을 멤버변수에 저장해야함
		2. 함수의 이름은 기능과 밀접한 관련이 있어야함
		3. 반환형은 void(기준은 값을 만들지 않는 경우)
		4. 함수의 매개변수 없음
	*/
	void setarr();

};

