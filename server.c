/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:08:26 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/11 13:11:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf("Hello from MiniTalk! :)\n");

#include "includes/minitalk.h"

int	init(void)
{
	if (ft_putstr_fd("Server started.\nPID: ", 1) < 0
		|| ft_putnbr_fd(getpid(), 1) < 0
		|| ft_putstr_fd("\n", 1) < 0)
		return (0);
	return (1);
}

void	handle_signals_with_client(int sig, t_server *server)
{
	unsigned char	c;

	server->curr_char <<= 1;
	if (sig == SIGUSR1)
		server->curr_char |= 1;
	server->curr_bit++;
	if (server->curr_bit == CHAR_BITS)
	{
		c = (unsigned char)server->curr_char;
		if (!(unsigned char)server->curr_char)
		{
			c = '\n';
			server->has_client = 0;
		}
		write(1, &c, 1);
		server->curr_bit = 0;
		server->curr_char = 0;
	}
	kill(server->client_pid, SIGUSR1);
}

void	handle_signals_without_client(int sig, t_server *server)
{
	server->curr_char <<= 1;
	if (sig == SIGUSR1)
		server->curr_char |= 1;
	server->curr_bit++;
	if (server->curr_bit == INT_BITS)
	{
		server->client_pid = (int)server->curr_char;
		server->curr_char = 0;
		server->curr_bit = 0;
		server->has_client = 1;
	}
}

void	signal_handler(int sig)
{
	static t_server	server;

	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	if (!server.has_client)
		server.client_pid = -1;
	if (server.client_pid == -1)
		handle_signals_without_client(sig, &server);
	else
		handle_signals_with_client(sig, &server);
}

int	main(void)
{
	struct sigaction	sa;

	if (!init())
		return (ft_error("Initialization failure"), 1);
	sa.sa_handler = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
