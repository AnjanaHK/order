#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "Drug.h"

// SearchDrug dialog

class SearchDrug : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDrug)

public:
	
	SearchDrug(CWnd* pParent = NULL);   // standard constructor
	virtual ~SearchDrug();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void SearchDrug::OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl drugListCntrl;
	CString drugName;
	Drug drug;

};
