/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:30:41 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/09/27 11:57:39 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
#define DEBUG 1
#endif

#include <netinet/in.h> // address
#include <iostream>		// std::cout
#include <sys/socket.h> // sockets
#include <cstdio>		// sprintf
#include <vector>		// vector
#include <cstdlib>		//
#include <unistd.h>		// sockets
#include <cstring>		// sockets
#include <fstream>		// files handling
#include <sstream>		// string handling
#include <poll.h>		// poll

void		exit_error(std::string message);
void		debug_message(std::string message);
std::string	my_itoa(int number);
