/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:27:39 by ksam              #+#    #+#             */
/*   Updated: 2021/07/11 21:57:04 by ksam             ###   ########lyon.fr   */
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
	int			*id;
	int			j;
	
}				t_philo_stuff;

void	*routine(void *arg)
{
	t_philo_stuff *copy;

	// usleep(1000);
	copy = arg;
	printf("Philosopher %d is created\n", copy->j);
}

int main()
{
	pthread_t		th[NB_PHILO];
	int 			i;
	t_philo_stuff 	stuff;

	memset(&stuff, 0, sizeof(stuff));

	stuff.id = malloc(sizeof(int) * NB_PHILO); // to free


	i = 0;
	while (i < NB_PHILO)
	{
		stuff.id[i] = i + 1;
		stuff.j = i + 1;
		if (pthread_create(&th[i], NULL, &routine, &stuff) != 0)
			return (1);
		i++;
	}

	i = 0;
	while (i < NB_PHILO)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}