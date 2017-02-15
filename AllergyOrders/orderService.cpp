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
		//dbc.closeConnection();
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
	//dbc.closeConnection();
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
int orderService::listPatientDrugInteraction(int patientId,int drugId)
{

	CString strSql;
	//try
	//{
	strSql.Format(L"select dp.DrugId, d.Drug_name,dp.severity from dbo.Patient p,dbo.interaction_patient dp, dbo.drug_reference d where p.PatientId=dp.PatientId and dp.DrugId=d.DrugId and dp.PatientId= %d",patientId );
	strSql.AppendFormat(L"and dp.drugId=%d", drugId);
	dbc.openConnection();
	CRecordset recordset;
	recordset.m_pDatabase = &dbc.database;
	recordset.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
	//dbc.closeConnection();
	int rowsize = recordset.GetRowsetSize();
	Drug* d = new Drug[rowsize];
	CString* sev = new CString[rowsize];
	int i = 0;
	while (!recordset.IsEOF())
	{
		CString did, name;
		recordset.GetFieldValue(L"DrugId", did);
		recordset.GetFieldValue(L"Drug_name", name);
		d[i].setDrugDetails(_wtoi(did), name);
		recordset.GetFieldValue(L"severity", sev[i]);
		i++;
		recordset.MoveNext();
	}
	recordset.Close();
	//}
	//catch (_com_error & ce)
	//{
	//MessageBox(_T("Error in search function"));
	//	}
	dbc.closeConnection();
	theApp.globalDrugArray = d;
	theApp.severity = sev;
	return (rowsize);

}
int orderService::listDrugDrugInteraction(int drugId)
{

	CString strSql;
	//try
	//{
	strSql.Format(L"select count(*) as count from dbo.interaction_drug di join dbo.drug_reference dr on dr.DrugId = di.DrugId2 where di.drugId1 = %d", drugId);
	dbc.openConnection();
	CRecordset recordset;
	recordset.m_pDatabase = &dbc.database;
	recordset.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
	CString size;
	recordset.GetFieldValue(L"count", size);
	recordset.Close();
	dbc.closeConnection();
	int rowsize = _wtoi(size);
	strSql.Format(L"select di.DrugId2, dr.Drug_name, di.severity from dbo.interaction_drug di join dbo.drug_reference dr on dr.DrugId = di.DrugId2 where di.drugId1 = %d", drugId);
	dbc.openConnection();
	recordset.m_pDatabase = &dbc.database;
	recordset.Open(CRecordset::forwardOnly, strSql, CRecordset::readOnly);
	Drug* d = new Drug[rowsize];
	CString* sev = new CString[rowsize];
	int i = 0;
	while (!recordset.IsEOF())
	{
		CString did, name;
		recordset.GetFieldValue(L"DrugId2", did);
		recordset.GetFieldValue(L"Drug_name", name);
		recordset.GetFieldValue(L"severity", sev[i]);
		d[i].setDrugDetails(_wtoi(did), name);
		recordset.MoveNext();
		i++;
	}
	recordset.Close();
	dbc.closeConnection();
	//}
	//catch (_com_error & ce)
	//{
	//MessageBox(_T("Error in search function"));
	//	}
	theApp.globalDrugArray = d;
	theApp.severity = sev;
	return (rowsize);
}