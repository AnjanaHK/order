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
	POSITION pos = drugListCntrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
		TRACE0("No items were selected!\n");
	else
	{
		while (pos)
		{
			int nItem = drugListCntrl.GetNextSelectedItem(pos);
			TRACE1("Item %d was selected!\n", nItem);
			drug = theApp.globalDrugArray[recordSize - nItem-1];
		}
	}
	
	CDialogEx::OnOK();
}



BOOL SearchDrug::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	drugListCntrl.SetExtendedStyle(drugListCntrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	orderService os;
	recordSize = os.searchDrug(drugName);

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
	for (int i = 0; i < recordSize; i++)
	{
		CString text;
		text.Format(L"%d", theApp.globalDrugArray[i].getDrugId());
		LVITEM lvItem;
		int nItem;

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = 0;
		lvItem.iSubItem = 0;
		lvItem.pszText = text.GetBuffer();
		nItem = drugListCntrl.InsertItem(&lvItem);

		drugListCntrl.SetItemText(nItem, 1, theApp.globalDrugArray[i].getDrugName());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

