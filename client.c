/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:27:46 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/11 13:11:58 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

t_client	*global_client(void)
{
	static t_client	client;

	return (&client);
}

t_client_args	*parse_args(int argc, char **argv)
{
	static t_client_args	args;
	long					pid;

	if (argc != 3)
		return (NULL);
	pid = ft_strtoi(argv[1]);
	if (pid == LONG_MAX)
		return (NULL);
	args.pid = pid;
	args.msg = argv[2];
	args.waiting = 0;
	return (&args);
}

void	send_bits(unsigned int n, int bit_len, int pid, int wait)
{
	while (bit_len--)
	{
		global_client()->waiting = wait;
		if ((n >> bit_len) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!wait)
			usleep(1000);
		while (global_client()->waiting)
			;
	}
}

void	nothing(int sig)
{
	if (sig == SIGUSR1)
		global_client()->waiting = 0;
}

int	main(int argc, char **argv)
{
	t_client_args		*args;
	int					my_pid;

	args = parse_args(argc, argv);
	if (!args)
		return (ft_error(C_I_ARGS), 1);
	my_pid = getpid();
	signal(SIGUSR1, nothing);
	send_bits(my_pid, INT_BITS, args->pid, 0);
	while (*args->msg)
		send_bits(*args->msg++, CHAR_BITS, args->pid, 1);
	send_bits('\0', CHAR_BITS, args->pid, 1);
	ft_putstr_fd("Message sent.\n", 1);
}
