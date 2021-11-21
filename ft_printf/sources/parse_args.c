/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeshaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:47:03 by pdeshaye          #+#    #+#             */
/*   Updated: 2021/11/12 02:31:39 by pdeshaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int static	case_print_part2(const char *format, int *count,
	va_list args, int index)
{
	int		temp_count;
	char	temp;

	temp = 0;
	if (format[index + 1])
		temp = format[index + 1];
	temp_count = *count;
	if (format[index] == '%' && (temp && temp == 'c'))
		ft_putchar(va_arg(args, int), count);
	else if (format[index] == '%' && (temp && (temp == 'i' || temp == 'd')))
		ft_putnbr(va_arg(args, int), count);
	else if (format[index] == '%' && (temp && temp == 'p'))
	{
		ft_putstr("0x", count);
		hex(va_arg(args, unsigned long), "0123456789abcdef", count);
	}
	else if (format[index] == '%' && (temp && temp == 'u'))
		ft_itoa_unsiged(va_arg(args, unsigned int), count);
	else if (format[index] == '%' && (temp && temp == '%'))
		ft_putchar('%', count);
	else if (format[index] == '%' && (temp && temp == 'x' ))
		hex(va_arg(args, unsigned int), "0123456789abcdef", count);
	if (temp_count == *count)
		return (0);
	return (1);
}

int	case_printf(const char *format, va_list args)
{
	int		index;
	int		count;
	char	temp;

	count = 0;
	index = 0;
	while (format[index] != '\0')
	{
		temp = 0;
		if (format[index + 1])
			temp = format[index + 1];
		if (format[index] == '%' && (temp && temp == 'X'))
			hex(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
		else if (format[index] == '%' && (temp && temp == 's'))
			ft_putstr(va_arg(args, char *), &count);
		else if (!case_print_part2(format, &count, args, index))
		{
			ft_putchar_fd(format[index], 1);
			index++;
			count++;
			continue ;
		}
		index += 2;
	}
	return (count);
}
