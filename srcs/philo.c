/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:28 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 10:42:59 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_details	data;
	int			ret;

	if (argc < 5 || argc > 6)
		return (printf("Error: wrong argument number\n"));
	ret = philo_arg_parser(&data, argv, argc);
	if (ret)
		return (error_messages(ret));
	ret = thread_spawn(&data);
	if (ret)
		return (error_messages(ret));
	return (0);
}
