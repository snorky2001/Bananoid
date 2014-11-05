// BananoidView.cpp : implementation of the CBananoidView class
//

#include "stdafx.h"
#include "Bananoid.h"

#include "BananoidDoc.h"
#include "BananoidView.h"

#include <vector>
#include <algorithm>
#include <functional>

#include "Item.h"
#include "Ball.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBananoidView

IMPLEMENT_DYNCREATE(CBananoidView, CView)

BEGIN_MESSAGE_MAP(CBananoidView, CView)
  	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CBananoidView construction/destruction

CBananoidView::CBananoidView(): m_BottomSpacer(30)
{
	// TODO: add construction code here

}

CBananoidView::~CBananoidView()
{
}

BOOL CBananoidView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}


// CBananoidView drawing
void CBananoidView::OnDraw(CDC* pDC)
{
	CBananoidDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

  GetClientRect(&m_Table);

  unsigned int x, y;
  x = m_ptPlayer.x;
  y = m_Table.bottom - m_BottomSpacer;

  pDC->Rectangle(x-20 , y - 5, x + 20, y + 5);


  /*
  http://mykbn.wordpress.com/2013/06/24/double-buffering-technique-in-mfc-for-flicker-free-drawing/
  +
  HDC hDC,                  // Handle to the display device context 
      hDCMem;               // Handle to the memory device context
  HBITMAP hBitmap;          // Handle to the new bitmap
  int iWidth, iHeight;      // Width and height of the bitmap
  // Retrieve the handle to a display device context for the client 
  // area of the window. 
  hDC = GetDC (hwnd);
  // Create a memory device context compatible with the device. 
  hDCMem = CreateCompatibleDC (hDC);
  // Retrieve the width and height of window display elements.
  iWidth = GetSystemMetrics (SM_CXSCREEN) / 10;
  iHeight = GetSystemMetrics (SM_CYSCREEN) / 10;
  // Create a bitmap compatible with the device associated with the 
  // device context.
  hBitmap = CreateCompatibleBitmap (hDC, iWidth, iHeight);
// Insert code to use the bitmap.
  // Delete the bitmap object and free all resources associated with it. 
  DeleteObject (hBitmap);
  // Delete the memory device context and the display device context.
  DeleteDC (hDCMem);
  ReleaseDC (hDC);
  */

  // Init
  DWORD simulationTime, displayTime;
  simulationTime = 0;
  displayTime = 0;

  std::vector<CItem *> movableItems;
  std::vector<CItem *> drawableItems;
  std::vector<CItem *> collisionItems;

  CItem ball;
  CItem paddle;
  CItem block1;
  CItem block2;

  movableItems.push_back(&ball);
  drawableItems.push_back(&ball);

  movableItems.push_back(&paddle);
  drawableItems.push_back(&paddle);
  collisionItems.push_back(&paddle);

  movableItems.push_back(&block1);
  drawableItems.push_back(&block1);
  collisionItems.push_back(&block1);

  movableItems.push_back(&block2);
  drawableItems.push_back(&block2);
  collisionItems.push_back(&block2);
  
  unsigned int step = 10;

  // Main loop
  simulationTime = GetTickCount();
  while (simulationTime < displayTime)
  {
    // Update state
    std::for_each ( movableItems.begin(), movableItems.end(), std::bind2nd( std::mem_fun(&CItem::Run), step) );

    // Check for collision
    ball.Collide(collisionItems);

    simulationTime ++;
  }

  // Update Draw
  std::for_each ( drawableItems.begin(), drawableItems.end(), std::mem_fun(&CItem::Draw) );
  displayTime = GetTickCount();
}



// CBananoidView diagnostics

#ifdef _DEBUG
void CBananoidView::AssertValid() const
{
	CView::AssertValid();
}

CBananoidDoc* CBananoidView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBananoidDoc)));
	return (CBananoidDoc*)m_pDocument;
}
#endif //_DEBUG


// CBananoidView message handlers
void CBananoidView::OnMouseMove(UINT nFlags, CPoint point) 
{
	m_ptPlayer = point;
  Invalidate();
}