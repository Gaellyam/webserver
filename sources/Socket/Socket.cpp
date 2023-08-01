#include "Socket.hpp"

// Constructors
Socket::Socket()
{
	_file_des = 0;
}

Socket::Socket(const Socket &copy)
{
	_file_des = copy.getFile_des();
}

Socket::Socket(int file_des)
{
	_file_des = file_des;
}


// Destructor
Socket::~Socket()
{
}


// Operators
Socket & Socket::operator=(const Socket &assign)
{
	_file_des = assign.getFile_des();
	return *this;
}


// Getters / Setters
int Socket::getFile_des() const
{
	return _file_des;
}
