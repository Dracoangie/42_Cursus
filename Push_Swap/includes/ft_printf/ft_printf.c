/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:16:53 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/24 17:52:44 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(int chr)
{
	write(1, &chr, 1);
	return (1);
}

static int	ft_conversion_type(va_list arg, const char chr)
{
	int	i;

	i = 0;
	if (chr == '%')
		i += ft_print_chr('%');
	else if (chr == 'c')
		i += ft_print_chr(va_arg(arg, int));
	else if (chr == 's')
		i += ft_print_str(va_arg(arg, char *));
	else if (chr == 'd' || chr == 'i')
		i += ft_print_num(va_arg(arg, int));
	else if (chr == 'u')
		i += ft_print_unum(va_arg(arg, int));
	else if (chr == 'p')
		i += ft_print_ptr(va_arg(arg, unsigned long));
	else if (chr == 'x')
		i += ft_print_hexnum(va_arg(arg, int), 0);
	else if (chr == 'X')
		i += ft_print_hexnum(va_arg(arg, int), 'a' - 'A');
	else
		i += ft_print_chr(chr);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		size;
	va_list	arg;

	i = 0;
	size = 0;
	va_start(arg, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_conversion_type(arg, str[i + 1]);
			i++;
		}
		else
			size += ft_print_chr(str[i]);
		i++;
	}
	va_end(arg);
	return (size);
}
/*
int main()
{
	//char *ptr_null = NULL;
	//char *ptr = "NULL";

	// ft_printf("Null check:\n");

	// ft_printf("Propia:%i \n", ft_printf(NULL));
	// printf("Estandar:%i\n", printf(NULL));


	// ft_printf("%% check:\n");

	// ft_printf("Propia: %% \n");
	// printf("Estandar: %%\n");

	
	// ft_printf("string check:\n");

	// ft_printf("Propia:\n");
	// ft_printf("lenght: %i \n", ft_printf("%s\n", NULL));
	// printf("Estandar:\n");
	// printf("lenght: %i \n", printf("%s\n", NULL));

	// ft_printf("Propia:\n");
	// ft_printf("lenght: %i \n", ft_printf("hola %s \n", "mundo"));
	// printf("Estandar:\n");
	// printf("lenght: %i \n", printf("hola %s \n", "mundo"));
    // return 0;


	// ft_printf("Num check:\n");

	// ft_printf("Propia:\n");
	// ft_printf("len: %i \n", ft_printf("unum: %u \n", 4294967295));
	// ft_printf("len: %i \n", ft_printf("num: %i \n", -2147483648));
	// ft_printf("len: %i \n", ft_printf("num: %i \n", 0));
	// printf("Estandar:\n");
	// printf("len: %i \n", printf("unum: %u \n", 4294967295));
	// printf("len: %i \n", printf("num: %i \n", -2147483648));
	// printf("len: %i \n", printf("num: %i \n", 0));


	// ft_printf("Pointer check:\n");
	
	// ft_printf("Propia: \n");
	// ft_printf("len: %i \n", ft_printf("ptr:  %p \n", ptr));
	// ft_printf("len: %i \n", ft_printf("ptr:  %p \n", ptr_null));
	// printf("Estandar: \n");
	// printf("len: %i \n", printf("ptr:  %p \n", ptr));
	// printf("len: %i \n", printf("ptr:  %p \n", ptr_null));


	ft_printf("Hex check:\n");
	ft_printf("Propia: \n");
	ft_printf("len: %i \n", ft_printf("hexnum:  %x \n", 0));
	ft_printf("len: %i \n", ft_printf("hexnum:  %X \n", 15));
	ft_printf("len: %i \n", ft_printf("hexnum:  %x \n", 4294967295));
	ft_printf("len: %i \n", ft_printf("hexnum:  %X \n", 4294967295));
	printf("Estandar: \n");
	printf("len: %i \n", printf("hexnum:  %x \n", 0));
	printf("len: %i \n", printf("hexnum:  %X \n", 15));
	printf("len: %i \n", printf("hexnum:  %x \n", 4294967295));
	printf("len: %i \n", printf("hexnum:  %X \n", 4294967295));

    return 0;
}*/
