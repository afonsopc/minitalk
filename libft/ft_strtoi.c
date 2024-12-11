/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 22:07:48 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/10 22:09:14 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_strtoi(char *str)
{
	int		sign;
	long	num;

	if (!str)
		return (LONG_MAX);
	sign = 1;
	num = 0;
	if ((*str == '-' || *str == '+') && *str++ == '-')
		sign = -1;
	if (!*str)
		return (LONG_MAX);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + ((*str++ - '0'));
		if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
			return (LONG_MAX);
	}
	if (*str)
		return (LONG_MAX);
	return (num * sign);
}
