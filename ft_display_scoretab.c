/*****************************************************************************/
/*                                                                           */
/*  yams ft_display_scoretab.c                                               */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_putline(char start, char mid, char end, int len)
{
	ft_putchar(' ');
	ft_putchar(start);
	ft_putqchar(mid, len);
	ft_putchar(end);
	ft_putchar('\n');
}

void	ft_put_caption(int mode, char *str, int len)
{
	ft_putline(' ', '=', ' ', len);
	ft_putstr(" | ");
	if (mode == 39)
			ft_putstr("SCOREBOARD        ");
	if (mode == -1)
		ft_putstr("SOLUTIONS         ");
	if (mode >= 1 && mode <= 38)
	{
		ft_putstr("TURN ");
		ft_putnbr(mode);
		ft_putqchar(' ', 13 - ft_nbrlen(mode));
	}
	ft_putstr(str);
	ft_putstr(" |\n");
	ft_putline('|', '-', '|', len);
}

void	ft_put_total(int *values)
{
	int	total;

	total = values[17] + values[35] + values[53];
	ft_putline('|', '-', '|', 51);
	ft_putstr(" | JETS ");
	ft_putnbr(values[54]);
	ft_putqchar(' ', 44 - ft_nbrlen(total) - ft_nbrlen(values[54]));
	ft_putnbr(total);
	ft_putstr(" |\n");
}

void	ft_put_rank(int rank)
{
	if (rank >= 0)
	{
		ft_putstr("  <");
		ft_putqchar(' ', 2 - ft_nbrlen(rank));
		ft_putnbr(rank);
		ft_putstr(" ");
	}
	else
		ft_putstr("      ");
}

void	ft_put_values(int i, int *values, int *rank, int mode)
{
	int r;

	for (int k = 0; k < 3; k++)
	{
		r = 18 * k + i;
		if (values[r] >= 0)
		{
			ft_putqchar(' ', 5 - ft_nbrlen(values[r]));
			if (rank[r] == mode && mode < 39)
				ft_put_green();
			if (rank[r] == 0 && mode != -1)
				ft_put_yellow();
			ft_putnbr(values[r]);
			ft_put_rank(rank[r]);
			ft_reset_put_color();
			ft_putstr("|");
		}
		else
			ft_putstr("           |");
	}
	ft_putstr("\n");
}

void	ft_display_scoretab(int *values, int *rank, int mode)
{
	char	*lines_names[18] = {
		" | Total de 1    |", " | Total de 2    |", " | Total de 3    |",
		" | Total de 4    |", " | Total de 5    |", " | Total de 6    |",
		" | Total         |", " | Bonus         |", " | TOTAL DES     |",
		" | Minimum       |", " | Maximum       |", " | Brelan        |",
		" | Full          |", " | Carre         |", " | Suite         |",
		" | Yams          |", " | TOTAL FIGURES |", " | TOTAL GENERAL |",
	};
	char	*caption = "Libre        Sec       Descente";

	ft_put_caption(mode, caption, 51);
	for (int i = 0; i < 18; i++)
	{
		if (i == 16 && mode == -1)
			break ;
		if (i == 6 && mode == -1)
			i = 9;
		if (i == 9 || i == 17)
			ft_putline('|', '-', '|', 51);
		ft_putstr(lines_names[i]);
		ft_put_values(i, values, rank, mode);
	}
	if (mode > 0)
		ft_put_total(values);
	ft_putline(' ', '=', ' ', 51);
}
