/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:31:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/08/03 04:44:26 by sdi-lega         ###   ########.fr       */
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
		std::cerr << "Not enough  arguments." << std::endl;
		return (1);
	}
	MySocket test(9000);
	while (1)
	{
		printf("\n+++++++ Waiting for new connection ++++++++\n\n");
		int new_socket, valread;
		new_socket = test.accept_connection();
		std::cout << "Connection accepted\n";
		char buffer[30000] = {0};
        valread = read( new_socket , buffer, 30000);
        printf("%s\n",buffer );
        write(new_socket , "hello" , 5);
        printf("------------------Hello message sent-------------------\n");
        close(new_socket);
		// ouvrir localhost:9000 sur son navigateur crée une connection
	}
	return (0);
}
