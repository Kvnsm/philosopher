/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:37:46 by ksam              #+#    #+#             */
/*   Updated: 2021/07/17 07:45:33 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosophe(void *arg)
{
	t_philo_stuff	*copy;

	copy = arg;
	copy->limit_time = copy->last_meal + copy->details->time_to_die;
	while (1)
	{
		mutex_forks(copy);
		manger(copy);
		unmutex_forks(copy);
		if (copy->eat_counter == copy->details->must_eat_counter)
		{
			copy->details->philo_full_counter++;
			break ;
		}
		dormir(copy);
		display_messages(copy, 4);
	}
	return (0);
}
