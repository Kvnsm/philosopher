/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:27:39 by ksam              #+#    #+#             */
/*   Updated: 2021/07/14 20:42:12 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

#define NB_PHILO 5

typedef struct	s_philo_stuff
{
	int				id;
	struct s_master	*box;
	
}				t_philo_stuff;

typedef struct	s_master
{
	t_philo_stuff	*philos;
	pthread_mutex_t	forks[NB_PHILO];

}				t_master;

void	manger(int id)
{
	printf("Philosophe [%d] mange\n", id);
	sleep(2);
}

void	*philosophe(void *arg)
{
	t_philo_stuff	*copy;
	t_master		*box;
	int				left;
	int				right;

	copy = arg;
	box = copy->box;
	left = copy->id;
	right = (left + 1) % NB_PHILO;
	
	while (1)
	{
		printf("Philosophe [%d] pense \n", box->philos[copy->id].id + 1);
		pthread_mutex_lock(&box->forks[left]);
		pthread_mutex_lock(&box->forks[right]);
		manger(box->philos[copy->id].id + 1);
		pthread_mutex_unlock(&box->forks[left]);
		pthread_mutex_unlock(&box->forks[right]);
	}
	return (NULL);
}

int main()
{
	t_master		box;
	int				i;
	pthread_t		th[NB_PHILO];

	i = 0;
	box.philos = malloc(sizeof(*(box.philos)) * NB_PHILO);
	if (box.philos == NULL)
		return (-1);
		
	while (i < NB_PHILO)
	{
		box.philos[i].id = i;
		box.philos[i].box = &box;
		pthread_mutex_init(&box.forks[i], NULL);
		if (pthread_create(&th[i], NULL, &philosophe, &box.philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	return (0);
}