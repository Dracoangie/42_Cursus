/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:42 by angnavar          #+#    #+#             */
/*   Updated: 2024/12/02 12:49:46 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf/ft_printf.h"
#include "../includes/libft/libft.h"

int to_num(char *argv)
{
    int sign;
    int result;
    char buffer[42];
    ssize_t bytes_read;

    while (1)
    {
        sign = 1;
        result = 0;

        if (!argv || *argv == '\0')
        {
            write(2, "Error: Argumento inválido. Introduce un número:\n", 48);
            bytes_read = read(0, buffer, 42);
            if (bytes_read <= 0)
                exit(EXIT_FAILURE);

            buffer[bytes_read] = '\0';
            argv = buffer;
        }

        if (*argv == '-')
        {
			sign = -1;
            argv++;
        }

        int valid = 1;
        for (char *ptr = argv; *ptr; ptr++)
        {
            if (*ptr < '0' || *ptr > '9')
            {
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            write(2, "Error: Argumento inválido. Introduce un número:\n", 48);
            bytes_read = read(0, buffer, 42);
            if (bytes_read <= 0)
                exit(EXIT_FAILURE);
            buffer[bytes_read] = '\0';
            argv = buffer;
            continue;
        }

        while (*argv >= '0' && *argv <= '9')
        {
            result = result * 10 + (*argv - '0');
            argv++;
        }

        return (result * sign);
    }
}

t_list *argv_checker(char **argv)
{
    t_list *result;

    argv++;
    if (!*argv)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    result = ft_lstnew(to_num(*argv));
    argv++;
    while (*argv)
    {
        ft_lstadd_back(&result, ft_lstnew(to_num(*argv)));
        argv++;
    }
    return (result);
}

void print_content(int content)
{
    ft_printf("%d\n", content);
}

int main(int argc, char **argv)
{
    t_list *nums;

    if (argc <= 2)
        return (0);

    nums = argv_checker(argv);
    ft_lstiter(nums, print_content);

    return (0);
}
