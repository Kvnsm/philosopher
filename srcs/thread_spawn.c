/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:02:47 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 03:09:04 by ksam             ###   ########lyon.fr   */
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
	while (i < data->nb_philo)
	{
		if (pthread_create(&th[i], NULL, &philosophe, &data->philos[i]) != 0)
			return (3);
		usleep(50);
		i++;
	}

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(th[i], NULL);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(th);
	return (0);
}