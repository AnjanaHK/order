#include "afxdb.h"
#pragma once
class CDBConnection
{
public:
	CDBConnection();
	~CDBConnection();
	CDatabase m_database;
public:
	// open coonection using dsn
	void OpenConnection();

	// close the database connection
	void CloseConnection();

	//takes patient name and searches for patient records with that name and returns number of records.
	int GetPatientRecordSize(CString sPatientName, bool bSearch);

	//takes patient name and searches for patient records with that name and stores the records in recordset.
	void GetPatientRecordset(CString sPatientName, CRecordset& recordset , bool bSearch);

	//takes drug name and searches for drug records with that name and returns number of records.
	int GetDrugRecordSize(CString sDrugName, bool bSearch);

	//takes drug name and searches for drug records with that name and stores the records in recordset.
	void GetDrugRecordset(CString sDrugName, CRecordset& recordset, bool bSearch);

	//takes patient ID and drug ID, searches for records of patient with that drug allergy and returns record size.
	int GetPatientDrugInteractionRecordSize(int nPatientId, int nDrugId);

	//takes patient ID and drug ID, searches for records of patient with that drug allergy and stores the record in recordset.
	void GetPatientDrugInteractionRecordset(int nPatientId, int nDrugId, CRecordset& recordset);

	//takes drug ID and searches for drug records with that ID in drug-drug interaction table and returns number of records.
	int GetDrugInteractionRecordSize(int nDrugId);

	//takes  drug ID and searches for drug records with that ID in drug-drug interaction table and stores the records in recordset.
	void GetDrugInteractionRecordset(int nDrugId, CRecordset& recordset);
	
	//takes drug ID, patient ID, Date and comment and stores the values in the order table.
	void SetOrderToDatabase(int nDrugId, int nPatientId, CString sDate, CString sComment);
};

