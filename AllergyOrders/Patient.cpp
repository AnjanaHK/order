#include "stdafx.h"
#include "Patient.h"


Patient::Patient()
{
	patientId = 0;
	patientName = _T("");
}


Patient::~Patient()
{
}


// get patient details - patient Id and name
void Patient::setPatientDetails(int pid, CString name)
{
	patientId = pid;
	patientName = name;
}


// return patient id
int Patient::getPatientId()
{
	return patientId;
}


// return patient name
CString Patient::getPatientName()
{
	return patientName;
}
