#include <boost\asio.hpp>
#include <boost\array.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace std;

class connection:public boost::enable_shared_from_this<connection>,private boost::noncopyable{
private:
	boost::asio::ip::tcp::socket sock;
	char buffer[8192];
	boost::asio::io_service::strand strand;
	requestHandler& reqHandler;
	typedef boost::shared_ptr<connection> connection_ptr;

public:
	connection(boost::asio::io_service,requestHandler);
	boost::asio::ip::tcp::socket getSocket();
	void read();
	void handleRead(const boost::system::error_code& e,size_t bt);
	void handleWrite(const boost::system::error_code& e);
};
