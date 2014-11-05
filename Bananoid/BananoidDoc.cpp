// BananoidDoc.cpp : implementation of the CBananoidDoc class
//

#include "stdafx.h"
#include "Bananoid.h"

#include "BananoidDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBananoidDoc

IMPLEMENT_DYNCREATE(CBananoidDoc, CDocument)

BEGIN_MESSAGE_MAP(CBananoidDoc, CDocument)
END_MESSAGE_MAP()

// CBananoidDoc construction/destruction

CBananoidDoc::CBananoidDoc()
{
	// TODO: add one-time construction code here

}

CBananoidDoc::~CBananoidDoc()
{
}

BOOL CBananoidDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// CBananoidDoc serialization


void CBananoidDoc::Serialize(CArchive& ar)
{
	(ar);
}



// CBananoidDoc diagnostics

#ifdef _DEBUG
void CBananoidDoc::AssertValid() const
{
	CDocument::AssertValid();
}
#endif //_DEBUG


// CBananoidDoc commands

