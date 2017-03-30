#include "stdafx.h"
#include "CDrug.h"


CDrug::CDrug()
{
	m_nDrugId = 0;
	m_sDrugName = _T("");
}


CDrug::~CDrug()
{
}


void CDrug::SetDrugDetails(int nDrugId, CString sDrugName)
{
	m_nDrugId = nDrugId;
	m_sDrugName = sDrugName;
}


int CDrug::GetDrugId()
{
	return m_nDrugId;
}


CString CDrug::GetDrugName()
{
	return m_sDrugName;
}
