#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "connection.h"


class server
  : private boost::noncopyable
{
public:
	server(std::size_t, const string);
	requestHandler reqHandler();
	shared_ptr<connection> newConnection;
	
private:
	boost::asio::io_service io_s;
	tcp::acceptor acceptor;
	size_t threadPoolSize;
	
	void run();
	void start_accept();
	void handle_stop();
	void handle_accept(const boost::system::error_code&);
	shared_ptr<connection> newConnection;
};
