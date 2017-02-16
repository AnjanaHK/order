// AllergyDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "AllergyOrders.h"
#include "AllergyDisplay.h"
#include "afxdialogex.h"


// AllergyDisplay dialog

IMPLEMENT_DYNAMIC(AllergyDisplay, CDialogEx)

AllergyDisplay::AllergyDisplay(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

AllergyDisplay::~AllergyDisplay()
{
}

void AllergyDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_PatientID);
	DDX_Control(pDX, IDC_EDIT2, m_patientName);
	DDX_Control(pDX, IDC_LIST1, m_patientAllergyList);
	DDX_Control(pDX, IDC_EDIT3, m_DrugId);
	DDX_Control(pDX, IDC_EDIT4, m_DrugName);
	DDX_Control(pDX, IDC_LIST2, m_drugAllergyList);
}


BEGIN_MESSAGE_MAP(AllergyDisplay, CDialogEx)
	ON_BN_CLICKED(IDOK, &AllergyDisplay::OnBnClickedOk)
END_MESSAGE_MAP()


// AllergyDisplay message handlers


BOOL AllergyDisplay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CString id;
	id.Format(L" %d", patient.getPatientId());
	m_PatientID.SetWindowTextW(id);
	m_patientName.SetWindowTextW(patient.getPatientName());
	id.Format(L" %d", drug.getDrugId());
	m_DrugId.SetWindowTextW(id);
	m_DrugName.SetWindowTextW(drug.getDrugName());

	LVCOLUMN lvColumn;
	int parraySize=0;
	parraySize = os.listPatientDrugInteraction(patient.getPatientId(), drug.getDrugId());
	if (parraySize > 0)
	{
		

		lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_LEFT;
		lvColumn.cx = 120;
		lvColumn.pszText = _T("Drug ID");
		m_patientAllergyList.InsertColumn(0, &lvColumn);

		lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_LEFT;
		lvColumn.cx = 200;
		lvColumn.pszText = _T("Name");
		m_patientAllergyList.InsertColumn(1, &lvColumn);

		lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_LEFT;
		lvColumn.cx = 200;
		lvColumn.pszText = _T("Severity");
		m_patientAllergyList.InsertColumn(2, &lvColumn);
		for (int i = 0; i < parraySize; i++)
		{
			LVITEM lvItem;
			int nItem;
			CString text;
			text.Format(L"%d", theApp.globalDrugArray[i].getDrugId());
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = 0;
			lvItem.iSubItem = 0;
			lvItem.pszText = text.GetBuffer();
			nItem = m_patientAllergyList.InsertItem(&lvItem);

			m_patientAllergyList.SetItemText(nItem, 1, theApp.globalDrugArray[i].getDrugName());
			m_patientAllergyList.SetItemText(nItem, 2, theApp.severity[i]);
		}
	}
	int darraySize = os.listDrugDrugInteraction(drug.getDrugId());
	if(darraySize>0)
	{
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 120;
	lvColumn.pszText = _T("Drug ID");
	m_drugAllergyList.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 200;
	lvColumn.pszText = _T("Name");
	m_drugAllergyList.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 200;
	lvColumn.pszText = _T("Severity");
	m_drugAllergyList.InsertColumn(2, &lvColumn);

	for (int i = 0; i < darraySize; i++)
	{
		LVITEM lvItem;
		int nItem;
		CString text;
		text.Format(L"%d", theApp.globalDrugArray[i].getDrugId());
		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = 0;
		lvItem.iSubItem = 0;
		lvItem.pszText = text.GetBuffer();
		nItem = m_drugAllergyList.InsertItem(&lvItem);

		m_drugAllergyList.SetItemText(nItem, 1, theApp.globalDrugArray[i].getDrugName());
		m_drugAllergyList.SetItemText(nItem, 2, theApp.severity[i]);
	}

	}
	if(parraySize==0 && darraySize==0)
	{
		CDialogEx::OnOK();
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void AllergyDisplay::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CDialogEx::OnOK();
}
