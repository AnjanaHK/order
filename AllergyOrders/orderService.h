#pragma once
#include "AllergyOrders.h"
#include "Patient.h"
#include "Drug.h"
#include "DBConnection.h"
#include<vector>
using namespace std;
class orderService
{
private:
	DBConnection dbc;
public:
	CString name;
	orderService();
	~orderService();
	int searchPatient(CString name);
	int searchDrug(CString name);
	int listPatientDrugInteraction(int patientId,int drugId);
	int listDrugDrugInteraction(int drugId);
	void saveOrders(int drugId, int patientId, CString date, CString comment);
};

