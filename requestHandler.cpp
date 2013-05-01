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
	void reset(); //δεν έχει λόγο να είναι public
}

requestHandler::requestHandler(char buff)
{
	std::string temp(&buff);
}

char* requestHandler::messageAnalyze(char& buff){
	
	reset();
	sscanf(&buff,"%s,%d",temp,id);
	
	result=temp.compare("Deals");
	if(result==0){
		sendBuffer=call_DB(1,0);
	}else if((result= temp.compare("Store"))==0)
	{
		sendBuffer=call_DB(2,id);
	}else
	{
		return "-1";
	}

}

char* requestHandler::call_DB(int choice, int id){
	//
	//
	//
	//
}

void requestHandler::reset(){
	memset(&sendBuffer,0,sizeof*(sendBuffer));
}