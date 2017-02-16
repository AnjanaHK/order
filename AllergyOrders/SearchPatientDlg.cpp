// SearchPatientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SearchPatientDlg.h"
#include "afxdialogex.h"
#include "resource.h"
// SearchPatientDlg dialog

IMPLEMENT_DYNAMIC(SearchPatientDlg, CDialogEx)

SearchPatientDlg::SearchPatientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

SearchPatientDlg::~SearchPatientDlg()
{
}

void SearchPatientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, patientList);
}


BEGIN_MESSAGE_MAP(SearchPatientDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SearchPatientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SearchPatientDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// SearchPatientDlg message handlers


void SearchPatientDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

}


void SearchPatientDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//this->ShowWindow(SW_HIDE);
	//ASSERT(patientList != NULL);

	POSITION pos = patientList.GetFirstSelectedItemPosition();
	if (pos == NULL)
		TRACE0("No items were selected!\n");
	else
	{
		while (pos)
		{
			int nItem = patientList.GetNextSelectedItem(pos);
			TRACE1("Item %d was selected!\n", nItem);
			patient = theApp.globalPatientArray[recordSize - nItem - 1];
		}
	}
	CDialogEx::OnOK();
}


void SearchPatientDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}




BOOL SearchPatientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	patientList.SetExtendedStyle(patientList.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	int i= 0;
	//vector<Patient> p;
	orderService os;
	recordSize = os.searchPatient(name);
	LVCOLUMN lvColumn;

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = _T("Patient ID");
	patientList.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 200;
	lvColumn.pszText = _T("Name");
	patientList.InsertColumn(1, &lvColumn);
	for(int i=0;i<recordSize;i++) 
	{
		CString text;
		text.Format(L"%d", theApp.globalPatientArray[i].getPatientId());
		//text.Append(p[0].getPatientName());
		//searchCntrl.SetWindowText(text);
		
		LVITEM lvItem;
		int nItem;

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = 0;
		lvItem.iSubItem = 0;
		lvItem.pszText = text.GetBuffer();
		nItem = patientList.InsertItem(&lvItem);

		patientList.SetItemText(nItem, 1, theApp.globalPatientArray[i].getPatientName());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


