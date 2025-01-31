/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:30:26 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/13 15:30:31 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main(void)
{
	int div;
	int mod;
	int a = 42;
	int b = 10;

	ft_div_mod(a, b, &div, &mod); 
	printf("resultado: %i / %i igual a %i y el moduo es %i", a, b, div, mod);
    
    return 0;
}

