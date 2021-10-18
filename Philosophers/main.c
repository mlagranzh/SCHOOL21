/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:17:03 by celys             #+#    #+#             */
/*   Updated: 2021/10/17 18:17:04 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_thread(t_current *philo, t_args *args)
{
	int	i;
	int	count_philo;

	count_philo = args ->nb_philo;
	i = -1;
	if (args ->nb_philo % 2 == 1)
		count_philo -= 1;
	while (++i < count_philo)
		if (i % 2 == 0)
			pthread_create(&args -> threads[i], NULL, imitation, &philo[i]);
	usleep(100);
	i = -1;
	while (++i < count_philo)
		if (i % 2 == 1)
			pthread_create(&args -> threads[i], NULL, imitation, &philo[i]);
	if (args -> nb_philo % 2 == 1)
	{
		usleep(100);
		pthread_create(&args->threads[count_philo], NULL, \
						imitation, &philo[count_philo]);
	}
	i = -1;
	while (++i < args -> nb_philo)
		pthread_join(args -> threads[i], NULL);
}

void	philo(t_args *args)
{
	int				i;
	t_current		*philo;

	args -> threads = malloc(sizeof(pthread_t) * args -> nb_philo);
	args -> mutex = malloc(args -> nb_philo * sizeof(pthread_mutex_t));
	args -> available_mutex = malloc(args -> nb_philo * sizeof(int));
	philo = malloc(args -> nb_philo * sizeof(t_current));
	i = 0;
	while (i < args ->nb_philo)
	{
		args -> available_mutex[i] = 1;
		philo[i].last_eat = 0;
		philo[i].time = 0;
		philo[i].current = i + 1;
		philo[i].args = args;
		philo[i].left_fork = min(i, (i + 1) % args -> nb_philo);
		philo[i].right_fork = max(i, (i + 1) % args -> nb_philo);
		pthread_mutex_init(&args -> mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&args -> mutex_write, NULL);
	create_thread(philo, args);
	free(philo);
}

void	free_all(t_args *args)
{
	int	i;

	i = 0;
	while (i < args -> nb_philo)
	{
		pthread_mutex_destroy(&args -> mutex[i]);
		pthread_detach(args -> threads[i]);
		i++;
	}
	free(args -> threads);
	free(args -> mutex);
	free(args -> available_mutex);
}

int	main(int argc,	char **argv)
{
	t_args	args;

	if (parse_error(argc, argv))
		return (1);
	args.nb_philo = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	args.nb_of_times = INT_MAX;
	if (argc == 6)
		args.nb_of_times = ft_atoi(argv[5]);
	philo(&args);
	free_all(&args);
	return (0);
}
