/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_m.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 07:40:26 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 07:45:19 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	mutex_forks(t_philo_stuff *copy)
{
	pthread_mutex_lock(&copy->details->forks[copy->lfork]);
	display_messages(copy, 3);
	pthread_mutex_lock(&copy->details->forks[copy->rfork]);
	display_messages(copy, 3);
}

void	unmutex_forks(t_philo_stuff *copy)
{
	pthread_mutex_unlock(&copy->details->forks[copy->lfork]);
	pthread_mutex_unlock(&copy->details->forks[copy->rfork]);
}
