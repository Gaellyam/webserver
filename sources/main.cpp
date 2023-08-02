/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:31:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/08/02 08:22:03 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include "MySocket.hpp"

int	main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Not enough  arguments." << std::endl;
		return (1);
	}
	MySocket test(9000);
	(void)argv;
	return 0;
}
