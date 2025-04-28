/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:49:09 by angnavar          #+#    #+#             */
/*   Updated: 2025/04/08 16:23:05 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j]; j++)
				argv[i][j] = toupper(argv[i][j]);
			std::cout << argv[i];
		}
		std::cout << '\n';
		return(0);
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
	return(0);
}