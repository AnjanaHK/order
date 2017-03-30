#pragma once
#include "AllergyOrders.h"
#include "CPatient.h"
#include "CDrug.h"
#include "CDBConnection.h"
#include<vector>
using namespace std;
class COrderService
{
private:
	CDBConnection m_dbconnection;

public:
	COrderService();
	~COrderService();

	//searches for patient using patient name and returns record count
	int SearchPatient(CString sPatientName, bool bSearch);

	//searches for drug using drug name and returns record count
	int SearchDrug(CString sDrugName, bool bSearch);

	//searches for patient records with given patient ID and drug ID and returns record count
	int ListPatientDrugInteraction(int nPatientId,int nDrugId);

	//searches for drug records with given drug Id and returns record count
	int ListDrugDrugInteraction(int nDrugId);

	//inserts given data to the database
	void SaveOrders(int nDrugId, int nPatientId, CString sDate, CString sComment);
};

