/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:37:46 by ksam              #+#    #+#             */
/*   Updated: 2021/07/16 17:21:11 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	manger(t_philo_stuff *philo)
{
	philo->last_meal = get_time();
	philo->limit_time = philo->last_meal + philo->details->time_to_die;
	// printf("Philosophe [%d] is eating\n", philo->id + 1);
	display_messages(philo, 1);
	usleep(philo->details->time_to_eat * 1000);
}

void	dormir(t_philo_stuff *philo)
{
	printf("Philosophe [%d] is sleeping\n", philo->id + 1);
	usleep(philo->details->time_to_sleep * 1000);
}
void	*philosophe(void *arg)
{
	t_philo_stuff	*copy;
	
	copy = arg;
	copy->limit_time = copy->last_meal + copy->details->time_to_die;

	while (1)
	{
		if (get_time() > copy->limit_time)
		{
			long test;
			test = get_time() - copy->details->start_timer;
			printf("%ld \t [%d] have to die now ! \n", test, copy->id + 1);
			copy->details->die = 1;
			break;
		}
		if (copy->details->nb_philo != 1)
		{
			pthread_mutex_lock(&copy->details->forks[copy->lfork]);
			printf("Philosophe [%d] has taken a Lfork\n", copy->id + 1);
			pthread_mutex_lock(&copy->details->forks[copy->rfork]);
			printf("Philosophe [%d] has taken a Rfork\n", copy->id + 1);
			

			manger(copy);

			
			pthread_mutex_unlock(&copy->details->forks[copy->lfork]);
			pthread_mutex_unlock(&copy->details->forks[copy->rfork]);

			dormir(copy);
			printf("Philosophe [%d] is thinking\n", copy->id + 1);
		}
	}
	return (0);
}