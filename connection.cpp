#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "Server.h"
#include "connection.h"
#include "requestHandler.h"
#define port 2000
using namespace std;



connection::connection(boost::asio::io_service io_s,requestHandler req)
	:strand(io_s),sock(io_s),reqHandler(req)
{
}

boost::asio::ip::tcp::socket connection::getSocket(){
	return sock;
}

void connection::read(){
	sock.async_read_some(buffer, strand.wrap(boost::bind(&connection::handleRead, shared_from_this(),
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred)));
	//shared_from_this mesa sthn bind epeidh h handleRead einai member function kai kaleitai ws pointer (prwto argument sthn bind)
	
}

void connection::handleRead(const boost::system::error_code& e,size_t bt){
	//enalaktika to kanw me iostream
	if(!e){
		char* result=reqHandler.messageAnalyze(buffer);
		if(result=="-1"){
			std::string error="Bad request\n";
			sock.async_write_some(error,strand.wrap(bind(&connection::handleWrite, shared_from_this(), boost::asio::placeholders::error)));
		}
		else
		{
		
			sock.async_write_some(result,strand.wrap(bind(&connection::handleWrite,shared_from_this(),boost::asio::placeholders::error)));
		}
		
		read();
}
}
void connection::handleWrite(const boost::system::error_code& e){
	if(!e){
		cout<<"send error"<<endl;
		sock.shutdown(boost::asio::ip::tcp::socket::shutdown_both); //kleisimo kai send kai receive (both)
	}
}