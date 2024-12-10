/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:11:35 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/10 21:32:19 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>

# ifndef C_I_ARGS
#  define C_I_ARGS "Invalid Arguments\nUsage: client [PID] [message]"
# endif

typedef struct s_server
{
	int	pid;
}	t_server;

#endif