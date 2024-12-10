/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:52:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/10 21:35:11 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	ret;
	ssize_t	ret2;
	ssize_t	ret3;

	ret = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		ret = write(fd, "-", 1);
		n = -n;
	}
	if (ret < 0)
		return (ret);
	ret2 = 0;
	if (n >= 10)
		ret2 = ft_putnbr_fd(n / 10, fd);
	if (ret2 < 0)
		return (ret2);
	ret3 = write(fd, &"0123456789"[n % 10], 1);
	if (ret3 < 0)
		return (ret3);
	return (ret + ret2 + ret3);
}
