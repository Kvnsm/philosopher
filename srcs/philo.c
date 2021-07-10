/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:39:28 by ksam              #+#    #+#             */
/*   Updated: 2021/07/10 13:53:45 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_details	data;
	
	if (argc < 5 || argc > 6)
		return(printf("Error: wrong argument number\n"));

	memset(&data, -1, sizeof(data));
	
	int i = 0;
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
			return(error_argument());
		i++;
	}
	data.nb_philo = ft_atoi(argv[1]);
	printf("Je suis nb philo: %d", data.nb_philo);
	return (0);
}