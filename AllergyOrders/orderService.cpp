#include "stdafx.h"
#include "orderService.h"
orderService::orderService()
{
}


orderService::~orderService()
{
}


//vector<Patient>
Patient* orderService::searchPatient(CString name)
{
	int i = -1;
	CString strSql;
	//try
	//{
		strSql.Format(L"select * from dbo.patient where patient_name like '" + name+"%%'");
		dbc.openConnection();
		CRecordset recordset;
		recordset.m_pDatabase = &dbc.database;
		recordset.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
		int rowsize = recordset.GetRowsetSize();
		Patient* p = new Patient[rowsize];
		//vector<Patient> p;
		while (!recordset.IsEOF())
		{
			CString pid, name;
			recordset.GetFieldValue(L"patientId", pid);
			recordset.GetFieldValue(L"patient_name", name);
			p[++i].setPatientDetails(_wtoi(pid), name);
			recordset.MoveNext();
		}

	//}
	//catch (_com_error & ce)
	//{
		//MessageBox(_T("Error in search function"));
//	}
	return (p);
}
Drug* orderService::searchDrug(CString name)
{

	CString strSql;
	//try
	//{
	strSql.Format(L"select * from dbo.drug_reference where drug_name like '" + name + "%%'");
	dbc.openConnection();
	CRecordset recordset;
	recordset.m_pDatabase = &dbc.database;
	recordset.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
	int rowsize = recordset.GetRowsetSize();
	Drug* d = new Drug[rowsize];
	int i = 0;
	while (!recordset.IsEOF())
	{
		CString did, name;
		recordset.GetFieldValue(L"drugId", did);
		recordset.GetFieldValue(L"drug_name", name);
		d[i++].setDrugDetails(_wtoi(did), name);
		recordset.MoveNext();
	}

	//}
	//catch (_com_error & ce)
	//{
	//MessageBox(_T("Error in search function"));
	//	}
	return (d);
}