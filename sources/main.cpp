/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:31:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/09/26 01:20:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySocket.hpp"
#include "include.h"

int	main(int argc, char const *argv[])
{
	struct pollfd	fds[5];
	int				fd;
	int				valread;
	// char			buffer[30000];

	// char	buffer[30000];
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Using default path" << std::endl;
		// return (1);
	}
	MySocket arr[2] = {9002, 9001};
	memset(fds, 0, sizeof(fds));
	fds[0].fd = arr[0].getFile_des();
	fds[0].events = POLLIN;
	fds[1].fd = arr[1].getFile_des();
	fds[1].events = POLLIN;
	std::stringstream buff_stream;
	while (1)
	{
		std::string header = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\n\n";
		std::string whole = header + "test";
		printf("\n+++++++ Waiting for new connection ++++++++\n\n");
		char buffer[30000] = {0};
		std::cout << "Before poll:\nevent 1: " << fds[0].revents << "\nevent 2: " << fds[1].revents << std::endl;
		if (poll(fds, 2, -1) > 0)
		{
			std::cout << "After poll:\nevent 1: " << fds[0].revents << "\nevent 2: " << fds[1].revents << std::endl;
			for (size_t i = 0; i < 2; i++)
			{
				if (fds[i].revents == POLLIN)
				{
					std::cout << "index: " << i << std::endl;
					fd = arr[i].accept_connection();
					valread = read(fd, buffer, 30000);
					std::cout << buffer << std::endl;
					write(fd , whole.c_str(), strlen(whole.c_str()));
					std::cout << "------------------Hello message sent-------------------\n" << std::endl;
					buff_stream.str("");
					close(fd);
					fds[i].revents = 0;
				}
				else if (fds[i].revents == POLLHUP)
				{
					arr[i].set_listen();
					fds[i].revents = 0;
				}
			}
		}
		else
		{
			std::cerr << "error with poll." << std::endl;
		}
		// ouvrir localhost:9000 sur son navigateur crée une connection
	}
	return (0);
}
