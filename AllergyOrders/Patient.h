#pragma once
class Patient
{
public:
	Patient();
	~Patient();
private:
	int patientId;
	CString patientName;
public:
	// get patient details - patient Id and name
	void setPatientDetails(int pid, CString name);
	// return patient id
	int getPatientId();
	// return patient name
	CString getPatientName();
};

