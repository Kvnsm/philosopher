/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:28 by ksam              #+#    #+#             */
/*   Updated: 2021/07/15 02:29:31 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_details	data;
	pthread_t	*th;
	int			i;
	int			ret;

	i = 0;
	
	if (argc < 5 || argc > 6)
		return(printf("Error: wrong argument number\n"));
	
	ret = philo_arg_parser(&data, argv, argc);
	if (ret)
		return(error_messages(ret));
	



	
	th = malloc(sizeof(th) * data.nb_philo);
	if (th == NULL)
		return (error_malloc());
	
	while (i < data.nb_philo)
	{
		if (pthread_create(&th[i], NULL, &philosophe, &data.philos[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_join(th[i], NULL);
		pthread_mutex_destroy(&data.forks[i]);
		i++;
	}
	free(th);
	free(data.philos);
	return (0);
}