
#pragma once
#include <atldbcli.h>


class CStore
{
public:
	LONG m_Id;
	TCHAR m_Name[201];
	TCHAR m_Address[201];
	TCHAR m_Phone[16];
	TCHAR m_Description[201];

	//Map for the table columns
	BEGIN_COLUMN_MAP(CStore)
		COLUMN_ENTRY(1, m_Id)
		COLUMN_ENTRY(2, m_Name)
		COLUMN_ENTRY(3, m_Address)
		COLUMN_ENTRY(4, m_Phone)
		COLUMN_ENTRY(5, m_Description)
	END_COLUMN_MAP()

	//Map for the query parameters
	BEGIN_PARAM_MAP(CStore)
		SET_PARAM_TYPE(DBPARAMIO_INPUT)
			COLUMN_ENTRY(1, m_Id)
END_PARAM_MAP()

CStore & operator=(const CStore &rhs)
{
	this->m_Id= rhs.m_Id;

	_tcscpy(this->m_Name,rhs.m_Name);
	_tcscpy(this->m_Address,rhs.m_Address);
	_tcscpy(this->m_Phone,rhs.m_Phone);
	_tcscpy(this->m_Description,rhs.m_Description);

	return *this;
}

};

