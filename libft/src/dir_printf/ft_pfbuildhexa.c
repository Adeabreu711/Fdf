/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildhexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:01:33 by alex              #+#    #+#             */
/*   Updated: 2025/03/07 19:40:06 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_get_hexa_size(t_conv *conv, int hexalen, t_uint32 nb)
{
	int	size;
	int	sflag;

	size = hexalen;
	sflag = conv->precision + !!(conv->flags & PREFIX) * 2;
	if (sflag && conv->witdh < sflag && sflag > hexalen)
		return (sflag);
	if (conv->witdh > size || conv->precision > size)
		size = ft_intcomp(conv->witdh, conv->precision, 1);
	if (!!(conv->flags & PREFIX) && nb && conv->witdh < hexalen + 2
		&& conv->witdh > conv->precision)
		size += 2;
	return (size);
}

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

static void	ft_add_prefix(char *temp, int prefix)
{
	if (prefix)
		ft_memmove(temp, "0x", 2);
}

static char	*ft_assign_hexa(char *temp, t_conv *conv, t_uint32 nb, char *base)
{
	char	*hexa;
	char	*dec;
	int		hexalen;
	int		offset;
	int		prefix;

	prefix = ((conv->flags & PREFIX) && nb);
	dec = ft_ui64itoa((t_uint64)nb);
	hexa = ft_ui64convert_base(dec, "0123456789", base);
	if (!hexa)
		return (free(dec), temp);
	hexalen = ft_strlen(hexa);
	offset = (conv->precision - hexalen) * (hexalen < conv->precision);
	if (conv->flags & ALIGN_L)
	{
		ft_add_prefix(temp, prefix);
		ft_memmove(temp + prefix * 2 + offset, hexa, hexalen);
		return (free(hexa), free(dec), temp);
	}
	if ((conv->flags & NFILL) && conv->precision == -1 && prefix)
		ft_memmove(temp, "0x", 2);
	else if (prefix)
		ft_memmove(temp + (strlen(temp) - hexalen - offset) - 2, "0x", 2);
	ft_memmove(temp + (strlen(temp) - hexalen), hexa, hexalen);
	return (free(hexa), free(dec), temp);
}

int	ft_pfbuildhexa(t_sbuild *out, t_conv *conv, t_uint32 nb)
{
	char	*temp;
	char	*base;
	int		hexalen;
	int		size;

	if (!ft_pfnullcheck(out, conv, !(t_uint64)nb, ""))
		return (conv->lenght);
	base = "0123456789abcdef";
	hexalen = ft_ui64digitcount_base((t_uint64)nb, base);
	size = ft_get_hexa_size(conv, hexalen, nb);
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_set_tempunsnb(temp, conv, size, hexalen);
	temp = ft_assign_hexa(temp, conv, nb, base);
	if (conv->type == 'X')
		temp = ft_strupcase(temp);
	ft_sb_addstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
