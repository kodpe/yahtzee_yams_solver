/*****************************************************************************/
/*                                                                           */
/*  yams ft_math.c                                                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

/*
 *	MEANS FUNCTIONS
 */
void	ft_add_mean(long double *dest, int *src, int x, int size)
{
	dest[x] = ((dest[x] * (size- 1)) + src[x]) / size;
}

void	ft_add_x_mean(long double *dest, int *src, int size, int len)
{
	for (int x = 0; x < len; x++)
		ft_add_mean(dest, src, x, size);
}
/*
int	ft_mean(int *array, int size)
{
	int	sum;
	
	sum = 0;
	for (int i = 0; i < size; i++)	
		sum += array[i];
	return (sum / size);
}
*/

/*
 *	SORT & SWAP FUNCTIONS
 */
void	ft_swap(int *a, int *b) 
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_tab(int *tab, int size)
{
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
		}
	}
}

/*
 * RANDOMIZE FUNCTIONS
 */
void	ft_roll(int *dice)
{
		*dice = rand() % 6 + 1; 
}

void	ft_rool_zero(int *dices)
{
	for (int i = 0; i < 5; i++)
		if (dices[i] == 0)
			ft_roll(&dices[i]); 
	ft_sort_tab(dices, 5);
}

/*
void	ft_roll_five(int *dices)
{
	for (int i = 0; i < 5; i++)
		ft_roll(&dices[i]); 
	ft_sort_tab(dices, 5);
}

void	ft_roll_rand(int *dices)
{
	for (int i = 0; i < 5; i++)
		if (rand() % 2 == 0)
			ft_roll(&dices[i]); 
	ft_sort_tab(dices, 5);
}

void	ft_random_fill(int *values, int *rank, int len, int range)
{
	for (int i = 0; i < len; i++)
	{
		if (rank[i] == 0)
			values[i] = rand() % range; 
	}
}
*/
