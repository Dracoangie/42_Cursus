/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:39:53 by angnavar          #+#    #+#             */
/*   Updated: 2024/08/26 10:39:58 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	while (++i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (++j < len)
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_recursive(int nbr, char *base, int base_len)
{
	if (nbr <= -base_len || nbr >= base_len)
		ft_putnbr_recursive(nbr / base_len, base, base_len);
	if (nbr < 0)
		write (1, &base[-(nbr % base_len)], 1);
	else
		write (1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
		write(1, "-", 1);
	ft_putnbr_recursive(nbr, base, base_len);
}
/*
int main() 
{
	ft_putnbr_base(255, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-255, "poniguay");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-42, "0123456789");
	write(1, "\n", 1);
	return 0;
}
*/
