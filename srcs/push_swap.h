/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilim <yilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:37:02 by yilim             #+#    #+#             */
/*   Updated: 2024/09/24 13:37:02 by yilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*joined;
}	t_stack;

// main.c
void	ft_exit(t_stack *s, char *msg);

// move.c
void	swap(char *str, int *arr, int size);
void	push(char *str, t_stack *s);
void	rotate(int *arr, int size, char *dir, char *list);

// sort.c
int		check_sorted(t_stack *s);
void	sort_three(t_stack *s);
void	sort_four_five(t_stack *s);
void	radix_sort(t_stack *s);

// utils.c
void	init_stacks(int argc, char **argv, t_stack *s);
void	parsing(t_stack *s);
void	exit_sorted_duplicate(t_stack *s, int i);
void	init_index(t_stack *s);

#endif
