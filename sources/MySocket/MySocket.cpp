/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySocket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:29:56 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/08/01 23:05:11 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySocket.hpp"

// Constructors
MySocket::MySocket(int port): _file_des(-1), _port(port) 
{
	int					domain, service, protocol;

	debug_message("Creating socket with port: " + my_itoa(_port));
	domain = AF_INET;
	service = SOCK_STREAM;
	protocol = 0;
	_file_des = socket(domain, service, protocol); 											// creation du file descriptor pour le socket
	if (_file_des == -1)
		exit_error("Error creating a socket.");
	_server_address.sin_family = domain;
	_server_address.sin_addr.s_addr = INADDR_ANY;
	_server_address.sin_port = htons(_port);													// server_adress stocke l'adresse et le port pour l'assigner au socket
	if (bind(_file_des, (struct sockaddr *)&_server_address, sizeof(_server_address)) == -1)
	{
		std::cout << "test1" <<std::endl;
		perror("test");
		exit_error("Error assigning a name to the socket (bind)");
	}
}

MySocket::MySocket(const MySocket &copy): _file_des(copy._file_des), _port(copy._port), _server_address(copy._server_address)
{
	
}

// Destructor
MySocket::~MySocket()
{
	debug_message("Destructor of socket called");
}

// Operators
MySocket	&MySocket::operator=(const MySocket &assign)
{
	_file_des = assign.getFile_des();
	return *this;
}

// Getters / Setters
int	MySocket::getFile_des() const
{
	return _file_des;
}

int MySocket::accept_connection(void)
{
	int	new_socket;
	int address_length;
	address_length = sizeof(_server_address);
	new_socket = accept(_file_des, (struct sockaddr *)&_server_address, (socklen_t *)&address_length);
	if (new_socket == -1)
		exit_error("Error accepting connection");
	return (new_socket);
}

void MySocket::set_listen()
{
	if (listen(_file_des, 10) == -1)
		exit_error("Error listening to the socket");
}
