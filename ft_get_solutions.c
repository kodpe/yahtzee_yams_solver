/*****************************************************************************/
/*                                                                           */
/*  yams ft_get_solutions.c                                                  */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_init_solutions(int *rank, int *solutions, int jet)
{
	for (int i = 0; i < 54; i++)
	{
		if (rank[i] == 0)
			solutions[i] = 0; 
		else if (rank[i] == -2)
			solutions[i] = -2; 
		else
			solutions[i] = -1; 
	}
	if (jet > 1)
		for (int i = 18; i < 36; i++)
			solutions[i] = -1; 
}

void	ft_count_dices(int *dices, int *qds)
{
	int	sum;
	int	count;

	sum = 0;
	for (int n = 1; n <= 6; n++)
	{
		count = 0;
		for (int i = 0; i < 5; i++)
		{
			if (dices[i] == n)
			{
				count++;
				sum += n;
			}
		}
		qds[n] = count;
	}
	qds[0] = sum;
}

void	ft_sol_maxdices(int *qds, int *solutions)
{
	for (int n = 1; n <= 6; n++)
	{
		for (int i = 0; i <= 36; i += 18)
			if (solutions[i + n - 1] == 0)
				solutions[i + n - 1] = qds[n] * n;
	}
}

void	ft_sol_min(int *qds, int *solutions, int *values, int *rank)
{
	for (int i = 9; i <= 45; i += 18)
	{
		if (solutions[i] == 0 && rank[i + 1] <= 0)
			solutions[i] = qds[0];
		if (solutions[i] == 0 && rank[i + 1] > 0)
		{
			if (qds[0] < values[i + 1])
				solutions[i] = qds[0];
		}
	}
}

void	ft_sol_max(int *qds, int *solutions, int *values, int *rank)
{
	for (int i = 10; i <= 46; i += 18)
	{
		if (solutions[i] == 0 && rank[i - 1] <= 0)
			solutions[i] = qds[0];
		if (solutions[i] == 0 && rank[i - 1] > 0)
		{
			if (qds[0] > values[i - 1])
				solutions[i] = qds[0];
		}
	}
}

void	ft_sol_brelan(int *qds, int *solutions)
{
	for (int n = 1; n <= 6; n++)
		if (qds[n] >= 3)
		{
			for (int i = 11; i <= 47; i += 18)
				if (solutions[i] == 0)
					solutions[i] = 3 * n + 20;
		}
}

void	ft_sol_full(int *d, int *solutions)
{
	for (int i = 12; i <= 48; i += 18)
		if (solutions[i] == 0 && d[0] != d[4])
		{
			if (d[0] == d[1] && d[2] == d[3] && d[3] == d[4])
				solutions[i] = 30;
			if (d[4] == d[3] && d[2] == d[1] && d[1] == d[0])
				solutions[i] = 30;
		}
}

void	ft_sol_carre(int *qds, int *solutions)
{
	for (int n = 1; n <= 6; n++)
		if (qds[n] >= 4)
		{
			for (int i = 13; i <= 49; i += 18)
				if (solutions[i] == 0)
					solutions[i] = 4 * n + 40;
		}
}

void	ft_sol_suite(int *qds, int *solutions)
{
	for (int n = 1; n <= 6; n++)
		if (qds[n] > 1)
			return ;
	if (qds[1] == 1 && qds[6] == 1)
			return ;
	for (int i = 14; i <= 50; i += 18)
		if (solutions[i] == 0)
			solutions[i] = 50;
}

void	ft_sol_yams(int *qds, int *solutions)
{
	for (int n = 1; n <= 6; n++)
		if (qds[n] == 5)
		{
			for (int i = 15; i <= 51; i += 18)
				if (solutions[i] == 0)
					solutions[i] = 5 * n + 60;
		}
}

void	ft_get_solutions(int *dices, int *sol, int *val, int *rank, int jet)
{
	int	qds[7]; // {sum, q1, q2, q3, q4, q5, q6};
	
	ft_init_solutions(rank, sol, jet);
	ft_count_dices(dices, qds);
	ft_sol_maxdices(qds, sol);
	ft_sol_min(qds, sol, val, rank);
	ft_sol_max(qds, sol, val, rank);
	ft_sol_brelan(qds, sol);
	ft_sol_full(dices, sol);
	ft_sol_carre(qds, sol);
	ft_sol_suite(qds, sol);
	ft_sol_yams(qds, sol);
}
