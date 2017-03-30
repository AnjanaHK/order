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
	DDX_Control(pDX, IDC_LIST3, m_patientLstCtrl);
}


BEGIN_MESSAGE_MAP(SearchPatientDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SearchPatientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &SearchPatientDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// SearchPatientDlg message handlers
/*
The following method is called when ok button is clicked.
#1. If an item is selected then it is mapped to global variable-m_pPatient
#2. Else a message box is displayed requesting the user to select an item or cancel the search.
*/

void SearchPatientDlg::OnBnClickedOk()
{
	
	POSITION pos = m_patientLstCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("No patient was selected. Please select a patient from the list or cancel the search."));
		return;
	}
	else
	{
			int nItem = m_patientLstCtrl.GetNextSelectedItem(pos);
			m_patient = theApp.m_patientArray[m_nRecordSize - nItem];
	}
	CDialogEx::OnOK();
}


void SearchPatientDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}

/*
This method is called to initialize the dialog.
Here the patient list displaying patients whose name match with the text entered in AllergyOrderDlg Dialog is loaded with headers
and data.
When DoModal() is called the dialog will be displayed with preloaded data and user has to select any one of the patient from the list.

*/
BOOL SearchPatientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_patientLstCtrl.SetExtendedStyle(m_patientLstCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	COrderService orderService;
	m_nRecordSize = orderService.SearchPatient(m_sPatientName,true);
	m_patientLstCtrl.InsertColumn(0, _T("Patient ID"),LVCFMT_LEFT,150); //set list
	m_patientLstCtrl.InsertColumn(1, _T("Name"), LVCFMT_LEFT,200);
	for(int i=1;i<=m_nRecordSize;i++) 
	{
		int nItem;
		CString text;
		text.Format(_T("%d"), theApp.m_patientArray[i].GetPatientId());
		nItem = m_patientLstCtrl.InsertItem(0, text);
		m_patientLstCtrl.SetItemText(nItem, 1, theApp.m_patientArray[i].GetPatientName());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


