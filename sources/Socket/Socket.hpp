#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <iostream>
# include <string>

class Socket
{
	public:
		// Constructors
		Socket();
		Socket(const Socket &copy);
		Socket(int file_des);
		
		// Destructor
		~Socket();
		
		// Operators
		Socket & operator=(const Socket &assign);
		
		// Getters / Setters
		int getFile_des() const;
		
	private:
		int _file_des;
};

#endif     // SOCKET_HPP
