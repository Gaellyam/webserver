/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 07:53:10 by sdi-lega          #+#    #+#             */
/*   Updated: 2023/08/02 08:21:55 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

std::string	my_itoa(int number)
{
	char	num[12];

	std::memset(num, 0, 12);
	sprintf(num, "%d", number);
	return (std::string(num));
}

void	exit_error(std::string message)
{
	std::cerr << message << std::endl;
	exit(EXIT_FAILURE);
}

void	debug_message(std::string message)
{
	if (DEBUG == 1)
		std::cout << message << std::endl;
}