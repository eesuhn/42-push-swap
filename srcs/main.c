/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:22:39 by yilim             #+#    #+#             */
/*   Updated: 2024/09/24 13:22:39 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stack *s, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (s != NULL)
	{
		if (s->a != NULL)
			free(s->a);
		if (s->b != NULL)
			free(s->b);
		if (s->joined != NULL)
			free(s->joined);
		if (s != NULL)
			free(s);
	}
	exit(1);
}

static void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		ft_exit(NULL, "");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			ft_exit(NULL, "Error");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				ft_exit(NULL, "Error");
			j++;
		}
	}
}

static void	join_args(int argc, char **argv, t_stack *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->joined = ft_strdup(tmp);
	if (s->joined == NULL)
		ft_exit(s, "Error");
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_stack	*s;

	check_args(argc, argv);
	s = malloc(sizeof * s);
	if (s == NULL)
		exit(1);
	init_stacks(argc, argv, s);
	join_args(argc, argv, s);
	return (0);
}
