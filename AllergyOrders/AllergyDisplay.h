#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Patient.h"
#include "Drug.h"
#include "DBConnection.h"
#include "orderService.h"
#include "AllergyOrders.h"
// AllergyDisplay dialog

class AllergyDisplay : public CDialogEx
{
	DECLARE_DYNAMIC(AllergyDisplay)

public:
	AllergyDisplay(CWnd* pParent = NULL);   // standard constructor
	virtual ~AllergyDisplay();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_PatientID;
	CEdit m_patientName;
	CListCtrl m_patientAllergyList;
//	CListCtrl m_drugAllergyList;
	virtual BOOL OnInitDialog();
	CEdit m_DrugId;
	CEdit m_DrugName;
	Patient patient;
	Drug drug;
	orderService os;
	DBConnection dbc;
	CListCtrl m_drugAllergyList;
	afx_msg void OnBnClickedOk();
};
