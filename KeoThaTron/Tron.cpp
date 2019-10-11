#include "StdAfx.h"
#include "Tron.h"
#include "math.h"

Tron::Tron(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

Tron::Tron(CPoint p1, CPoint p2)
{
	diem1.x = p1.x;
	diem1.y = p1.y;
	diem2.x = p2.x;
	diem2.y = p2.y;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
}

void Tron::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void Tron::ve(CClientDC *pDC)
{
	pDC->Ellipse(x1, y1, x2, y2);
}

CPoint Tron::getA()
{
	return CPoint(x1, y1);
}

CPoint Tron::getC()
{
	return CPoint(x2, y2);
}

int Tron::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}
float Tron::dientich()
{
	float kq;
	kq = (sqrt((x2 - x1)*(x2 - x1))+((y2 - y1)*(y2 - y1))/2) *(sqrt((x2 - x1)*(x2 - x1))+((y2 - y1)*(y2 - y1))/2) * 3.14;
	return kq;
}

float Tron::chuvi()
{
	int kq;
	kq = (sqrt((x2 - x1)*(x2 - x1))+((y2 - y1)*(y2 - y1))/2) * 2 * 3.14;
	return kq;
}
Tron::Tron(void)
{
}


Tron::~Tron(void)
{
}
