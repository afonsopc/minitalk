/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:08:26 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/10 21:15:24 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf("Hello from MiniTalk! :)\n");

#include "includes/minitalk.h"

t_server	*global_server(void)
{
	static t_server	server;

	return (&server);
}

int	main(void)
{
	global_server()->pid = getpid();
	ft_putstr_fd("Server started.\nPID: ", 1);
	ft_putnbr_fd(global_server()->pid, 1);
	ft_putstr_fd("\n", 1);
}
