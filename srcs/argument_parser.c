/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:36:50 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 19:08:13 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		philo_arg_checker(char **argv)
{
	int i;
	int j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (!(ft_isdigit(argv[j][i])))
				return(1);
			i++;
		}
		j++;
	}
	return (0);
}

int		philo_arg_parser(t_details *data, char **argv, int argc)
{
	memset(data, -1, sizeof(*data));
	if (philo_arg_checker(argv))
		return (1);
	data->nb_philo = ft_atoi(argv[1]);
	if (data->nb_philo == 0)
		return(4);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_counter = ft_atoi(argv[5]);
	data->philo_full_counter = 0;
	// Protection si il existe qu'un seul philo ? 1 fourchette ?

	// data->forks = NULL; // ???
	
	data->philos = NULL;
	data->philos = malloc(sizeof(*(data->philos)) * data->nb_philo);
	if (data->philos == NULL)
		return (2);
	init_philo(data);
	return (init_mutexes(data));
}