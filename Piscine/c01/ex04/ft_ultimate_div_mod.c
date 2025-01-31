/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:35:45 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/13 15:35:48 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;

	temp_a = *a;
	*a = temp_a / *b;
	*b = temp_a % *b;
}
/*
int main()
{
    int a = 42;
    int b = 10;
    
    char div_char;
    char mod_char;

    ft_ultimate_div_mod(&a, &b);

    div_char = '0' + (a % 10);
    mod_char = '0' + (b % 10);

    write(1, &div_char, 1);
    write(1, ", ", 2);
    write(1, &mod_char, 1);
    
    return 0;
}
*/
