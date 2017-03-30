#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "CDrug.h"

// SearchDrugDlg dialog

class SearchDrugDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDrugDlg)

public:
	
	SearchDrugDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SearchDrugDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif
private: 

	int m_nRecordSize;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_sDrugName;
	CDrug m_drug;
	void SearchDrugDlg::OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_drugLstCtrl;
	
};
