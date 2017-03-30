
// AllergyOrders.h : main header file for the PROJECT_NAME application
//
#include "stdafx.h"
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "CPatient.h"
#include "CDrug.h"

// CAllergyOrdersApp:
// See AllergyOrders.cpp for the implementation of this class
//

class CAllergyOrdersApp : public CWinApp
{
public:

	CAllergyOrdersApp();
	CArray<CPatient, CPatient&> m_patientArray;
	CArray<CDrug, CDrug&> m_drugArray;
	CArray<CString, CString&> m_severity;
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CAllergyOrdersApp theApp;