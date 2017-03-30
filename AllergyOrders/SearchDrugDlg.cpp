// SearchDrugDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AllergyOrders.h"
#include "SearchDrugDlg.h"
#include "afxdialogex.h"
#include "COrderService.h"

// SearchDrugDlg dialog

IMPLEMENT_DYNAMIC(SearchDrugDlg, CDialogEx)

SearchDrugDlg::SearchDrugDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

SearchDrugDlg::~SearchDrugDlg()
{
}

void SearchDrugDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_drugLstCtrl);
}


BEGIN_MESSAGE_MAP(SearchDrugDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SearchDrugDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SearchDrugDlg message handlers

/*
The following method is called when ok button is clicked.
#1. If an item is selected then it is mapped to global variable-m_pDrug
#2. Else a message box is displayed requesting the user to select an item or cancel the search.
*/

void SearchDrugDlg::OnBnClickedOk()
{
	POSITION pos = m_drugLstCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("No drug was selected. Please select a drug or cancel the search."));
		return;
	}
	else
	{
			int nItem = m_drugLstCtrl.GetNextSelectedItem(pos);
			m_drug = theApp.m_drugArray[m_nRecordSize - nItem];
	}
	
	CDialogEx::OnOK();
}


/*
This method is called to initialize the dialog.
Here the drug list displaying drugs whose name match with the text entered in AllergyOrderDlg Dialog is loaded with headers
and data.
When DoModal() is called the dialog will be displayed with preloaded data and user has to select any one of the drug from the list.

*/
BOOL SearchDrugDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_drugLstCtrl.SetExtendedStyle(m_drugLstCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	COrderService orderService;
	m_nRecordSize = orderService.SearchDrug(m_sDrugName,true);

	m_drugLstCtrl.InsertColumn(0, _T("Drug ID"), LVCFMT_LEFT, 150);
	m_drugLstCtrl.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 200);
	for (int i = 1; i <= m_nRecordSize; i++)
	{
		int nItem;
		CString stext;
		stext.Format(_T("%d"), theApp.m_drugArray[i].GetDrugId());
		nItem = m_drugLstCtrl.InsertItem(0, stext);
		m_drugLstCtrl.SetItemText(nItem, 1, theApp.m_drugArray[i].GetDrugName());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

