#pragma once
class CCircle
{
	//���� �������� ���� ��� ������ m_radius�� ���� �� �ʱ�ȭ
private: 
	int m_radius = 0;
	//�⺻ ������(�Ű� ������ ���� ������)�� �Ӹ� �κи� �ۼ�
public:
	CCircle();
	//�Լ��ߺ� ������ ����ؼ� �Ű������� ���� �������� �Ӹ� �κи��� �ۼ�
	CCircle(int radius);
	//m_radius�� ���� �ٲٰ� ���� �� ���� ��� �Լ��� �߰�
	void setradius(int newradius);
	//��� ������ m_radius�� ���� ���� �а� ���� �� ���� ��� �Լ� �߰�
	//����: ��ȯ��(��� ������ �ڷ����� ��ġ�ؾ� ��) get+��������̸�();
	int getradius();

};

