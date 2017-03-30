#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "CPatient.h"
#include "CDrug.h"
#include "CDBConnection.h"
#include "COrderService.h"
#include "AllergyOrders.h"
// AllergyDisplayDlg dialog

class AllergyDisplayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AllergyDisplayDlg)

public:
	AllergyDisplayDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AllergyDisplayDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

private:
	CArray<CPatient, CPatient&> m_patientArray;
	CArray<CDrug, CDrug&> m_drugArray;
	COrderService m_orderService;
	CDBConnection m_connection;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_patientIdEdt;
	CEdit m_patientNameEdt;
	CListCtrl m_patientAllergyLstCtrl;
	virtual BOOL OnInitDialog();
	CEdit m_drugIdEdt;
	CEdit m_drugNameEdt;
	CPatient m_patient;
	CDrug m_drug;
	CListCtrl m_drugAllergyLstCtrl;
	afx_msg void OnBnClickedOk();
	virtual INT_PTR DoModal(CArray<CDrug, CDrug&> &drugArray, CArray<CPatient, CPatient&> &patientArray);
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCancel();
};
