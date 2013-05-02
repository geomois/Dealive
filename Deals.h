

#pragma once
#include <atldbcli.h>



class CDeals
{
public:
	LONG m_Id;
	TCHAR m_Name[51];
	LONG m_Type;
	DBTIMESTAMP m_Time;
	CURRENCY m_Price;
	TCHAR m_Place[51];
	LONG m_Id_S;

	DBSTATUS m_dwPriceStatus;
	DBLENGTH m_dwPriceLength;

	//Map for the table columns
	BEGIN_COLUMN_MAP(CDeals)
		COLUMN_ENTRY(1, m_Id)
		COLUMN_ENTRY(2, m_Name)
		COLUMN_ENTRY(3, m_Type)
		COLUMN_ENTRY(4, m_Time)
		_COLUMN_ENTRY_CODE(5, DBTYPE_CY, _SIZE_TYPE(m_Price), 0, 0, offsetbuf(m_Price), offsetbuf(m_dwPriceLength), offsetbuf(m_dwPriceStatus))
		COLUMN_ENTRY(6, m_Place)
		COLUMN_ENTRY(7, m_Id_S)
	END_COLUMN_MAP()

	//Map for the query parameters
	BEGIN_PARAM_MAP(CDeals)
		SET_PARAM_TYPE(DBPARAMIO_INPUT)
			COLUMN_ENTRY(1, m_Type)
END_PARAM_MAP()

CDeals & operator=(const CDeals &rhs)
{
	this->m_Id= rhs.m_Id;
	_tcscpy(this->m_Name,rhs.m_Name);
	this->m_Type= rhs.m_Type;
	this->m_Time=rhs.m_Time;
	this->m_Price=rhs.m_Price;
	_tcscpy(this->m_Place,rhs.m_Place);
	this->m_Id_S= rhs.m_Id_S;

	return *this;

}
};




