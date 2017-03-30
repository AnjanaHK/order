#pragma once
class CInputValidator
{
private:
	// this method will check whether given char is an alphabet
	bool CheckIsAlphabet(char cValue);
	// this  method checks whether given char is a number
	bool CheckIsNumber(char cValue);
	// this method checks whether given char is space
	bool CheckIsSpace(char cValue);
public:
	CInputValidator();
	~CInputValidator();
	//this method checks whether given string is valid i.e. whether it is alphanumeric
	bool CheckValid(CString sValue);
};

