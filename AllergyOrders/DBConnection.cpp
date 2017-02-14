#include "stdafx.h"
#include "DBConnection.h"


DBConnection::DBConnection()
{
}


DBConnection::~DBConnection()
{
}


// open coonection using dsn
void DBConnection::openConnection()
{
	CString strSQL, name;
	try
	{
		database.Open(_T("Demodns;"), FALSE, FALSE, _T("ODBC;"));
	
	}
	catch (_com_error & ce)
	{
		CString errMsg = ce.ErrorMessage();// = ce.ErrorMessage();
		//errMsg.Format(_T(ce.ErrorMessage()));
		AfxMessageBox(errMsg);
	}
}


// close the database connection
void DBConnection::closeConnection()
{
	database.Close();
}
