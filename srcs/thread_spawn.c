/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_spawn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 02:02:47 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 10:47:09 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_pthreads(pthread_t *th, t_details *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&th[i], NULL, &philosophe, &data->philos[i]) != 0)
			return (3);
		pthread_detach(th[i]);
		usleep(100);
		i++;
	}
	return (0);
}

void	check_philo_alive(t_details *data)
{
	int	i;

	i = 0;
	while (data->nb_philo != data->philo_full_counter)
	{
		if (data->must_eat_counter != data->philos[i].eat_counter && \
							get_time() > data->philos[i].limit_time)
		{
			display_messages(&data->philos[i], 5);
			break ;
		}
		i = (i + 1) % data->nb_philo;
	}
}

int	thread_spawn(t_details *data)
{
	pthread_t	*th;
	int			ret;

	th = malloc(sizeof(pthread_t) * data->nb_philo);
	if (th == NULL)
		return (2);
	data->start_timer = get_time();
	ret = start_pthreads(th, data);
	if (ret)
	{
		clean_all(data, th);
		return (ret);
	}
	check_philo_alive(data);
	clean_all(data, th);
	return (0);
}
