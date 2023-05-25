#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_push_swap
{
	int	*stack_a;
	int	*stack_b;
	size_t	sizea;
	size_t	sizeb;
}	t_push_swap;

#endif