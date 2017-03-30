#include "stdafx.h"
#include "COrderService.h"
COrderService::COrderService()
{
}


COrderService::~COrderService()
{
}

/*
	This method is called for a patient.
	parameter:
			sPatientName- It is sDrugName of a patient.
	This method will search for patients with sDrugName that matches the parameter.
	return:
			number of rows- number of patient records found.
*/
int COrderService::SearchPatient(CString sPatientName, bool bSearch)
{
	int nCounter = -1;
	int nRowSize;
	nRowSize = m_dbconnection.GetPatientRecordSize(sPatientName, bSearch);
	CRecordset recordset;
	m_dbconnection.GetPatientRecordset(sPatientName,recordset, bSearch);
	CPatient* pPatient = new CPatient[nRowSize];
	theApp.m_patientArray.RemoveAll();
	while (!recordset.IsEOF())
		{
			CString sPatientId, sPatientName;
			recordset.GetFieldValue(_T("patientId"), sPatientId);
			recordset.GetFieldValue(_T("patient_name"), sPatientName);
		//	AfxMessageBox(sPatientName);
			pPatient[++nCounter].SetPatientDetails(_ttoi(sPatientId.GetString()), sPatientName);
			recordset.MoveNext();
			theApp.m_patientArray.SetAtGrow(nCounter + 1, pPatient[nCounter]);
		}

	
	recordset.Close();
	m_dbconnection.CloseConnection();
	return (nRowSize);
}

/*
This method is called for a drug.
parameter:
sDrugName- It is sDrugName of a drug.
This method will search for drugs with sDrugName that matches the parameter.
return:
number of rows- number of drug records found.
*/
int COrderService::SearchDrug(CString sDrugName, bool bSearch)
{
	int nRowSize;
	nRowSize = m_dbconnection.GetDrugRecordSize(sDrugName, bSearch);
	CRecordset recordset;
	m_dbconnection.GetDrugRecordset(sDrugName,recordset, bSearch);
	CDrug* pDrug = new CDrug[nRowSize];
	int nCounter = 0;
	theApp.m_drugArray.RemoveAll();
	while (!recordset.IsEOF())
	{
		CString sDrugId, sDrugName;
		recordset.GetFieldValue(_T("drugId"), sDrugId);
		recordset.GetFieldValue(_T("drug_name"), sDrugName);
		pDrug[nCounter++].SetDrugDetails(_ttoi(sDrugId), sDrugName);
		recordset.MoveNext();
		theApp.m_drugArray.SetAtGrow(nCounter, pDrug[nCounter-1]);
	}
	recordset.Close();
	m_dbconnection.CloseConnection();
	return (nRowSize);
}

/*
This method is called for patient drug interaction.
parameter:
	nPatientId- ID of the patient for whom allergies have to be searched.
	nDrugId- ID of the drug for which interaction has to be checked.
This method will map patient allergy to the drug.
return:
number of rows- number of records found.
*/
int COrderService::ListPatientDrugInteraction(int nPatientId,int nDrugId)
{
	int nRowSize;
	nRowSize = m_dbconnection.GetPatientDrugInteractionRecordSize(nPatientId, nDrugId);
	CRecordset recordset;
	m_dbconnection.GetPatientDrugInteractionRecordset(nPatientId, nDrugId, recordset);
	CDrug* pDrug = new CDrug[nRowSize];
	CString* psSeverity = new CString[nRowSize];
	int nCounter = 0;
	theApp.m_drugArray.RemoveAll();
	while (!recordset.IsEOF())
	{
		CString sDrugId, sDrugName;
		recordset.GetFieldValue(_T("DrugId"), sDrugId);
		recordset.GetFieldValue(_T("Drug_name"), sDrugName);
		pDrug[nCounter].SetDrugDetails(_ttoi(sDrugId), sDrugName);
		recordset.GetFieldValue(_T("severity"), psSeverity[nCounter]);
		nCounter++;
		recordset.MoveNext();
		theApp.m_drugArray.SetAtGrow(nCounter, pDrug[nCounter - 1]);
		theApp.m_severity.SetAtGrow(nCounter, psSeverity[nCounter - 1]);
	}
	recordset.Close();
	m_dbconnection.CloseConnection();
	return (nRowSize);

}

/*
This method is called for a interaction between drugs.
parameter:
	nDrugId- ID of the drug for which interactions has to be checked.
This method will search for drugs that interacts with current drug.
return:
number of rows- number of records found.
*/
int COrderService::ListDrugDrugInteraction(int nDrugId)
{
	int nRowSize;
	CRecordset recordset;
	nRowSize = m_dbconnection.GetDrugInteractionRecordSize(nDrugId);
	m_dbconnection.GetDrugInteractionRecordset(nDrugId, recordset);
	CDrug* pDrug = new CDrug[nRowSize];
	CString* psSeverity = new CString[nRowSize];
	int nCounter = 0;
	theApp.m_drugArray.RemoveAll();
	theApp.m_severity.RemoveAll();
	while (!recordset.IsEOF())
	{
		CString sDrugId, sDrugName;
		//assuming current drug is under coloumn DrugId2, take values for DrugId1
		recordset.GetFieldValue(_T("DrugId1"), sDrugId);
		recordset.GetFieldValue(_T("Drug_Name1"), sDrugName);
		if (_ttoi(sDrugId) == nDrugId)//if current drug is under coloumn DrugId1 then display the drug to which it interacts nCounter.e DrugId2.
		{
			recordset.GetFieldValue(_T("DrugId2"), sDrugId);
			recordset.GetFieldValue(_T("Drug_Name2"), sDrugName);

		}

		recordset.GetFieldValue(_T("severity"), psSeverity[nCounter]);
		pDrug[nCounter].SetDrugDetails(_ttoi(sDrugId), sDrugName);
		recordset.MoveNext();
		nCounter++;
		theApp.m_drugArray.SetAtGrow(nCounter, pDrug[nCounter - 1]);
		theApp.m_severity.SetAtGrow(nCounter, psSeverity[nCounter - 1]);
	}
	recordset.Close();
	m_dbconnection.CloseConnection();
	return (nRowSize);
}
void COrderService::SaveOrders(int drugId, int patientId, CString date, CString comment)
{
	m_dbconnection.SetOrderToDatabase(drugId, patientId, date, comment);
}