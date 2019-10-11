
// KeoThaTronView.h : interface of the CKeoThaTronView class
//

#pragma once
#include"HCN.h"
#include"Hinh.h"
#include"Tron.h"
#include"NutBam.h"

class CKeoThaTronView : public CView
{
protected: // create from serialization only
	CKeoThaTronView();
	DECLARE_DYNCREATE(CKeoThaTronView)

// Attributes
public:
	CKeoThaTronDoc* GetDocument() const;

// Operations
public:
	NutBam ve,xoa,mau1,mau2,mau3,mau4,khung1;
	Tron ht1;
	CClientDC *pdc;
	CPoint p1, p2;
	int n;
	int chon;
	int mau;
	Hinh *hinh[30];
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CKeoThaTronView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in KeoThaTronView.cpp
inline CKeoThaTronDoc* CKeoThaTronView::GetDocument() const
   { return reinterpret_cast<CKeoThaTronDoc*>(m_pDocument); }
#endif

