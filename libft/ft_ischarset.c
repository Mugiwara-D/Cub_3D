/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xacharle <xacharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 03:04:04 by xacharle          #+#    #+#             */
/*   Updated: 2024/04/02 03:06:13 by xacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char c, char *set)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}
