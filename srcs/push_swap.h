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

// utils.c
void	init_stacks(int argc, char **argv, t_stack *s);

#endif
