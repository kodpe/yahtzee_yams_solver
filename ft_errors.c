/*****************************************************************************/
/*                                                                           */
/*  yams ft_errors.c                                                         */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_show_commands(void)
{
	printf("\tresult, score, res, s, r : display only scoreboard\n");
	printf("\tmanual, man, m           : real dice roll mode\n");
	printf("\tanalyse, auto, all, a    : automatic mode\n");
	printf("\t{a large number}         : multiple games\n");
	printf("\tkkk, kk, k               : 1000k, 100k, 10k games\n");
}

int	ft_check_mode(char *av)
{
	if (strcmp(av, "score") == 0)
		return (1);
	if (strcmp(av, "result") == 0 || strcmp(av, "res") == 0)
		return (1);
	if (strcmp(av, "s") == 0 || strcmp(av, "r") == 0)
		return (1);
	if (strcmp(av, "manual") == 0)
		return (2);
	if (strcmp(av, "man") == 0 || strcmp(av, "m") == 0)
		return (2);
	if (strcmp(av, "analyse") == 0 || strcmp(av, "auto") == 0)
		return (3);
	if (strcmp(av, "all") == 0 || strcmp(av, "a") == 0)
		return (3);
	if (strcmp(av, "k") == 0)
		return (10000);
	if (strcmp(av, "kk") == 0)
		return (100000);
	if (strcmp(av, "kkk") == 0)
		return (1000000);
	return (0);
}

int	ft_error_ac(int ac)
{
	ft_red();
	if (ac < 2)
		printf(">>> ERROR AC >>> Too few arguments (need one)\n");
	if (ac > 2)
		printf(">>> ERROR AC >>> Too many arguments (need one)\n");
	ft_reset_color();
	ft_show_commands();
	return (0);
}

int	ft_error_unknown(char *av)
{
	ft_red();
	printf(">>> ERROR INIT >>> Unknown command \"%s\"\n", av);
	ft_reset_color();
	ft_show_commands();
	return (0);
}
int	ft_error_over(int n)
{
	ft_red();
	printf(">>> ERROR INIT >>> N_GAMES(%d) > N_MAX(64810000)\n", n);
	ft_reset_color();
	return (0);
}
int	ft_error_less(int n)
{
	ft_red();
	printf(">>> ERROR INIT >>> N_GAMES(%d) < N_MIN(10000)\n", n);
	ft_reset_color();
	return (0);
}

int	ft_check_init(char *av)
{
	int	nbr_games;

	if (ft_check_mode(av))
		return (ft_check_mode(av));
	nbr_games = atoi(av);
	if (nbr_games == 0)
		return (ft_error_unknown(av));
	if (nbr_games > 64818000)
		return (ft_error_over(nbr_games));
	if (nbr_games < 10000)
		return (ft_error_less(nbr_games));
	return (nbr_games);
}
