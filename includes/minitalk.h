/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:11:35 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/11 13:01:03 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

# ifndef C_I_ARGS
#  define C_I_ARGS "Invalid Arguments\nUsage: client [PID] [message]"
# endif

# ifndef INT_BITS
#  define INT_BITS 32
# endif

# ifndef CHAR_BITS
#  define CHAR_BITS 8
# endif

typedef struct s_server
{
	int				pid;
	unsigned int	curr_char;
	int				curr_bit;
	int				client_pid;
	int				has_client;
}	t_server;

typedef struct s_client
{
	int		waiting;
}	t_client;

typedef struct s_client_args
{
	int		pid;
	char	*msg;
	int		waiting;
}	t_client_args;

#endif