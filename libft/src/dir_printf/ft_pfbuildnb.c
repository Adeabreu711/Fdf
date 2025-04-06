/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfbuildnb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 18:54:25 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/07 19:21:40 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	ft_getsign(int nb)
{
	if (nb < 0)
		return ('-');
	return ('+');
}

static char	*ft_set_tempunsnb(char *temp, t_conv *conv, int size, int nb)
{
	int	i;
	int	nblen;
	int	space;

	i = 0;
	nblen = ft_digitcount(nb);
	space = !!(conv->flags & ADD_SPACE);
	temp = ft_memset(temp, ' ', size);
	if (nblen < conv->precision + (nb < 0))
	{
		nblen = conv->precision + (nb < 0);
		i = (size - nblen) * !(conv->flags & ALIGN_L);
		i += !!(conv->flags & ALIGN_L) * !!(conv->flags & ADD_SPACE);
		while (--nblen >= 0)
			temp[i++] = '0';
	}
	else if ((conv->flags & NFILL) && !(conv->flags & ALIGN_L)
		&& conv->precision == -1)
		ft_memset(temp + space, '0', size - space);
	return (temp);
}

static char	*ft_assign_nb(char *temp, t_conv *conv, int nb, int size)
{
	int		nblen;
	int		offset;
	int		ng;
	char	*snb;

	ng = (nb < 0);
	offset = 0;
	nblen = ft_digitcount(nb);
	snb = ft_itoa(nb);
	if (!snb)
		return (temp);
	if (nblen < conv->precision + ng)
		offset += conv->precision + ng - nblen;
	if (conv->flags & ALIGN_L)
		ft_memmove(temp + ((conv->flags & SIGN) || (conv->flags & ADD_SPACE)
				|| ng) + offset, snb + ng, nblen - ng);
	else
		ft_memmove(temp + (size - nblen + ng), snb + ng, nblen - ng);
	if (((conv->flags & NFILL) && conv->precision == -1)
		|| (conv->flags & ALIGN_L))
		temp[0] += (ft_getsign(nb) - temp[0]) * ((conv->flags & SIGN) || ng);
	else if ((conv->flags & SIGN && nb >= 0) || ng)
		temp[size - nblen - !ng - offset] = ft_getsign(nb);
	return (free(snb), temp);
}

int	ft_pfbuildnb(t_sbuild *out, t_conv *conv, int nb)
{
	char	*temp;
	int		size;
	int		sflag;

	if (!ft_pfnullcheck(out, conv, !(t_uint64)nb, ""))
		return (conv->lenght);
	sflag = (((conv->flags & SIGN) && nb >= 0)
			|| ((conv->flags & ADD_SPACE) && !(conv->flags & SIGN) && nb >= 0));
	size = ft_digitcount(nb) + sflag;
	if (conv->witdh > size || conv->precision + (nb < 0) > size)
	{
		size = ft_intcomp(conv->witdh, conv->precision + (nb < 0), 1);
		size += (!conv->witdh || conv->witdh < conv->precision) * sflag;
	}
	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (conv->lenght);
	temp = ft_set_tempunsnb(temp, conv, size, nb);
	temp = ft_assign_nb(temp, conv, nb, size);
	ft_sb_addstr(&out, temp, size);
	free(temp);
	return (conv->lenght);
}
