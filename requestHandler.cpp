#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <vector>
#include "string.h"
#include <boost/bind.hpp>
#include <boost/noncopyable.hpp>
#include "requestHandler.h"
#include "Fetch.h"
#include "Deals.h"

requestHandler::requestHandler()
{
	Fetch session();
}

char* requestHandler::messageAnalyze(char buff[]){
	
	std::string temp(buff);
	reset();
	sscanf(buff,"%s,%d",temp,id);
	
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
	int* arraysize=0;
	if(id==0){
		char* tempBuff;	
		strcat(tempBuff,std::string(session.Deals(1,*arraysize)));
		strcat(tempBuff,session.Deals(2,*arraysize));
		strcat(tempBuff,session.Deals(3,*arraysize));
	}
	else{

	}
}


void requestHandler::reset(){
	memset(&sendBuffer,0,sizeof*(sendBuffer));
}