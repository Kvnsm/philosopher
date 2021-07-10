/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:36:50 by ksam              #+#    #+#             */
/*   Updated: 2021/07/10 14:45:21 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		philo_arg_checker(char **argv)
{
	int i = 0;
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
			return(1);
		i++;
	}
	return (0);
}