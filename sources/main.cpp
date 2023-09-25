/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:31:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/09/25 12:08:05 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySocket.hpp"
#include "include.h"

int	main(int argc, char const *argv[])
{
	// char	buffer[30000];

	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Using default path" << std::endl;
		// return (1);
	}
	MySocket test(9001);
	std::stringstream buff_stream;
	while (1)
	{
		std::ifstream testfile("test.html");
		buff_stream << testfile.rdbuf();
		std::string header = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\n";
		std::string whole = header + buff_stream.str();
		printf("\n+++++++ Waiting for new connection ++++++++\n\n");
		int new_socket, valread;
		new_socket = test.accept_connection();
		std::cout << "Connection accepted\n";
		char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);
        printf("%s\n",buffer );
        write(new_socket , whole.c_str(), strlen(whole.c_str()));
        printf("------------------Hello message sent-------------------\n");
		buff_stream.str("");
        close(new_socket);
		// ouvrir localhost:9000 sur son navigateur crée une connection
	}
	return (0);
}
