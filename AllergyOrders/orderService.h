#pragma once
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
	Patient* searchPatient(CString name);
	Drug* searchDrug(CString name);
};
