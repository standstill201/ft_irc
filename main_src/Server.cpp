#include "./Server.hpp"

static void	removeFD(struct pollfd *pfd)
{
	close(pfd->fd);
	pfd->fd = -1;
}

void	Server::connectNewClient(int i)
{
	const	char	*welcome_message("Welcome! and this string have to be changed");

	socklen_t		sockaddr_in_size = sizeof(struct sockaddr_in);
	if (pollfds[i].revents & POLLIN)
	{
		int accepted_fd = accept(server_fd, reinterpret_cast<struct sockaddr *>(&client_addr), &sockaddr_in_size);
		if (accepted_fd < 0)
			std::cout << "err\n"; //err
		
		for (int j = 0; j < CONNECT_MAX; j++)
		{
			if (pollfds[j].fd == -1)
			{
				pollfds[j].fd = accepted_fd;
				pollfds[j].events = POLLIN;
				break;
			}
			if (j == CONNECT_MAX)
				std::cout << "err\n"; //err
		}
		std::cout << "Client IP: " << inet_ntoa(client_addr.sin_addr) << "PORT: " << ntohs(client_addr.sin_port) << std::endl;
		send_size = send(accepted_fd, welcome_message, strlen(welcome_message), 0);
		if (send_size < 0)
			std::cout << "err\n"; //err
	}
}

void	Server::operServer()
{
	
}


Server::Server()
{
	// 이 생성자는 서버의 첫 설정을 담당합니다. 소켓 생성, 바인드, 리슨함수를 사용해서요. 그다음, poll함수에 초기 설정값을 넣어놓습니다.
	server_fd = socket(PF_INET, SOCK_STREAM, 0);
	if (server_fd < 0)
		Error::fatalError("Socket initialize error");
	memset(&host_addr, 0, sizeof(host_addr));
	host_addr.sin_family = AF_INET; 
	host_addr.sin_port = htons(PORT);
	host_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(server_fd, reinterpret_cast<struct sockaddr *>(&host_addr), sizeof(struct sockaddr)) < 0)
		Error::fatalError("Bind initialize error");

	if (listen(server_fd, 3) < 0)
		Error::fatalError("Listen initialize error");

}

void	Server::runServer()
{
	
}

Server::~Server()
{

}
