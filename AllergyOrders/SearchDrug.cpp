// SearchDrug.cpp : implementation file
//

#include "stdafx.h"
#include "AllergyOrders.h"
#include "SearchDrug.h"
#include "afxdialogex.h"
#include "orderService.h"

// SearchDrug dialog

IMPLEMENT_DYNAMIC(SearchDrug, CDialogEx)

SearchDrug::SearchDrug(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

SearchDrug::~SearchDrug()
{
}

void SearchDrug::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, drugListCntrl);
}


BEGIN_MESSAGE_MAP(SearchDrug, CDialogEx)
	ON_BN_CLICKED(IDOK, &SearchDrug::OnBnClickedOk)
END_MESSAGE_MAP()


// SearchDrug message handlers


void SearchDrug::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}



BOOL SearchDrug::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	Drug* d;
	orderService os;
	d = os.searchDrug(drugName);
	CString text;
	text.Format(L"%d", d[0].getDrugId());
	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = _T("Drug ID");
	drugListCntrl.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 200;
	lvColumn.pszText = _T("Name");
	drugListCntrl.InsertColumn(1, &lvColumn);
	LVITEM lvItem;
	int nItem;

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = 0;
	lvItem.iSubItem = 0;
	lvItem.pszText = text.GetBuffer();
	nItem = drugListCntrl.InsertItem(&lvItem);

	drugListCntrl.SetItemText(nItem, 1, d[0].getDrugName());
	drug = d[0];
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

