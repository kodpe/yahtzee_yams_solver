/*****************************************************************************/
/*                                                                           */
/*  yams main.c                                                               */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_play_one_game(int mode)
{
	int			values[55];
	int			rank[54];

	ft_init_scoreboard(values, rank);
	ft_do_game(values, rank, mode);
	if (mode == 1)
		ft_display_scoretab(values, rank, 39);
}

void	ft_play_x_game(int nbr_games)
{
	int			values[55];
	int			rank[54];
	long double	mean_values[55] = {0};
	long double	mean_rank[54] = {0};

	for (int n = 1; n <= nbr_games; n++)
	{
		ft_display_process(n, nbr_games);
		ft_init_scoreboard(values, rank);
		ft_do_game(values, rank, 1);
		ft_add_x_mean(mean_values, values, n, 55);
		ft_add_x_mean(mean_rank, rank, n, 54);
	}
	ft_disp_tab(mean_values, mean_rank);
}

int	main(int ac, char **av)
{
	int	mode;

	srand(time(NULL));
	ft_display_header();
	if (ac != 2)
		return (ft_error_ac(ac));
	if (ac == 2)
	{
		mode = ft_check_init(av[1]);
		if (!mode)
			return (0);
		if (mode <= 3)
			ft_play_one_game(mode);
		else
			ft_play_x_game(mode);
	}
	return (0);
}
