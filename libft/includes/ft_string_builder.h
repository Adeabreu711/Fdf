/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_builder.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:28:08 by alde-abre         #+#    #+#             */
/*   Updated: 2025/02/07 11:32:10 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_BUILDER_H
# define FT_STRING_BUILDER_H

# define SB_SIZE 128

# include "libft.h"

typedef struct s_sbuild
{
	char	str[SB_SIZE];
	int		id;
	void	*next;
}	t_sbuild;

//utils :
t_sbuild	*ft_sbnew(char *str);
void		ft_sbclear(t_sbuild **container);
t_sbuild	*ft_sblast(t_sbuild *container);
int			ft_sblen(t_sbuild *container);

//string builder :
void		*ft_sb_addstr(t_sbuild **container, char *str, size_t n);
int			ft_sb_display(t_sbuild *container);
char		*ft_sb_build(t_sbuild *container);

#endif
