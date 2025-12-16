/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:20 by rcompain          #+#    #+#             */
/*   Updated: 2025/12/16 16:55:31 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

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
	NBR_CHUNK = 3
}	t_utils;

/* --------------------------------- MOVES --------------------------------- */

/* move_push.c */
char	*sa(t_stack *a, t_stack *b);
char	*pa(t_stack *a, t_stack *b);
char	*pb(t_stack *a, t_stack *b);

/* move_rotate.c */
char	*ra(t_stack *a, t_stack *b);
char	*rb(t_stack *b, t_stack *a);
void	rr(t_stack *a, t_stack *b);

/* move_reverse_rotate.c */
char	*rra(t_stack *a, t_stack *b);
char	*rrb(t_stack *b, t_stack *a);
void	rrr(t_stack *a, t_stack *b);

/* ------------------------------- PARSING --------------------------------- */

/* parsing.c */
t_stack	*parsing(int ac, char **av);

/* -------------------------------- ALGO ----------------------------------- */

/* sort.c */
t_list	*algo_sort(t_stack *map, t_stack *b, int flag);
int		push_best_to_a(t_stack *map, t_stack *b, t_list **lst, int flag);

/* tiny_sort.c */
int		tiny_sort(t_stack *map, t_stack *b, t_list **lst);

/* sort_best_index.c */
int		*check_best_index(t_stack *map, t_stack *b);

/* opti_lst.c */
void	opti(t_list **lst);

/* -------------------------------- UTILS ---------------------------------- */

/* utils.c */
void	mapping(t_stack *a, t_stack *map);
int		new_cmd(t_list **lst, t_stack *stack1, t_stack *stack2,
			char *(*cmd)(t_stack *, t_stack *));
int		stack_sorted(t_stack *stack);

/* parsing_utils.c */
int		empty_str(char *str);
int		already_exit(t_stack *a, int nbr);

/* opti_lst_utils.c */
int		*count_rr_or_rrr(t_list *curent, char *str1, char *str2, int size);
void	put_space(t_list *curent, int i);

/* ------------------------------- MEMORY ---------------------------------- */

/* memory.c */
t_stack	*init_stack(int ac, size_t size);
void	free_stack(t_stack *a, t_stack *b, t_stack *map);
void	free_str(char **str);

#endif
