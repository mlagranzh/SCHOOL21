/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:18:11 by celys             #+#    #+#             */
/*   Updated: 2021/10/17 18:18:13 by celys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>

typedef struct argc
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	my_mutex;
	pthread_mutex_t	mutex_write;
	pthread_t		*threads;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_times;
	int				*available_mutex;
}	t_args;

typedef struct s_current
{
	long	start_time;
	long	last_eat;
	int		current;
	int		time;
	int		left_fork;
	int		right_fork;
	t_args	*args;
}				t_current;

long int	my_atoi(char *str);
int			my_isdigit(char *string);
int			parse_error(int argc, char **argv);
int			ft_atoi(char *str);
long		get_time(void);
int			min(int a, int b);
int			max(int a, int b);

void		*imitation(void *args);
void		take_fork(t_current *philo);
void		eating(t_current *philo);
void		sleeping(t_current *philo);

#endif
