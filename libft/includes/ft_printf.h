/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:27:17 by alde-abr          #+#    #+#             */
/*   Updated: 2025/04/06 18:50:59 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_string_builder.h"
# include <stdarg.h>

# define ALIGN_L	0b10000000 // '-'
# define SIGN		0b01000000 // '+'
# define NFILL		0b00100000 // '0'
# define ADD_SPACE	0b00010000 // ' '
# define PREFIX		0b00001000 // '#'

typedef struct s_conv
{
	char	flags;
	int		witdh;
	int		precision;
	char	type;
	int		lenght;
}	t_conv;

int			ft_printf(const char *s, ...);
int			ft_fprintf(int fd, const char *s, ...);
int			ft_parseformat(t_conv *out, char *format);

int			ft_pfbuildchar(t_sbuild *out, t_conv *conv, char c);
int			ft_pfbuildstr(t_sbuild *out, t_conv *conv, char *str);
int			ft_pfbuildnb(t_sbuild *out, t_conv *conv, int nb);
int			ft_pfbuildunsnb(t_sbuild *out, t_conv *conv, t_uint32 nb);
int			ft_pfbuildhexa(t_sbuild *out, t_conv *conv, t_uint32 nb);
int			ft_pfbuildptr(t_sbuild *out, t_conv *conv, t_uint64 nb);
int			ft_pfnullcheck(t_sbuild *out, t_conv *conv, t_uint64 nb, char *s);

char		*ft_strprcut(char *str, int precision);
int			ft_digitcount(int nb);
char		ft_getsign(int nb);
int			ft_ui64digitcount(t_uint64 nb);
char		*ft_ui64itoa(t_uint64 nb);
t_uint64	ft_ui64atoi_base(char *str, char *base);
int			ft_ui64digitcount_base(t_uint64 dec, char *base_to);
char		*ft_ui64convert_base(char *n, char *base_from, char *base_to);
int			ft_strdigitcount(char *str);

#endif
