#include "stdafx.h"
#include "InputValidator.h"


CInputValidator::CInputValidator()
{
}


CInputValidator::~CInputValidator()
{
}


// this method will check whether given char is an alphabet
bool CInputValidator::CheckIsAlphabet(char cValue)
{
	if (((cValue >= 'a') && (cValue <= 'z')) || ((cValue>= 'A') && (cValue <= 'Z')))
	{
		return true;
	}
	return false;
}


// this  method checks whether given char is a number
bool CInputValidator::CheckIsNumber(char cValue)
{
	if ((cValue >= '0') && (cValue <= '9'))
	{
		return true;
	}
	return false;
}


// this method checks whether given char is space
bool CInputValidator::CheckIsSpace(char cValue)
{
	if (cValue == ' ')
	{
		return true;
	}
	return false;
}

//this method checks whether given string is valid i.e. whether it is alphanumeric
bool CInputValidator::CheckValid(CString sValue)
{
	bool bValid = false;
	for(int i=0; i<sValue.GetLength();i++)
	{ 
		if (CheckIsAlphabet(sValue.GetAt(i)) | CheckIsNumber(sValue.GetAt(i)) | CheckIsSpace(sValue.GetAt(i)))
		{
			bValid = true;
		}
		else
		{
			bValid = false;
			break;
		}
	}
	return bValid;
}
