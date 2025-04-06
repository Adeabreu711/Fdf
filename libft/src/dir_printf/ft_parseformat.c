/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:11:24 by alde-abre         #+#    #+#             */
/*   Updated: 2025/02/07 12:05:45 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_strdigitcount(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (ft_isdigit(str[++i]))
		count++;
	return (count);
}

void	ft_init_conv(t_conv *out)
{
	ft_memset(out, 0, sizeof(t_conv));
	out->precision = -1;
	out->flags = 0;
}

void	ft_get_flags(t_conv *out, char *format)
{
	int				i;
	int				temp;
	unsigned char	bit;

	i = -1;
	bit = 0b10000000;
	while (format[++i] && ft_strchr("-+0 #", format[i]))
	{
		temp = ft_strlen(ft_strchr("-+0 #", format[i]));
		if (temp)
			out->flags |= bit >> (5 - temp);
	}
	out->lenght += i;
}

int	ft_parseformat(t_conv *out, char *format)
{
	if (format[0] != '%')
		return (0);
	ft_init_conv(out);
	out->lenght++;
	ft_get_flags(out, format + out->lenght);
	out->witdh = ft_atoi(format + out->lenght);
	if (ft_isdigit(format[out->lenght]))
		out->lenght += ft_strdigitcount(format + out->lenght);
	if (!format[out->lenght])
		return (0);
	if (format[out->lenght] == '.')
	{
		out->precision = ft_atoi(format + (out->lenght + 1));
		if (ft_isdigit(format[out->lenght + 1]))
			out->lenght += ft_strdigitcount(format + out->lenght + 1);
		out->lenght++;
	}
	if (ft_strchr("cspdiuxX%", format[out->lenght]))
		out->type = *ft_strchr("cspdiuxX%", format[out->lenght]);
	if (out->type)
	{
		out->lenght++;
		return (out->lenght);
	}
	return (0);
}
