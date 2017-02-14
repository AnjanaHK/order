#pragma once
class Drug
{
public:
	Drug();
	~Drug();
private:
	int drugId;
	CString drugName;
public:
	void setDrugDetails(int dId, CString name);
	int getDrugId();
	CString getDrugName();
};

