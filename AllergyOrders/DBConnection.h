#include "afxdb.h"
#pragma once
class DBConnection
{
public:
	DBConnection();
	~DBConnection();
	CDatabase database;
public:
	// open coonection using dsn
	void openConnection();
	// close the database connection
	void closeConnection();
};

