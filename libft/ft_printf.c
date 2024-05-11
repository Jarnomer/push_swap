/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:16:50 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/10 13:54:23 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	st_fmt_spc(t_print *output, va_list args, char spec)
{
	if (spec == '%')
		st_fmt_chr(output, '%');
	else if (spec == 'c')
		st_fmt_chr(output, va_arg(args, int));
	else if (spec == 's')
		st_fmt_str(output, va_arg(args, char *));
	else if (spec == 'i' || spec == 'd')
		st_fmt_int(output, va_arg(args, int));
	else if (spec == 'u')
		st_fmt_int(output, va_arg(args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		st_fmt_hex(output, va_arg(args, unsigned int), spec);
	else if (spec == 'p')
		st_fmt_hex(output, va_arg(args, unsigned long), spec);
}

int	ft_printf(const char *format, ...)
{
	t_print	output;
	va_list	args;

	output.length = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format != '%')
			st_fmt_chr(&output, *format);
		else if (ft_strchr(SPECS, *(format + 1)))
			st_fmt_spc(&output, args, *++format);
		if (output.length < 0 || !*format)
			break ;
		++format;
	}
	va_end (args);
	return (output.length);
}
