/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:11:35 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/10 21:35:32 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
ssize_t	ft_strlen(const char *s);
ssize_t	ft_error(char *message);

#endif