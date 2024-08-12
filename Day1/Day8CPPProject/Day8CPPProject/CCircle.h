#pragma once
class CCircle
{
	//원의 반지름을 갖는 멤버 변수인 m_radius를 선언 및 초기화
private: 
	int m_radius = 0;
	//기본 생성자(매개 변수가 없는 생성자)의 머리 부분만 작성
public:
	CCircle();
	//함수중복 개념을 사용해서 매개변수를 갖는 생성자의 머리 부분만을 작성
	CCircle(int radius);
	//m_radius의 값을 바꾸고 싶을 때 쓰는 멤버 함수를 추가
	void setradius(int newradius);
	//멤버 변수인 m_radius의 현제 값을 읽고 싶을 때 쓰는 멤버 함수 추가
	//문법: 반환형(멤버 변수의 자료형과 일치해야 함) get+멤버변수이름();
	int getradius();

};

