#include "stdafx.h"
#include "CPatient.h"


CPatient::CPatient()
{
	m_nPatientId = 0;
	m_sPatientName = _T("");
}


CPatient::~CPatient()
{
}


// get patient details - patient Id and name
void CPatient::SetPatientDetails(int nPatientId, CString sPatientName)
{
	m_nPatientId = nPatientId;
	m_sPatientName = sPatientName;
}


// return patient id
int CPatient::GetPatientId()
{
	return m_nPatientId;
}


// return patient name
CString CPatient::GetPatientName()
{
	return m_sPatientName;
}
