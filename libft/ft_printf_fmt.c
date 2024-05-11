/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmertane <jmertane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:53:31 by jmertane          #+#    #+#             */
/*   Updated: 2023/12/10 13:01:30 by jmertane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	st_fmt_chr(t_print *output, int chr)
{
	if (ft_putchar_fd(chr, 1) < 0)
		output->length = -1;
	else
		output->length += 1;
}

void	st_fmt_str(t_print *output, char *str)
{
	if (!str)
		output->result = ft_putstr_fd("(null)", 1);
	else
		output->result = ft_putstr_fd(str, 1);
	if (output->result < 0)
		output->length = -1;
	else
		output->length += output->result;
}

void	st_fmt_int(t_print *output, long val)
{
	output->result = ft_putnbr_fd(val, 1);
	if (output->result < 0)
		output->length = -1;
	else
		output->length += output->result;
}

void	st_fmt_hex(t_print *output, unsigned long hex, char spec)
{
	if (hex >= 16)
		st_fmt_hex(output, hex / 16, spec);
	if (spec == 'p' && hex < 16)
		st_fmt_str(output, "0x");
	if (output->length < 0)
		return ;
	if (spec == 'x' || spec == 'p')
		st_fmt_chr(output, HEXLOW[hex % 16]);
	else
		st_fmt_chr(output, HEXUPP[hex % 16]);
}
