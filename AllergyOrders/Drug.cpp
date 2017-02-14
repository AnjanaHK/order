#include "stdafx.h"
#include "Drug.h"


Drug::Drug()
{
	drugId = 0;
	drugName = _T("");
}


Drug::~Drug()
{
}


void Drug::setDrugDetails(int dId, CString name)
{
	drugId = dId;
	drugName = name;
}


int Drug::getDrugId()
{
	return drugId;
}


CString Drug::getDrugName()
{
	return drugName;
}
