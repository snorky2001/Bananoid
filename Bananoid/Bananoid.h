// Bananoid.h : main header file for the Bananoid application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"

// CBananoidApp:
// See Bananoid.cpp for the implementation of this class
//

class CBananoidApp : public CWinApp
{
public:
	CBananoidApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
public:
	afx_msg void OnAppAbout();

	DECLARE_MESSAGE_MAP()
};

extern CBananoidApp theApp;
