// BananoidView.h : interface of the CBananoidView class
//


#pragma once

class CBananoidView : public CView
{
protected: // create from serialization only
	CBananoidView();
	DECLARE_DYNCREATE(CBananoidView)

// Attributes
public:
	CBananoidDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	CPoint m_ptPlayer;
  CRect  m_Table;
  const unsigned int m_BottomSpacer;

// Implementation
public:
	virtual ~CBananoidView();
#ifdef _DEBUG
	virtual void AssertValid() const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
  void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in BananoidView.cpp
inline CBananoidDoc* CBananoidView::GetDocument() const
   { return reinterpret_cast<CBananoidDoc*>(m_pDocument); }
#endif

