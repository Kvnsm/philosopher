/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:02:47 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 17:32:34 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		thread_spawn(t_details *data)
{
	pthread_t	*th;
	int			i;

	i = 0;
	th = malloc(sizeof(th) * data->nb_philo);
	if (th == NULL)
		return (2);
	data->start_timer = get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&th[i], NULL, &philosophe, &data->philos[i]) != 0)
			return (3);
		// detach threads
		usleep(100);
		i++;
	}

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(th[i], NULL);
		// check philo si il est mort
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(th);
	free(data->forks);
	return (0);
}