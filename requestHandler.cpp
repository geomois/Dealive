#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>

class requestHandler:boost::noncopyable{
private:
	//char buffer[8192];
	std::string temp;
	requestHandler(char);
	char call_DB(int choice,int id);  //choice: 1Deals, 2Store
	int messageAnalyze(char&);
};

requestHandler::requestHandler(char buff)
{
	std::string temp(&buff);
	messageAnalyze(buff);
}

int requestHandler::messageAnalyze(char& buff){
	
	int id;
	sscanf(&buff,"%s,%d",temp,id);
	
	int result=temp.compare("Deals");
	if(result==0){
		call_DB(1,0);
	}
	result= temp.compare("Store");
	if(result==0){
		call_DB(2,id);
	}
}

char call_DB(int choice, int id){
	//
	//
	//
	//
}