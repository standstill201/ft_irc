#include <string>

class Message
{
	private:
		std::string	msg;
		std::string	command;
		Message();

	public:
		std::string		commandNotifier();
		std::string		messageNotifier();
		Message(std::string msg);
		~Message();
};
