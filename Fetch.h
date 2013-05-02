#pragma once
#include "stdafx.h"
#include <ctime>
#include "string.h"
#include "Deals.h"
#include "Store.h"

class Fetch
{
public:

	Fetch(void);
	~Fetch(void);
	CStore Store(int Id);
	CDeals* Deals(type t,int &arraySize);


private :

	void tstamp(string print);
	void tstamp(string print,int n);


	CDataSource connection;
	CSession session;
	CCommand<CAccessor<CStore> > store;
	CCommand<CAccessor<CDeals> > deals;
	CLSID clsid;
	HRESULT hr;
	CDeals* RDeals;
};

