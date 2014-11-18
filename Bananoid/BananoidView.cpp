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

#include <Box2D/Box2D.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBananoidView

IMPLEMENT_DYNCREATE(CBananoidView, CView)

BEGIN_MESSAGE_MAP(CBananoidView, CView)
  	ON_WM_MOUSEMOVE()
    ON_WM_TIMER()
END_MESSAGE_MAP()

// CBananoidView construction/destruction

CBananoidView::CBananoidView(): m_BottomSpacer(30), gravity(0.0f, -10.0f), world(gravity)
{
	// TODO: add construction code here
  m_Timer = NULL;
}

CBananoidView::~CBananoidView()
{
  KillTimer(IDT_TIMER_0);
}

BOOL CBananoidView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

  // Box2D engine test

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 60.0f);
	body = world.CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.0f;

  fixtureDef.restitution = 0.9f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	b2BodyDef groundBodyPad;
	groundBodyPad.position.Set(0.0f, 10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* bodyPad = world.CreateBody(&groundBodyPad);

	// Define the ground box shape.
	b2PolygonShape padBox;

	// The extents are the half-widths of the box.
	padBox.SetAsBox(0.0f, 0.0f);

	// Add the ground fixture to the ground body.
	bodyPad->CreateFixture(&padBox, 0.0f);

  

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

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

  // The extents are the half-widths of the box.
//    b2Vec2 pos(m_ptPlayer.x, m_ptPlayer.y);
//  	bodyPad->SetTransform(pos, 0);;

	// This is our little game loop.
//	for (int32 i = 0; i < 60; ++i)
	{
		// Instruct the world to perform a single step of simulation.
		// It is generally best to keep the time step and iterations fixed.
		world.Step(timeStep, velocityIterations, positionIterations);

		// Now print the position and angle of the body.
		b2Vec2 position = body->GetPosition();
    float32 angle = body->GetAngle();

    float ratio = (m_Table.bottom - m_Table.top) / 100;
    position.x = (ratio*position.x) + m_Table.right/2;
    position.y = m_Table.bottom - (ratio*position.y);

    pDC->Rectangle( position.x-ratio , position.y - ratio, position.x + ratio, position.y + ratio);
		printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}

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
/*
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

*/

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
  if (m_Timer == NULL)
    m_Timer = SetTimer(IDT_TIMER_0, 10, NULL);

	m_ptPlayer = point;
 // Invalidate();
}

void CBananoidView::OnTimer (UINT TimerVal)
{
  Invalidate();
  CView::OnTimer(TimerVal);
}
