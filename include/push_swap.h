/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:20 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/08 19:56:00 by rcompain         ###   ########.fr       */
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

typedef struct s_index
{
	int	*curent;
	int	*best;
}	t_index;

typedef struct s_cost
{
	int	ra_rb;
	int	rra_rrb;
	int	ra_rrb;
	int	rra_rb;
	int	*best;
}	t_cost;

/* --------------------------------- ENUM --------------------------------- */

typedef enum e_move_type
{
	RA_RB = 1,
	RRA_RRB,
	RA_RRB,
	RRA_RB
}	t_move_type;

typedef enum e_utils
{
	ERROR = -1,
	FALSE = 0,
	TRUE = 1,
	NBR_CHUNK = 4
}	t_utils;

/* --------------------------------- RULES --------------------------------- */

/* move_push */
char	*pa(t_stack *a, t_stack *b);
char	*pb(t_stack *a, t_stack *b);

/* move_rotate */
char	*ra(t_stack *a, t_stack *b);
char	*rb(t_stack *b, t_stack *a);
void	rr(t_stack *a, t_stack *b);

/* move_reverse_rotate */
char	*rra(t_stack *a, t_stack *b);
char	*rrb(t_stack *b, t_stack *a);
void	rrr(t_stack *a, t_stack *b);

/* ------------------------------- PARSING --------------------------------- */

t_stack	*parsing(int ac, char **av);
int		empty_str(char *str);
int		already_exit(t_stack *a, int nbr);

/* -------------------------------- ALGO ----------------------------------- */

t_list	*algo_sort(t_stack *map, t_stack *b, int flag);
int		*check_best_index(t_stack *map, t_stack *b);
void	opti(t_list **lst);

/* -------------------------------- UTILS ---------------------------------- */

void	mapping(t_stack *a, t_stack *map);
int		*count_rr_or_rrr(t_list *curent, char *str1, char *str2, int size);
void	put_space(t_list *curent, int i);

/* ------------------------------- MEMORY ---------------------------------- */

t_stack	*init_stack(int ac, size_t size);
void	free_stack(t_stack *a, t_stack *b, t_stack *map);
void	free_str(char **str);

#endif
