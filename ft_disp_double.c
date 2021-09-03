/*****************************************************************************/
/*                                                                           */
/*  yams ft_dis_double.c                                                     */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_put_mean_rank(long double rank)
{
	if (rank >= 0)
	{
		ft_putstr("  <");
		ft_putqchar(' ', 9 - ft_doublelen(rank));
		ft_putdouble(rank, 3);
		ft_putstr(" |");
	}
	else
		ft_putstr("          |");
}

void	ft_put_mean(int i, long double *val, long double *rank)
{
	int r;

	for (int k = 0; k < 3; k++)
	{
		r = 18 * k + i;
		if (val[r] >= 0)
		{
			ft_putqchar(' ', 12 - ft_doublelen(val[r]));
			ft_putdouble(val[r], 3);
			ft_put_mean_rank(rank[r]);
		}
		else
			ft_putstr("           |");
	}
	ft_putstr("\n");
}

void	ft_disp_final_score(long double *mean_values)
{
	long double	s;

	s = mean_values[17] + mean_values[35] + mean_values[53];
	printf("\n\n   ***** TOTAL %.3LF     ", s);
	printf("RANGE (%.3LF : %.3LF)", s - (s * 0.005), s + (s * 0.005));
	printf("     THROW %.3LF *****\n", mean_values[54]);
}

void	ft_disp_tab(long double *values, long double *rank)
{
	char	*lines_names[18] = {
		" | Total de 1    |", " | Total de 2    |", " | Total de 3    |",
		" | Total de 4    |", " | Total de 5    |", " | Total de 6    |",
		" | Total         |", " | Bonus         |", " | TOTAL DES     |",
		" | Minimum       |", " | Maximum       |", " | Brelan        |",
		" | Full          |", " | Carre         |", " | Suite         |",
		" | Yams          |", " | TOTAL FIGURES |", " | TOTAL GENERAL |",
	};
	char	*cap = "    Libre                Sec              Descente     ";
	int	len;

	len = 75;
	ft_disp_final_score(values);
	ft_put_caption(39, cap, len);
	for (int i = 0; i < 18; i++)
	{
		if (i == 9 || i == 17)
			ft_putline('|', '-', '|', len);
		ft_putstr(lines_names[i]);
		ft_put_mean(i, values, rank);
	}
	ft_putline(' ', '=', ' ', len);
	ft_putchar('\n');
}
