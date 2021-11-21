/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:41:23 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/12 02:36:45 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../../libft/libft.h"

int		ft_printf(const char *format, ...);
int		case_printf(const char *format, va_list args);
void	ft_putstr(char *str, int *count);
void	ft_putchar(int c, int *count);
void	ft_putnbr(int nb, int *count);
void	hex(unsigned long nb, char *base, int *count);
void	ft_itoa_unsiged(unsigned int nb, int *count);
int		int_count_n(int nb);

#endif