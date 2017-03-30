#pragma once
class CDrug
{
private:
	int m_nDrugId;
	CString m_sDrugName;

public:
	CDrug();
	~CDrug();
public:
	void SetDrugDetails(int nDrugId, CString sDrugName);
	int GetDrugId();
	CString GetDrugName();
};

