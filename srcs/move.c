/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:31:46 by yilim             #+#    #+#             */
/*   Updated: 2024/12/06 01:31:46 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *arr, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_stack *s)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->b_size <= 0)
			return ;
		tmp = s->b[0];
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->a_size);
		s->a[0] = tmp;
		s->b_size--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->b_size);
		s->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->a_size <= 0)
			return ;
		tmp = s->a[0];
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->b_size);
		s->b[0] = tmp;
		s->a_size--;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->a_size);
		s->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *arr, int size, char *dir, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(dir, "up", 5) == 0)
	{
		tmp = arr[0];
		ft_memmove(arr, arr + 1, sizeof(int) * (size - 1));
		arr[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(dir, "down", 5) == 0)
	{
		tmp = arr[size - 1];
		ft_memmove(arr + 1, arr, sizeof(int) * (size - 1));
		arr[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
