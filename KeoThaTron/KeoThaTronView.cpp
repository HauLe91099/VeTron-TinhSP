
// KeoThaTronView.cpp : implementation of the CKeoThaTronView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "KeoThaTron.h"
#endif

#include "KeoThaTronDoc.h"
#include "KeoThaTronView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeoThaTronView

IMPLEMENT_DYNCREATE(CKeoThaTronView, CView)

BEGIN_MESSAGE_MAP(CKeoThaTronView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CKeoThaTronView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CKeoThaTronView construction/destruction

CKeoThaTronView::CKeoThaTronView()
{
	// TODO: add construction code here
	ve.thietlap(0, 0, 80, 50);
	ve.chu = CString("VeHinh");
	xoa.thietlap(80, 0, 161, 50);
	xoa.chu = CString("XoaHinh ");
	mau1.thietlap(161, 0, 186, 25);
	mau2.thietlap(186, 0, 211, 25);
	mau3.thietlap(161, 25, 186, 50);
	mau4.thietlap(186, 25, 211, 50);
	khung1.thietlap(0, 0, 2000, 50);
	n = 0;
	mau = 0;
}

CKeoThaTronView::~CKeoThaTronView()
{
}

BOOL CKeoThaTronView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CKeoThaTronView drawing

void CKeoThaTronView::OnDraw(CDC* /*pDC*/)
{
	CKeoThaTronDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);

	khung1.ve(pdc);
	CPen *pen;
	CPen *pen1;
	CBrush *nen;
	CBrush *nen1;
	CBrush *nen2;
	CPen *pen2;
	CPen *pen3;
	CBrush *nen3;
	CPen *pen4;
	CBrush *nen4;
	CPen *pen5;
	CBrush *nen5;
	
	pen1 = new CPen(PS_SOLID, 2, RGB(0, 0, 0));
	pen2 = new CPen(PS_SOLID, 2, RGB(255, 0, 0));
	pen3 = new CPen(PS_SOLID, 2, RGB(0, 0, 255));
	pen4 = new CPen(PS_SOLID, 2, RGB(0, 255, 0));
	pen5 = new CPen(PS_SOLID, 2, RGB(255, 0, 255));

	nen1 = new CBrush(RGB(255,255,255));
	nen2 = new CBrush(RGB(255, 0, 0));
	nen3 = new CBrush(RGB(0, 0, 255));
	nen4 = new CBrush(RGB(0, 255, 0));
	nen5 = new CBrush(RGB(255, 0, 255));

	ve.ve(pdc);
	xoa.ve(pdc);

	pen = pdc->SelectObject(pen2);
	nen = pdc->SelectObject(nen2);
	mau1.ve(pdc);

	pen = pdc->SelectObject(pen3);
	nen = pdc->SelectObject(nen3);
	mau2.ve(pdc);

	pen = pdc->SelectObject(pen4);
	nen = pdc->SelectObject(nen4);
	mau3.ve(pdc);

	pen = pdc->SelectObject(pen5);
	nen = pdc->SelectObject(nen5);
	mau4.ve(pdc);

	nen = pdc->SelectObject(nen1);

	// TODO: add draw code for native data here
}


// CKeoThaTronView printing


void CKeoThaTronView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CKeoThaTronView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKeoThaTronView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKeoThaTronView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CKeoThaTronView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CKeoThaTronView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CKeoThaTronView diagnostics

#ifdef _DEBUG
void CKeoThaTronView::AssertValid() const
{
	CView::AssertValid();
}

void CKeoThaTronView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeoThaTronDoc* CKeoThaTronView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeoThaTronDoc)));
	return (CKeoThaTronDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeoThaTronView message handlers


void CKeoThaTronView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x<2000 && point.x>100 && point.y<1000 && point.y>100)
	{
		p1.x = point.x;
		p1.y = point.y;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CKeoThaTronView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.y > 100 && point.x > 100)
	{
		p2.x = point.x;
		p2.y = point.y;
	}
	CPen *pen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen *pen2;
	pen2 = new CPen(PS_SOLID, 2, RGB(255, 0, 0));
	CPen *pen3;
	pen3 = new CPen(PS_SOLID, 2, RGB(0, 0, 255));
	CPen *pen4;
	pen4 = new CPen(PS_SOLID, 2, RGB(0, 255, 0));
	CPen *pen5;
	pen5 = new CPen(PS_SOLID, 2, RGB(255, 0, 255));

	if (ve.tronghinh(point) == 1)
	{
		chon = 1;
		pen = pdc->SelectObject(pen2);
		ve.ve(pdc);
	
		pen = pdc->SelectObject(pen1);
		xoa.ve(pdc);
	}
	else
		if (xoa.tronghinh(point) == 1)
		{
			chon = 2;
			pen = pdc->SelectObject(pen2);
			xoa.ve(pdc);

			pen = pdc->SelectObject(pen1);
			ve.ve(pdc);
		}

		else
			if (mau1.tronghinh(point) == 1)
			{
				pen = pdc->SelectObject(pen2);
			}
			else
				if (mau2.tronghinh(point) == 1)
				{
					pen = pdc->SelectObject(pen3);
				}
				else
				if (mau3.tronghinh(point) == 1)
				{
					pen = pdc->SelectObject(pen4);
				}
				else
					if (mau4.tronghinh(point) == 1)
					{
						pen = pdc->SelectObject(pen5);
					}
					else
						if (chon == 1)
						{
							hinh[n] = new Tron(p1, p2);
							hinh[n]->ve(pdc);
							n++;
						}
						else
							if(chon == 2)
							{
								int i;
								CPen *pen;
								CBrush *nen;
								CPen *pen1;
								pen1 = new CPen(PS_SOLID, 2, RGB(255, 255, 255));
								for (i = 0; i < n; i++)
								{
									if (hinh[i]->tronghinh(point) == 1)
									{
										pen = pdc->SelectObject(pen1);
										hinh[i]->ve(pdc);
										break;
									}
								}

							}
	CView::OnLButtonUp(nFlags, point);
}


void CKeoThaTronView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	int i;
	CString dt,cv;
	CString sts;
	sts = "Dien tich:";
	CString stc;
	stc = "Chu vi:";
	for (i = 0; i < n; i++)
	{
		dt.Format(_T("%f"), hinh[i]->dientich());
		cv.Format(_T("%f"), hinh[i]->chuvi());
		pdc->TextOutW(400, 25, sts);
		pdc->TextOutW(480, 25, dt);
		pdc->TextOutW(620, 25, stc);
		pdc->TextOutW(680, 25, cv);
		break;
	}
	CView::OnLButtonDblClk(nFlags, point);
}
