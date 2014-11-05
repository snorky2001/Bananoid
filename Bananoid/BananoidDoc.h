// BananoidDoc.h : interface of the CBananoidDoc class
//


#pragma once

class CBananoidDoc : public CDocument
{
protected: // create from serialization only
	CBananoidDoc();
	DECLARE_DYNCREATE(CBananoidDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();

	virtual void Serialize(CArchive& ar);


// Implementation
public:
	virtual ~CBananoidDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


