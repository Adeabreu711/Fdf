/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 03:04:37 by alex              #+#    #+#             */
/*   Updated: 2025/04/28 17:38:15 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	check_size(char *r_map);
int	check_info(char *info);
int	check_map(char *r_map);

//return 1 if the map is valid, 0 if not.
int	is_map_valid(char *r_map)
{
	if (!check_size(r_map) || !check_map(r_map))
		return (0);
	return (1);
}

//return 1 if the size of the map can be rendered properly, 0 if not.
int	check_size(char *r_map)
{
	int	i;
	int	col;
	int	row_len;
	int	row_max;

	i = -1;
	col = 0;
	row_len = 0;
	row_max = 0;
	while (r_map[++i])
	{
		if (r_map[i] == '\n')
		{
			if (row_len > row_max)
				row_max = row_len;
			if (row_max > 1 && ++col > 1)
				return (1);
			row_len = 0;
		}
		else if (is_map_point(r_map, i))
			row_len++;
	}
	return (0);
}

//return the lenght of given point info or 0 if the point isn't valid.
int	check_info(char *info)
{
	int	i;
	int	hexa_len;

	i = 0;
	if (ft_is_sign(info[i]))
		i++;
	if (!ft_isdigit(info[i]))
		return (0);
	while (ft_isdigit(info[i]))
		i++;
	if (!info[i] || ft_is_space(info[i]))
		return (i);
	if (info[i++] == ',')
	{
		hexa_len = check_hexa_color(info + i);
		if (hexa_len)
			return (hexa_len + i);
	}
	return (0);
}

//return 1 if the given map contain errors, 0 if not.
int	check_map(char *r_map)
{
	int	i;
	int	row_len;
	int	info_len;

	i = -1;
	row_len = 0;
	while (r_map[++i])
	{
		if (r_map[i] == '\n' && row_len)
			row_len = 0;
		else if (r_map[i] == '\n')
			return (ft_printf("error : empty line in file\n"), 0);
		else if (is_map_point(r_map, i))
		{
			info_len = check_info(r_map + i);
			if (!info_len)
				return (ft_printf("error : invalid point in file"), 0);
			i += info_len - 1;
			row_len++;
		}
		else if (!ft_is_space(r_map[i]))
			return (ft_printf("error : invalid character in file\n"), 0);
	}
	return (1);
}
