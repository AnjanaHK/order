#pragma once
class CPatient
{
public:
	CPatient();
	~CPatient();
private:
	int m_nPatientId;
	CString m_sPatientName;
public:
	// get patient details - patient Id and name
	void SetPatientDetails(int nPatientId, CString sPatientName);
	// return patient id
	int GetPatientId();
	// return patient name
	CString GetPatientName();
};

