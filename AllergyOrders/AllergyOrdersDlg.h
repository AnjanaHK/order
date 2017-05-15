// AllergyOrdersDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
//#include "resource.h"
#include "afxcmn.h"
#include "AllergyDisplayDlg.h"
#include "SearchPatientDlg.h"
#include "SearchDrugDlg.h"
#include "InputValidator.h"
// CAllergyOrdersDlg dialog
class CAllergyOrdersDlg : public CDialogEx
{
private:
	CArray<CPatient, CPatient&> m_patientArray;
	CArray<CDrug, CDrug&> m_drugArray;

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
	CEdit m_patientEdt;
	CEdit m_drugEdt;
	CDateTimeCtrl m_dateDTCtrl;
	CListCtrl m_orderLstCtrl;
	
	CEdit m_commentCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton3();
	static int g_nDrugRecordSize;
	static int g_nPatientRecordSize;
	CMFCButton m_searchDrugBtn;
	CMFCButton m_addBtn;
	virtual void OnOK();
	CButton m_orderBtn;
	CMFCButton m_searchPatientBtn;
	CFont m_font;
	afx_msg void OnEnChangeEdit2();
	CMFCButton m_removeBtn;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
};
