#include "CCircle.h"

//CCircle();
CCircle::CCircle()
{
	m_radius = 1;
}

//CCircle(int radius);
CCircle::CCircle(int radius)
{
	m_radius = radius;
}


//void setradius(int newradius);
void CCircle::setradius(int newradius)
{
	m_radius = newradius;
}

//int getradius();
int CCircle::getradius()
{
	return m_radius;
}


