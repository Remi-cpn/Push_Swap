/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:20 by rcompain          #+#    #+#             */
/*   Updated: 2025/11/28 13:56:20 by rcompain         ###   ########.fr       */
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
	size_t	size;
}	t_stack;

typedef struct s_bit
{
	int	max;
	int	index;
}	t_bit;

/* --------------------------------- RULES --------------------------------- */

/* swap_push_utils */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
char	*pa(t_stack *a, t_stack *b);
char	*pb(t_stack *a, t_stack *b);

/* rotate_utils */
char	*ra(t_stack *a);
char	*rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* reverse_rotate_utils */
char	*rra(t_stack *a);
char	*rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* ------------------------------- PARSING --------------------------------- */

t_stack	*parsing(int ac, char **av);

/* -------------------------------- ALGO ----------------------------------- */

t_list	*algo(t_stack *map, t_stack *b);
int		pos_in_a(t_stack *map, int value);
int		*check_best_index(t_stack *map, t_stack *b);

/* -------------------------------- UTILS ---------------------------------- */

void	mapping(t_stack *a, t_stack *map);
char	*strjoin_wish(char *s1, char *s2);
int		bit_max(size_t index_max);
char	*replace(char *sec, char *bad1, char *bad2);

/* ------------------------------- MEMORY ---------------------------------- */

t_stack	*init_stack(int ac, size_t size);
t_bit	*init_bit(int bit_max, int bit);
void	free_stack(t_stack *a, t_stack *b, t_stack *map);
void	free_tab_str(char **str);

/* ---------------------------- OPTIMISATION ------------------------------ */

void	opti(t_list **lst);

/* -------------------------------- TEST ---------------------------------- */

void	print_stack(t_stack *a, t_stack *b);

#endif // !DEBUG
