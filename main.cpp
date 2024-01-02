#include "./main_src/Server.hpp"

int main(void)
{
	try
	{
		Server	server;

		server.runServer();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// 