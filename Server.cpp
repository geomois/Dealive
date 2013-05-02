#include <boost\asio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost\thread.hpp>
#include "Server.h"
#include "connection.h"
#include "requestHandler.h"
#define port 2000
using boost::asio::ip::tcp;
using namespace std;

server::server(std::size_t thread_pool, std::string address):
	acceptor(io_s),
	newConnection(){

		threadPoolSize= thread_pool;
		shared_ptr<connection> newConnection();
		
		boost::asio::ip::tcp::resolver resolver(io_s);
		boost::asio::ip::tcp::resolver::query query(address, port);
		boost::asio::ip::tcp::endpoint ep = *resolver.resolve(query);
		
		acceptor.open(ep.protocol());
		acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
		acceptor.bind(ep);
		acceptor.listen();


		start_accept();
		
	}

void server::run()
{

  std::vector<boost::thread > threads;
  for (std::size_t i = 0; i < threadPoolSize; i++)
  {
	  boost::thread thread(new boost::thread(
      boost::bind(&boost::asio::io_service::run,&io_s)));
	  threads.push_back(thread);
  }

  for (std::size_t i = 0; i < threads.size(); i++)
	  threads[i].join();

  cout<<"Up and running"<<endl;
}

void server::start_accept(){

		newConnection.reset(new connection(io_s,reqHandler));
		acceptor.async_accept(newConnection->getSocket(),
		boost::bind(&server::handle_accept, this,
        boost::asio::placeholders::error));
}
void server::handle_stop(){
  io_s.stop();
}

void server::handle_accept(const boost::system::error_code& e){
		
  if (!e)
  {
    newConnection->read();
  }

  start_accept();
}