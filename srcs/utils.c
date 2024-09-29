/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:08:37 by yilim             #+#    #+#             */
/*   Updated: 2024/09/25 18:08:37 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int argc, char **argv, t_stack *s)
{
	int	i;

	i = 0;
	s->a_size = 0;
	s->b_size = 0;
	while (--argc)
	{
		if (ft_size(argv[i + 1], ' '))
			s->a_size += ft_size(argv[i + 1], ' ');
		else
			s->a_size++;
		i++;
	}
	s->a = malloc(s->a_size * sizeof * s->a);
	if (s->a == NULL)
		ft_exit(s, "Error");
	s->b = malloc(s->a_size * sizeof * s->b);
	if (s->b == NULL)
		ft_exit(s, "Error");
}

static int	parse_num(const char *n, t_stack *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if ((n[i] == '+' || n[i] == '-'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			ft_exit(s, "Error");
		if (!(n[i] >= '0' && n[i] <= '9'))
			ft_exit(s, "Error");
		res = res * 10 + (n[i++] - '0');
	}
	return ((int)(res * sign));
}

void	parsing(t_stack *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->joined, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		s->a[z++] = parse_num(tmp[i++], s);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	exit_sorted_duplicate(t_stack *s, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < s->a_size)
		{
			j = i + 1;
			while (j < s->a_size)
			{
				if (s->a[i] == s->a[j])
					ft_exit(s, "Error");
				j++;
			}
			i++;
		}
	}
	if (check_sorted(s))
		ft_exit(s, NULL);
}

void	init_index(t_stack *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->a_size * sizeof * new_a);
	if (new_a == NULL)
		ft_exit(s, "Error");
	i = -1;
	while (++i < s->a_size)
	{
		k = 0;
		j = -1;
		while (++j < s->a_size)
			if (s->a[i] > s->a[j])
				k++;
		new_a[i] = k;
	}
	i = s->a_size;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}
