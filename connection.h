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
	boost::array<char, 1024> buffer;
	boost::asio::io_service::strand strand;
	requestHandler reqHandler();
	typedef boost::shared_ptr<connection> connection_ptr;

public:
	connection(boost::asio::io_service&);
	boost::asio::ip::tcp::socket getSocket();
	void start();
	void handleRead(const boost::system::error_code& e,size_t bt);
}