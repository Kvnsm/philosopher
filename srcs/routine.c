/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:37:46 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 18:24:03 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	manger(t_philo_stuff *philo)
{
	philo->last_meal = get_time();
	philo->limit_time = philo->last_meal + philo->details->time_to_die;
	display_messages(philo, 1);
	usleep(philo->details->time_to_eat * 1000);
}

void	dormir(t_philo_stuff *philo)
{
	display_messages(philo, 2);
	usleep(philo->details->time_to_sleep * 1000);
}
void	*philosophe(void *arg)
{
	t_philo_stuff	*copy;
	
	copy = arg;
	copy->limit_time = copy->last_meal + copy->details->time_to_die;

	while (1)
	{
		pthread_mutex_lock(&copy->details->forks[copy->lfork]);
		display_messages(copy, 3);
		pthread_mutex_lock(&copy->details->forks[copy->rfork]);
		display_messages(copy, 3);



		manger(copy);

		
		pthread_mutex_unlock(&copy->details->forks[copy->lfork]);
		pthread_mutex_unlock(&copy->details->forks[copy->rfork]);

		dormir(copy);

		display_messages(copy, 4);
	}
	return (0);
}