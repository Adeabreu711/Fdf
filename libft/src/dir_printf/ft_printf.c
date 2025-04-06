/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:42:03 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/06 18:50:23 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_clear_printf(t_sbuild **sb, va_list ptr, char *str)
{
	free (str);
	ft_sbclear(sb);
	va_end(ptr);
	return (0);
}

int	ft_pfgetformat(t_sbuild *sb, int count, char *s)
{
	ft_sb_addstr(&sb, (char *)s + count, 1);
	return (1);
}

int	ft_applyconv(va_list ptr, t_conv *conv, t_sbuild *sb)
{
	if (conv->type == 'c')
		return (ft_pfbuildchar(sb, conv, va_arg(ptr, int)));
	else if (conv->type == 's')
		return (ft_pfbuildstr(sb, conv, va_arg(ptr, char *)));
	else if (conv->type == 'i' || conv->type == 'd')
		return (ft_pfbuildnb(sb, conv, va_arg(ptr, int)));
	else if (conv->type == 'u')
		return (ft_pfbuildunsnb(sb, conv, va_arg(ptr, unsigned int)));
	else if (conv->type == 'x' || conv->type == 'X')
		return (ft_pfbuildhexa(sb, conv, va_arg(ptr, unsigned int)));
	else if (conv->type == 'p')
		return (ft_pfbuildptr(sb, conv, va_arg(ptr, unsigned long)));
	ft_sb_addstr(&sb, "%", 1);
	return (conv->lenght);
}

int	ft_printf(const char *s, ...)
{
	int			count;
	char		*str;
	va_list		ptr;
	t_conv		conv;
	t_sbuild	*sb;

	if (!s)
		return (-1);
	sb = ft_sbnew("");
	if (!sb)
		return (0);
	va_start(ptr, s);
	count = 0;
	while (s[count])
	{
		if (!ft_parseformat(&conv, (char *)s + count))
			count += ft_pfgetformat(sb, count, (char *)s);
		else
			count += ft_applyconv(ptr, &conv, sb);
	}
	str = ft_sb_build (sb);
	count = ft_sblen(sb);
	write(1, str, count);
	ft_clear_printf(&sb, ptr, str);
	return (count);
}

int	ft_fprintf(int fd, const char *s, ...)
{
	int			count;
	char		*str;
	va_list		ptr;
	t_conv		conv;
	t_sbuild	*sb;

	if (!s)
		return (-1);
	sb = ft_sbnew("");
	if (!sb)
		return (0);
	va_start(ptr, s);
	count = 0;
	while (s[count])
	{
		if (!ft_parseformat(&conv, (char *)s + count))
			count += ft_pfgetformat(sb, count, (char *)s);
		else
			count += ft_applyconv(ptr, &conv, sb);
	}
	str = ft_sb_build (sb);
	count = ft_sblen(sb);
	write(fd, str, count);
	ft_clear_printf(&sb, ptr, str);
	return (count);
}
