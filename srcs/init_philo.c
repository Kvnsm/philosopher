/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 02:12:24 by ksam              #+#    #+#             */
/*   Updated: 2021/07/15 02:26:30 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	init_philo(t_details *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].is_eating = 0;
		data->philos[i].id = i;
		data->philos[i].lfork = i;
		data->philos[i].rfork = (i + 1) % data->nb_philo;
		data->philos[i].eat_counter = 0;
		data->philos[i].details = data;
		i++;
	}
}

int		init_mutexes(t_details *data)
{
	int	i;

	data->forks = malloc(sizeof(*(data->forks)) * data->nb_philo);
	if (data->forks == NULL)
		return (2);
	i = 0;
	while (i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (0);
}