#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "Server.h"
#define port 2000
using namespace std;

class connection {
private:
	boost::asio::ip::tcp::socket sock;
	char buffer[8192];
	boost::asio::io_service::strand strand;
	requestHandler reqHandler();
	typedef boost::shared_ptr<connection> connection_ptr;

public:
	connection(boost::asio::io_service&,requestHandler&);
	boost::asio::ip::tcp::socket getSocket();
	void start();
	void handleRead(const boost::system::error_code& e,size_t bt);
	void handleWrite(const boost::system::error_code& e);
}

connection::connection(boost::asio::io_service& io_s,requestHandler& req)
	:strand(io_s),sock(io_s),reqHandler(req)
{
}

boost::asio::ip::tcp::socket getSocket(){
	return sock;
}

void connection::start(){
	sock.async_read_some(buffer, strand.wrap(boost::bind(&connection::handleRead, this,
          boost::asio::placeholders::error,
          boost::asio::placeholders::bytes_transferred)));//shared_from_this mesa sthn bind epeidh h handleRead einai member function kai kaleitai ws pointer (prwto argument sthn bind
	
}

void connection::handleRead(const boost::system::error_code& e,size_t bt){
	//enalaktika to kanw me iostream
	if(!e){
		int result=reqHandler(buffer);
		if(result==-1){
			std::string error="Bad request\n";
			sock.async_read_some(error,strand.wrap(bind(&connection::handleWrite,boost::asio::placeholders::error)));
		}
		else if(result==0)
		{
			//ο requestHandler επιστρέφει τα αποτελέσματα στον ίδιο buffer που του δίνεται από την κλήση του
			//πριν ξαναγράψει σε αυτόν ΝΑ ΤΟΝ ΚΑΝΩ FLUSH, το χρησιμοποιώ για να στείλω την απάντηση όπως είναι
			sock.async_write_some(buffer,strand.wrap(bind(&connection::handleWrite,boost::asio::placeholders::error)));
		}
		//*/
		//sock.async_write_some(///

}
}
void handleWrite(boost::system::error_code& e){
	//sock.shutdown etc
	}
