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
END_MESSAGE_MAP()


// AllergyDisplay message handlers


BOOL AllergyDisplay::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	int arraySize;
	arraySize = os.listPatientDrugInteraction(patient.getPatientId(), drug.getDrugId());
	LVCOLUMN lvColumn;

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
	for (int i = 0; i < arraySize; i++)
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
	arraySize = os.listDrugDrugInteraction(drug.getDrugId());
	for (int i = 0; i < arraySize; i++)
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



	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
