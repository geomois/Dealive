#include <boost/asio.hpp>
#include <string>
#include <vector>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>



class server
  : private boost::noncopyable
{
public:
  server(boost::asio::io_service& io_s, std::size_t thread_pool, const string& address);

  void run();

private:
  void start_accept();
/// Handle completion of an asynchronous accept operation.
  void handle_accept(const boost::system::error_code& e);
/// Handle a request to stop the server.
  void handle_stop();
  
  boost::asio::io_service io_s;
  boost::asio::ip::tcp::acceptor acceptor;
  shared_ptr<connection> newConnection;
}