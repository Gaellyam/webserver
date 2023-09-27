/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:31:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/09/27 13:57:23 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySocket.hpp"
#include "include.h"
#include <fcntl.h>

void	send_message(int file_des, std::string header, std::string content)
{
	write(file_des, header.c_str(), strlen(header.c_str()));
	write(file_des, content.c_str(), content.size());
}

void	receive_message(int file_des)
{
	int					bytes_read;
	char				buffer[10];
	std::stringstream	buff;

	bytes_read = read(file_des, buffer, 10);
	buff.write(buffer, bytes_read);
	fcntl(file_des, F_SETFL, O_NONBLOCK);
	while (bytes_read == 10)
	{
		bytes_read = recv(file_des, buffer, 10, 0);
		buff.write(buffer, bytes_read);
	}
	std::cout << buff.str() << std::endl;
}

void fill_fd_array(struct pollfd *file_des_array, std::vector<MySocket> const &socket_array)
{
	size_t	size = socket_array.size();
	memset(file_des_array, 0, size);
	for (size_t i = 0; i < size; i++)
	{
		file_des_array[i].fd = socket_array[i].getFile_des();
		file_des_array[i].events = POLLIN;
	}
	
}

std::string handle_file(std::string path)
{
	std::ifstream		file(path.c_str(), std::ios_base::binary);
	std::stringstream	buff_stream;

	buff_stream << file.rdbuf();
	std::string response;
	response = buff_stream.str();
	file.close();
	return (response);
}



int	main(int argc, char const *argv[])
{
	unsigned int				socket_number = 2;
	std::vector<MySocket>		socket_array;
	struct pollfd				file_des_array[socket_number];
	int							client_fd;
	(void)argv;

	if (argc != 2)
	{
		std::cerr << "Using default path" << std::endl;
		// return (1);
	}
	MySocket test1 = MySocket(9003);
	MySocket test2 = MySocket(9002);
	socket_array.push_back(test1);
	socket_array.push_back(test2);
	fill_fd_array(file_des_array, socket_array);
	std::string message_content = handle_file("www/small.html");
	while (1)
	{
		std::string header = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n";
		printf("\n+++++++ Waiting for new connection ++++++++\n\n");
		if (poll(file_des_array, socket_number, -1) > 0)
		{
			for (size_t i = 0; i < socket_number; i++)
			{
				if (file_des_array[i].revents == POLLIN)
				{
					client_fd = socket_array[i].accept_connection();
					receive_message(client_fd);
					send_message(client_fd, header, message_content);
					std::cout << "------------------Hello message sent-------------------\n" << std::endl;
					close(client_fd);
					file_des_array[i].revents = 0;
				}
				else if (file_des_array[i].revents == POLLHUP)
				{
					socket_array[i].set_listen();
					file_des_array[i].revents = 0;
				}
			}
		}
		else
		{
			std::cerr << "error with poll." << std::endl;
		}
	}
	return (0);
}
