// AllergyDisplayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AllergyOrders.h"
#include "AllergyDisplayDlg.h"
#include "afxdialogex.h"


// AllergyDisplayDlg dialog

IMPLEMENT_DYNAMIC(AllergyDisplayDlg, CDialogEx)

AllergyDisplayDlg::AllergyDisplayDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

AllergyDisplayDlg::~AllergyDisplayDlg()
{
}

void AllergyDisplayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_patientIdEdt);
	DDX_Control(pDX, IDC_EDIT2, m_patientNameEdt);
	DDX_Control(pDX, IDC_LIST1, m_patientAllergyLstCtrl);
	DDX_Control(pDX, IDC_EDIT3, m_drugIdEdt);
	DDX_Control(pDX, IDC_EDIT4, m_drugNameEdt);
	DDX_Control(pDX, IDC_LIST2, m_drugAllergyLstCtrl);
}


BEGIN_MESSAGE_MAP(AllergyDisplayDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AllergyDisplayDlg::OnBnClickedOk)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &AllergyDisplayDlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDCANCEL, &AllergyDisplayDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// AllergyDisplayDlg message handlers
/*
This method is called to initialize the dialog.
Here a list displaying drugs to which patient is allergic and a list of drugs that has already been prescribed 
and can interact with current drug to cause allergy are displayed.
When DoModal() is called the dialog will be displayed with preloaded data. The user can choose to continue with
the order or cancel the order.

*/

BOOL AllergyDisplayDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString sPatientId;
	bool bInteractionFlag=0;//to check if any drug-drug interactions are present with respect to drugs already present in order list.
	try
	{
		sPatientId.Format(_T(" %d"), m_patient.GetPatientId());
		m_patientIdEdt.SetWindowText(sPatientId);
		m_patientNameEdt.SetWindowText(m_patient.GetPatientName());
		sPatientId.Format(_T(" %d"), m_drug.GetDrugId());
		m_drugIdEdt.SetWindowText(sPatientId);
		m_drugNameEdt.SetWindowText(m_drug.GetDrugName());

		//setting the lists with headers
		m_patientAllergyLstCtrl.InsertColumn(0, _T("Drug ID"), LVCFMT_LEFT, 200);
		m_patientAllergyLstCtrl.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 200);
		m_patientAllergyLstCtrl.InsertColumn(2, _T("Severity"), LVCFMT_LEFT, 200);
		m_drugAllergyLstCtrl.InsertColumn(0, _T("Drug ID"), LVCFMT_LEFT, 200);
		m_drugAllergyLstCtrl.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 200);
		m_drugAllergyLstCtrl.InsertColumn(2, _T("Severity"), LVCFMT_LEFT, 200);
		
		int nPatientArraySize = 0;
		nPatientArraySize = m_orderService.ListPatientDrugInteraction(m_patient.GetPatientId(), m_drug.GetDrugId());
		if (nPatientArraySize > 0)
		{
			//if patient is allergic to the drug then load data to the m_patientAllergyLstCtrl.
			for (int i = 1; i <= nPatientArraySize; i++)
			{
				//for loading the patient-allergy list
				int nItem;
				CString sText;
				sText.Format(_T("%d"), theApp.m_drugArray[i].GetDrugId());
				nItem = m_patientAllergyLstCtrl.InsertItem(0, sText);
				m_patientAllergyLstCtrl.SetItemText(nItem, 1, theApp.m_drugArray[i].GetDrugName());
				m_patientAllergyLstCtrl.SetItemText(nItem, 2, theApp.m_severity[i]);
			}
		}

		int nDrugArraySize = m_orderService.ListDrugDrugInteraction(m_drug.GetDrugId());
		if (nDrugArraySize > 0)
		{
			//if drug interacts with other drugs then load m_drugAllergyLstCtrl.
			for (int i = 1; i <= nDrugArraySize; i++)
			{
				for (int j = 1; j < m_drugArray.GetCount(); j++)
				{
					if (m_patient.GetPatientId() == m_patientArray[j].GetPatientId())
					{
						if (m_drugArray[j].GetDrugId() == theApp.m_drugArray[i].GetDrugId())
						{
							int nItem;
							CString sText;
							bInteractionFlag = 1;
							sText.Format(_T("%d"), theApp.m_drugArray[i].GetDrugId());
							nItem = m_drugAllergyLstCtrl.InsertItem(0, sText);
							m_drugAllergyLstCtrl.SetItemText(nItem, 1, theApp.m_drugArray[i].GetDrugName());
							m_drugAllergyLstCtrl.SetItemText(nItem, 2, theApp.m_severity[i]);
						}
					}
				}
			}

		}
		if (nPatientArraySize == 0 && (nDrugArraySize == 0 || bInteractionFlag == 0))
		{
			CDialogEx::OnOK();
		}
	}
	catch (CException* e)
	{
		MessageBox(_T("Error in adding order."));
		e->Delete();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void AllergyDisplayDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	CDialogEx::OnOK();
}

/*
this method is called to display the AllergyDisplayDlg dialog.
parameter:
		Drug array from AllergyOrderDlg dialog
		It copies the values from the parameter to local drug array-m_drugArray
*/
INT_PTR AllergyDisplayDlg::DoModal(CArray<CDrug, CDrug&> &drugArray, CArray<CPatient, CPatient&> &patientArray)
{
	m_drugArray.Copy(drugArray);
	m_patientArray.Copy(patientArray);
	return CDialogEx::DoModal();
}


		void AllergyDisplayDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
		{
			LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
			// TODO: Add your control notification handler code here
			*pResult = 0;
		}


		void AllergyDisplayDlg::OnBnClickedCancel()
		{
			// TODO: Add your control notification handler code here
			CDialogEx::OnCancel();
		}
