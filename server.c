/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:08:26 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/12 02:21:51 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf("Hello from MiniTalk! :)\n");

#include "includes/minitalk.h"

char	*str_join_n(char *s1, char *s2, size_t n)
{
	char	*str;
	ssize_t	tmp_len1;
	size_t	len1;
	size_t	i;

	tmp_len1 = ft_strlen(s1);
	len1 = tmp_len1;
	if (tmp_len1 == -1)
		len1 = 0;
	str = malloc(len1 + n + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < n)
		str[len1 + i] = s2[i];
	str[len1 + n] = '\0';
	return (free(s1), str);
}

void	handle_signals(int sig, t_server *server)
{
	server->curr_char <<= 1;
	if (sig == SIGUSR1)
		server->curr_char |= 1;
	server->curr_bit++;
	if (server->curr_bit >= CHAR_BITS)
	{
		if (!server->curr_char)
		{
			server->msg = str_join_n(server->msg, "", 0);
			if (server->msg)
			{
				if (ft_putstr_fd(server->msg, 1) < 0)
					ft_error("Error printing message");
				free(server->msg);
				server->msg = NULL;
			}
		}
		else
			server->msg = str_join_n(server->msg,
					(char *)&server->curr_char, 1);
		server->curr_bit = 0;
		server->curr_char = 0;
	}
}

void	signal_handler(int sig, siginfo_t *info)
{
	static t_server	server;

	if (sig != SIGUSR1 && sig != SIGUSR2)
		return ;
	handle_signals(sig, &server);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	if (ft_putstr_fd("Server started.\nPID: ", 1) < 0
		|| ft_putnbr_fd(getpid(), 1) < 0
		|| ft_putstr_fd("\n", 1) < 0)
		return (ft_error("Initialization failure"), 1);
	sa.sa_sigaction = (void *)signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
