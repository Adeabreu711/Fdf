/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:25:47 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:42 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_splits(char const *s, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
		if (c != s[i] && (!s[i + 1] || s[i + 1] == c))
			count++;
	return (count);
}

static char	**ft_freesplits(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}

static int	ft_get_splitstart(const char *s, char c)
{
	int	i;

	i = -1;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

/**
 * @brief Split a string into multiple strings. depending on the separator "c".
 * @param {charconst*} "s" pointer to a string to split.
 * @param {char} "c" sepator used to delimit the string "s".
 * @return A pointer of strings corresponding to the split of the string
 * "s" by the separator "c".
 */
char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	str = ft_calloc(ft_count_splits(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	start = ft_get_splitstart(s, c);
	while (s[++i])
	{
		if (c != s[i] && (i == 0 || s[i - 1] == c))
			start = i;
		if (c != s[i] && (!s[i + 1] || s[i + 1] == c))
		{
			str[j] = ft_substr(s, start, i - start + 1);
			if (!str[j++])
				return (ft_freesplits(str));
		}
	}
	return (str);
}
