
// AllergyOrdersDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
//#include "resource.h"
#include "OrdersGlobal.h"
#include "afxcmn.h"
#include "AllergyDisplay.h"
// CAllergyOrdersDlg dialog
class CAllergyOrdersDlg : public CDialogEx
{
// Construction
public:
	
	CAllergyOrdersDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALLERGYORDERS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	CEdit patientCntrl;
	CEdit drugCntrl;
	CDateTimeCtrl dateCntrl;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_orderList;
	afx_msg void OnBnClickedButton3();
	Patient patient;
	Drug drug;
};
