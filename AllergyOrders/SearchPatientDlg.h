#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "CPatient.h"
#include "COrderService.h"
// SearchPatientDlg dialog

class SearchPatientDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SearchPatientDlg)

public:

	SearchPatientDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SearchPatientDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

private:
	int m_nRecordSize;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CListCtrl m_patientLstCtrl;
	CString m_sPatientName;
	CPatient m_patient;

};
