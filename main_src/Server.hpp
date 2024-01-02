#ifndef SERVER_HPP
#define SERVER_HPP

#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <poll.h>
#include <unistd.h>

#include "../sub_src/Error.hpp"

#define PORT 6667
#define CONNECT_MAX 512
#define BUFFER_SIZE 512

class Server
{
	private:
		int					server_fd;
		int					send_size;

		void				Server::connectNewClient(int i);
		void				Server::operServer();



		struct	sockaddr_in	host_addr;
		struct	sockaddr_in	client_addr;

		struct	pollfd		pollfds[CONNECT_MAX];
	public:
		Server();
		~Server();
		void	runServer();
};

#endif