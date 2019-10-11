#pragma once
#include "hinh.h"
class HCN :
	public Hinh
{
private: 
	
public:
	int x1, y1, x2, y2;
	void thietlap(int x1, int y1, int x2, int y2);
	void ve(CClientDC *pdc);
	int tronghinh(CPoint p1);
	CPoint getA();
	CPoint getC();
	HCN(void);
	~HCN(void);
};

