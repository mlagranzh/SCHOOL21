/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imitation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:16:21 by celys             #+#    #+#             */
/*   Updated: 2021/10/17 18:16:26 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	g_alive = 1;

void	write_message(t_current *philo, char *string)
{
	int	i;

	pthread_mutex_lock(&philo -> args -> mutex_write);
	if (g_alive == 1)
	{
		philo -> time += get_time() - philo -> start_time;
		printf("%d %d %s\n", philo -> time, philo -> current, string);
		philo -> start_time = get_time();
	}
	if (string[0] == 'd')
	{
		g_alive = 0;
		i = 0;
		while (i < philo -> args -> nb_philo)
		{
			pthread_mutex_unlock(&philo -> args -> mutex[i]);
			i++;
		}
	}
	pthread_mutex_unlock(&philo -> args -> mutex_write);
}

void	take_fork(t_current *philo)
{
	while (philo -> args -> available_mutex[philo -> left_fork] == 0)
	{
		usleep(100);
		if (philo -> time + get_time() - philo -> start_time - \
				philo -> last_eat > philo -> args -> time_to_die)
			return (write_message(philo, "died"));
		if (g_alive == 0)
			return ;
	}
	write_message(philo, "has taken a fork");
	pthread_mutex_lock(&(philo -> args ->mutex[philo -> left_fork]));
	philo -> args -> available_mutex[philo -> left_fork] = 0;
	while (philo -> args -> available_mutex[philo -> right_fork] == 0)
	{
		usleep(100);
		if (philo -> time + get_time() - philo -> start_time - \
				philo -> last_eat > philo -> args -> time_to_die)
			return (write_message(philo, "died"));
		if (g_alive == 0)
			return ;
	}
	write_message(philo, "has taken a fork");
	pthread_mutex_lock(&(philo -> args -> mutex[philo -> right_fork]));
	philo -> args -> available_mutex[philo -> right_fork] = 0;
}

void	eating(t_current *philo)
{
	philo -> start_time = get_time();
	take_fork(philo);
	philo -> last_eat = philo -> time;
	write_message(philo, "is eating");
	while (get_time() - philo -> start_time < philo -> args -> time_to_eat)
	{
		if (g_alive == 0)
			return ;
		usleep(100);
		if (philo -> time + get_time() - philo -> start_time - \
				philo -> last_eat > philo -> args -> time_to_die)
			return (write_message(philo, "died"));
	}
	pthread_mutex_unlock(&(philo -> args ->mutex[philo -> right_fork]));
	philo -> args -> available_mutex[philo -> right_fork] = 1;
	pthread_mutex_unlock(&(philo -> args -> mutex[philo -> left_fork]));
	philo -> args -> available_mutex[philo -> left_fork] = 1;
}

void	sleeping(t_current	*philo)
{
	write_message(philo, "is sleeping");
	while (get_time() - philo -> start_time < philo -> args -> time_to_sleep)
	{
		if (g_alive == 0)
			return ;
		usleep(100);
		if (philo -> time + get_time() - philo -> start_time - \
			philo -> last_eat > philo -> args -> time_to_die)
			return (write_message(philo, "died"));
	}
	write_message(philo, "is thinking");
}

void	*imitation(void *args)
{
	t_current	*philo;
	int			i;

	i = 0;
	philo = ((t_current *)(args));
	while (i++ < philo -> args -> nb_of_times && g_alive == 1)
	{
		if (g_alive == 0)
			return (NULL);
		eating(philo);
		if (g_alive == 0)
			return (NULL);
		sleeping(philo);
		if (g_alive == 0)
			return (NULL);
	}
	return (NULL);
}
