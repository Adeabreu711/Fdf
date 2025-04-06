/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:28:51 by alde-abr          #+#    #+#             */
/*   Updated: 2025/01/09 11:29:50 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief convert all the uppercase chars in the given string
 * "str" to lowercase.
 */
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}
