/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:07:05 by alexandre         #+#    #+#             */
/*   Updated: 2025/03/07 19:40:18 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*ft_set_tempunsnb(char *temp, t_conv *conv, int size, int hexalen)
{
	int	i;

	i = 0;
	temp = ft_memset(temp, ' ', size);
	if (hexalen < conv->precision)
	{
		hexalen = conv->precision;
		i = (size - hexalen) * !(conv->flags & ALIGN_L);
		while (--hexalen >= 0)
			temp[i++] = '0';
	}
	else if ((conv->flags & NFILL) && !(conv->flags & ALIGN_L)
		&& conv->precision == -1)
		temp = ft_memset(temp, '0', size);
	return (temp);
}

static char	*ft_assign_ptr(char *temp, t_conv *conv, t_uint64 nb, char *base)
{
	char	*hexa;
	char	*dec;
	int		hexalen;
	int		size;
	int		offset;

	size = strlen(temp);
	dec = ft_ui64itoa(nb);
	hexa = ft_ui64convert_base(dec, "0123456789", base);
	if (!hexa)
		return (free(dec), temp);
	hexalen = ft_strlen(hexa);
	offset = (conv->precision - hexalen) * (hexalen < conv->precision);
	if (!!(conv->flags & ALIGN_L))
	{
		ft_memmove(temp, "0x", 2);
		ft_memmove(temp + 2 + offset, hexa, hexalen);
		return (free(hexa), free(dec), temp);
	}
	if ((conv->flags & NFILL) && conv->precision == -1)
		ft_memmove(temp, "0x", 2);
	else
		ft_memmove(temp + (size - hexalen - offset) - 2, "0x", 2);
	ft_memmove(temp + (size - hexalen), hexa, hexalen);
	return (free(hexa), free(dec), temp);
}

int	ft_pfbuildptr(t_sbuild *out, t_conv *conv, t_uint64 nb)
{
	char	*temp;
	char	*base;
	int		hexalen;
	int		size;

	if (!ft_pfnullcheck(out, conv, !(t_uint64)nb, "(nil)"))
		return (conv->lenght);
	base = "0123456789abcdef";
	hexalen = ft_ui64digitcount_base(nb, base);
	size = hexalen + 2;
	if (conv->witdh > size || conv->precision + 2 > size)
		size = ft_intcomp(conv->witdh, conv->precision + 2, 1);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_set_tempunsnb(temp, conv, size, hexalen);
	temp = ft_assign_ptr(temp, conv, nb, base);
	ft_sb_addstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
