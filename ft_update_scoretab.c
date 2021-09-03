/*****************************************************************************/
/*                                                                           */
/*  yams ft_update_scoretab.c                                                */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_sum(int *val, int start, int end)
{
	int sum;

	sum = 0;
	for (int i = start; i < end; i++)
		sum += val[i];
	val[end] = sum;
}

void	ft_up_rank(int *rank, int x)
{
	if (x >= 36 && x <= 40)
		rank[x + 1] = 0;
	if (x == 41)
		rank[45] = 0;
	if (x >= 45 && x <= 50)
		rank[x + 1] = 0;
}

void	ft_check_bonus(int *values)
{
	int	tab[3] = {6, 24, 42};

	for (int i = 0; i < 3; i++)
	{
		if (values[tab[i]] >= 60 && values[tab[i]] <= 69)
			values[tab[i] + 1] = 20;
		else if (values[tab[i]] >= 70)
			values[tab[i] + 1] = 30;
		else
			values[tab[i] + 1] = 0;
	}
}

void	ft_init_line(int *rank, int start, int end, int a)
{
	for (int k = start; k < end; k++)
		for (int i = 0; i < 3; i++)
			rank[k + i * 18] = a;
}

void	ft_init_scoreboard(int *values, int *rank)
{
	for (int i = 0; i < 55; i++)
		values[i] = 0;
	ft_init_line(rank, 0, 6, 0);
	ft_init_line(rank, 6, 9, -1);
	ft_init_line(rank, 9, 16, 0);
	ft_init_line(rank, 16, 18, -1);
	for (int k = 37; k < 53; k++)
		rank[k] = -2; ////////////// tmp 17:51 03/09
}

void	ft_up_turn(int *val, int *sol, int *rank, int x, int mode, int turn)
{
	val[x] = sol[x];
	rank[x] = turn;
	ft_up_rank(rank, x);
	ft_sum(val, 0, 6);
	ft_sum(val, 18, 24);
	ft_sum(val, 36, 42);
	ft_check_bonus(val);
	ft_sum(val, 6, 8);
	ft_sum(val, 24, 26);
	ft_sum(val, 42, 44);
	ft_sum(val, 9, 16);
	ft_sum(val, 27, 34);
	ft_sum(val, 45, 52);
	val[17] = val[8] + val[16];
	val[35] = val[26] + val[34];
	val[53] = val[44] + val[52];
	ft_show_choice(mode, val, rank, x);
}

void	ft_show_choice(int mode, int *values, int *rank, int x)
{
	if (mode > 1)
		ft_display_scoretab(values, rank, rank[x]);
}
