#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <vector>
#include "string.h"
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>

class requestHandler:boost::noncopyable{
private:
	char* sendBuffer;
	int id,result;
	std::string temp;
	requestHandler(char);
	char* call_DB(int choice,int id);  //choice: 1Deals, 2Store
public:
	char* messageAnalyze(char&);
	void reset();
};