/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:16:43 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/24 17:52:59 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_ptrlen(unsigned long ptr);
int		ft_print_chr(int chr);
int		ft_print_str(char *str);
int		ft_print_unum(unsigned int unum);
int		ft_print_num(int num);
int		ft_print_hexnum(unsigned int unum, int menor);
int		ft_print_ptr(unsigned long ptr);
int		ft_printf(const char *str, ...);

#endif