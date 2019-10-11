#pragma once
class Hinh
{
public:
	CPoint diem1, diem2;
	virtual void ve(CClientDC *pdc);
	virtual int tronghinh(CPoint p1);
	virtual float chuvi();
	virtual float dientich();
	Hinh(void);
	~Hinh(void);
};

