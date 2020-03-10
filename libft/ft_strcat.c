/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:59:24 by kkinzers          #+#    #+#             */
/*   Updated: 2018/12/06 18:13:48 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (s1[s])
		s++;
	while (s2[i])
	{
		s1[s] = s2[i];
		i++;
		s++;
	}
	s1[s] = '\0';
	return (s1);
}