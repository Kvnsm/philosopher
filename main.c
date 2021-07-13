/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 15:27:39 by ksam              #+#    #+#             */
/*   Updated: 2021/07/13 19:19:59 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>

#define NB_PHILO 5

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = s;
	while (i < n)
		str[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	stock;

	stock = count * size;
	if (!(tab = malloc(stock)))
		return (NULL);
	ft_bzero(tab, stock);
	return (tab);
}

typedef struct	s_philo_stuff
{
	int				id;
	struct s_master	*box;
	
}				t_philo_stuff;

typedef struct	s_master
{
	t_philo_stuff	*philos;
}				t_master;

void	*philosophe(void *arg)
{
	t_master	*copy;

	copy = arg;
	printf("Je suis un test %d\n", copy->philos->id);
}

int main()
{
	t_master	box;
	int			i;
	pthread_t	th[NB_PHILO];

	i = 0;
	box.philos = malloc(sizeof(*(box.philos)) * NB_PHILO);
	if (box.philos == NULL)
		return (-1);

	while (i < NB_PHILO);
	{
		box.philos[i].id = i;
		box.philos[i].box = &box;
		i++;
	}
	i = 0;
	while (i < NB_PHILO)
	{
		pthread_create(&th[i], NULL, &philosophe, &box);
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