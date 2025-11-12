/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:20 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/12 15:31:56 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

int		main(int ac, char **av);

/* --------------------------------- STRUCT -------------------------------- */

typedef struct s_stack
{
	int		*tab;
}	t_stack;

/* --------------------------------- RULES --------------------------------- */

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

#endif // !DEBUG
