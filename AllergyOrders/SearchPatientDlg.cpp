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
	int i= 0;
	//vector<Patient> p;
	Patient* p;
	orderService os;
	p = os.searchPatient(name);
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
	//for(Patient pat : p) 
	//{
		CString text;
		text.Format(L"%d", p[0].getPatientId());
		//text.Append(p[0].getPatientName());
		//searchCntrl.SetWindowText(text);
		
		LVITEM lvItem;
		int nItem;

		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = 0;
		lvItem.iSubItem = 0;
		lvItem.pszText = text.GetBuffer();
		nItem = patientList.InsertItem(&lvItem);

		patientList.SetItemText(nItem, 1, p[0].getPatientName());
	//}
	patient = p[0];
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


