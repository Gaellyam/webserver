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
MySocket::MySocket(int port)
{
	int					domain, service, protocol;
	struct sockaddr_in	server_address;

	debug_message("Creating socket with port: " + my_itoa(port));
	domain = AF_INET;
	service = SOCK_STREAM;
	protocol = 0;
	_file_des = socket(domain, service, protocol);
	if (_file_des == -1)
		exit_error("Error creating a socket.");
	server_address.sin_family = domain;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(port);
	if (bind(_file_des, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
		exit_error("Error assigning a name to the socket (bind)");
}

MySocket::MySocket(const MySocket &copy)
{
	_file_des = copy.getFile_des();
}

// Destructor
MySocket::~MySocket()
{
	debug_message("Destructor of socket called");
	close(_file_des);
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
