#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/event.h>
#include <map>
#include <vector>
#include <unistd.h>

class Server
{
	private:
		int serverSocket;
		int kq;
		std::map<int, std::string> clients;
		std::vector<struct kevent> changeList;
		struct kevent eventList[8];
	public:
		Server(int port);
		void runServer();
		void changeEvents(std::vector<struct kevent>& changeList, uintptr_t ident, int16_t filter,
					uint16_t flags, uint32_t fflags, intptr_t data, void *udata);
		void disconnect_client(int client_fd, std::map<int, std::string>& clients);
};

#endif