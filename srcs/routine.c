/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:37:46 by ksam              #+#    #+#             */
/*   Updated: 2021/07/14 21:01:45 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	manger(int id)
{
	printf("Philosophe [%d] is eating\n", id);
	// sleep(1);
}

void	*philosophe(void *arg)
{
	t_philo_stuff	*copy;
	t_details		*data;
	int				left;
	int				right;

	copy = arg;
	data = copy->details;
	left = copy->id;
	right = (left + 1) % data->nb_philo;

	while (1)
	{
		printf("Philosophe [%d] is thinking\n", data->philos[copy->id].id + 1);
		pthread_mutex_lock(&data->forks[left]);
		pthread_mutex_lock(&data->forks[right]);
		manger(data->philos[copy->id].id + 1);
		pthread_mutex_unlock(&data->forks[right]);
		pthread_mutex_unlock(&data->forks[right]);
		// dormir
	}
	return (NULL);
}