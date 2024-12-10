/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:27:46 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/10 21:35:53 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 3)
		return (ft_error(C_I_ARGS), 1);
	ft_putstr_fd("Hello from client. :)\n", 1);
}
