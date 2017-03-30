#include "stdafx.h"
#include "CDBConnection.h"


CDBConnection::CDBConnection()
{
}


CDBConnection::~CDBConnection()
{
}


// open cnonection using dsn
void CDBConnection::OpenConnection()
{
	try
	{
		m_database.Open(_T("Demodns;"), FALSE, FALSE, _T("ODBC;"));
	}
	catch (_com_error & ce)
	{
		CString errMsg = ce.ErrorMessage();// = ce.ErrorMessage();
		//errMsg.Format(_T(ce.ErrorMessage()));
		AfxMessageBox(errMsg);
	}
}


// close the database connection
void CDBConnection::CloseConnection()
{
	m_database.Close();

}

/*
This method returns number of records found after quering the database for records of patient with name that matches the parameter.
*/
int CDBConnection::GetPatientRecordSize(CString sPatientName, bool bSearch)
{
	CString sSqlStatement;
	CString sSize;
	int nRowSize;
	if(bSearch == true)
		sSqlStatement.Format(_T("select count(*) as count from dbo.patient where patient_name like '" + sPatientName + "%%'"));
	else
		sSqlStatement.Format(_T("select count(*) as count from dbo.patient where patient_name = '" + sPatientName + "'"));
	OpenConnection();
	CRecordset recordset;
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSqlStatement, CRecordset::readOnly);
	recordset.GetFieldValue(_T("count"), sSize);
	recordset.Close();
	CloseConnection();

	nRowSize = _ttoi(sSize);
	return(nRowSize);

}
/*
This method searches for records of patients with name that matches the 1st parameter and populates the recorset with the same.
*/
void CDBConnection::GetPatientRecordset(CString sPatientName, CRecordset& recordset, bool bSearch)
{
	
	CString sSQLStatement;
	if (bSearch == true)
		sSQLStatement.Format(_T("select * from dbo.patient where patient_name like '" + sPatientName + "%%'"));
	else
		sSQLStatement.Format(_T("select * from dbo.patient where patient_name ='" + sPatientName + "'"));
	OpenConnection();
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);

}

/*
This method returns number of records found after quering the database for records of drug with name that matches the parameter.
*/
int CDBConnection::GetDrugRecordSize(CString sDrugName, bool bSearch)
{
	CString sSQLStatement;
	int nRowsize;
	CString sSize;
	if (bSearch == true)
		sSQLStatement.Format(_T("select count(*) as count from dbo.drug_reference where drug_name like '" + sDrugName + "%%'"));
	else
		sSQLStatement.Format(_T("select count(*) as count from dbo.drug_reference where drug_name ='" + sDrugName + "'"));
	OpenConnection();
	CRecordset recordset;
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);
	recordset.GetFieldValue(_T("count"), sSize);
	recordset.Close();
	CloseConnection();
	nRowsize = _ttoi(sSize);
	return(nRowsize);
}

/*
This method searches for records of drugs with name that matches the 1st parameter and populates the recorset with the same.
*/
void CDBConnection::GetDrugRecordset(CString sDrugName, CRecordset& recordset, bool bSearch)
{
	CString sSQLStatement;
	if(bSearch == true)
		sSQLStatement.Format(_T("select * from dbo.drug_reference where drug_name like '" + sDrugName + "%%'"));
	else
		sSQLStatement.Format(_T("select * from dbo.drug_reference where drug_name ='" + sDrugName + "'"));
	OpenConnection();
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);
}

/*
This method returns number of records for patient drug interaction with given PatientId and DrugId.
*/
int CDBConnection::GetPatientDrugInteractionRecordSize(int nPatientId, int nDrugId)
{
	CString sSQLStatement;
	int nRowsize;
	CString sSize;
	CRecordset recordset;
	sSQLStatement.Format(_T("select count(*) as count from dbo.Patient p,dbo.interaction_patient dp, dbo.drug_reference d where p.PatientId=dp.PatientId and dp.DrugId=d.DrugId and dp.PatientId= %d and dp.drugId=%d"), nPatientId,nDrugId);
	OpenConnection();
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);
	recordset.GetFieldValue(_T("count"), sSize);
	recordset.Close();
	CloseConnection();
	nRowsize = _ttoi(sSize);
	return nRowsize;
}
/*
This method searches for records of patient drug interaction with given m_PatientId and drugId and populates the recorset with the same.
*/
void CDBConnection::GetPatientDrugInteractionRecordset(int nPatientId, int nDrugId, CRecordset& recordset)
{
	CString sSQLStatement;
	sSQLStatement.Format(_T("select dp.DrugId, d.Drug_name,dp.severity from dbo.Patient p,dbo.interaction_patient dp, dbo.drug_reference d where p.PatientId=dp.PatientId and dp.DrugId=d.DrugId and dp.PatientId= %d and dp.drugId=%d "), nPatientId, nDrugId);
	OpenConnection();
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);
}
/*
This method returns number of records for drug drug interaction with given DrugId.
*/
int CDBConnection::GetDrugInteractionRecordSize(int nDrugId)
{
	CString sSQLStatement;
	int nRowsize;
	CString sSize;
	CRecordset recordset;
	sSQLStatement.Format(_T("select count(*) as count from dbo.interaction_drug di join dbo.drug_reference dr on dr.DrugId = di.DrugId2 where di.drugId1 = %d or di.drugId2 = %d"), nDrugId, nDrugId);
	OpenConnection();
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);
	recordset.GetFieldValue(_T("count"), sSize);
	recordset.Close();
	CloseConnection();
	nRowsize = _ttoi(sSize);
	return nRowsize;
}
/*
This method searches for records of drug drug interaction with given drugId and populates the recorset with the same.
*/
void CDBConnection::GetDrugInteractionRecordset(int nDrugId, CRecordset& recordset)
{
	CString sSQLStatement;
	sSQLStatement.Format(_T("select di.DrugId1, dr1.Drug_name as Drug_Name1, di.DrugId2, dr2.Drug_name as Drug_Name2,di.severity from dbo.interaction_drug di join dbo.drug_reference dr1 on dr1.DrugId=di.DrugId1 join dbo.drug_reference dr2 on dr2.DrugId=di.DrugId2 where di.drugId1 = %d or di.drugId2 = %d"), nDrugId, nDrugId);
	OpenConnection();
	recordset.m_pDatabase = &m_database;
	recordset.Open(CRecordset::forwardOnly, sSQLStatement, CRecordset::readOnly);
}

/*
This method takes all the parameters and inserts the order record into the database.
*/
void CDBConnection::SetOrderToDatabase(int nDrugId, int nPatientId, CString sDate, CString sComment)
{

	CString sSQLStatement;
	sSQLStatement.Format(_T("insert into dbo.orders(patientId, drugId, date, comment) values (%d, %d, '%s','%s')"), nDrugId, nPatientId, sDate, sComment);
	//strSql.Format(L"select * from dbo.orders");
	//strSql.Append(date);
	//strSql.AppendFormat(L"', ");
	//strSql.Append(comment);
	OpenConnection();
	//CRecordset recordset;
	//recordset.m_pDatabase = &m_dbconnection.m_database;
	//recordset.Open(CRecordset::dynamic, strSql, CRecordset::executeDirect);
	//recordset.AddNew();
	m_database.ExecuteSQL(sSQLStatement);
	//recordset.Update();
	//recordset.Close();
	CloseConnection();
}