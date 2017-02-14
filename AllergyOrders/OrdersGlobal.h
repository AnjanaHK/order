#pragma once
#include "afxwin.h"
#include "orderService.h"
#include "iostream"
using namespace std;
#include "Patient.h"
#include "AllergyOrdersDlg.h"
#include "AllergyOrders.h"
class OrdersGlobal :
	public CWinApp
{
public:
	OrdersGlobal();
	~OrdersGlobal();
	static DBConnection DBconnection;
	static orderService os;
	static Patient patient;
	static CString patientName;
	static CString drugName;
	static CRecordset recordset;
};

