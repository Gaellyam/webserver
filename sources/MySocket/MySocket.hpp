/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySocket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:29:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/08/01 22:44:49 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSOCKET_HPP
#define MYSOCKET_HPP

#include "include.h"

class MySocket
{
public:
	// Constructors
	MySocket(int port);
	MySocket(const MySocket &copy);

	// Destructor
	~MySocket();

	// Operators
	MySocket &operator=(const MySocket &assign);

	// Getters / Setters
	int getFile_des() const;

	int accept_connection(void);
private:
	struct sockaddr_in	_server_address;
	int					_file_des;
	int					_port;
};

#endif // MYSOCKET_HPP
