/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:12:07 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/03 17:05:04 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	count;

	if (!s)
		return (-1);
	count = 0;
	while (s[count])
		count++;
	return (count);
}
