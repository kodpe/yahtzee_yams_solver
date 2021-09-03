/*****************************************************************************/
/*                                                                           */
/*  yams.h                                                                   */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef YAMS_H
# define YAMS_H

#include <time.h>
#include "display.h"

/*		tmp.c
 */
int		ft_have_reroll(int *rank);
void	ft_show_solutions(int mode, int *solutions, int *rank);
void	ft_do_game(int *values, int *rank, int mode);

/*		ft_len.c
 */
int		ft_strlen(char *str);
int		ft_nbrlen(int nbr);
int		ft_doublelen(long double db);

/*		ft_math.c
 */
void	ft_add_mean(long double *dest, int *src, int x, int size);
void	ft_add_x_mean(long double *dest, int *src, int size, int len);
//int		ft_mean(int *array, int size); // useless
void	ft_swap(int *a, int *b);
void	ft_sort_tab(int *tab, int size);
void	ft_roll(int *dice);
void	ft_rool_zero(int *dices);
//void	ft_roll_five(int *dices); // useless
//void	ft_roll_rand(int *dices); // useless

/*		ft_update_scoretab.c
 */
void	ft_sum(int *val, int start, int end);
void	ft_up_rank(int *rank, int x);
void	ft_check_bonus(int *values);
void	ft_init_line(int *rank, int start, int end, int a);
void	ft_init_scoreboard(int *values, int *rank);
void	ft_update_scoretab(int *val, int *sol, int *rank, int x, int turn);
void	ft_up_turn(int *val, int *sol, int *rank, int x, int mode, int turn);
void	ft_show_choice(int mode, int *values, int *rank, int x);

/*		ft_get_dices.c
 */
void	ft_init_dices(int *dices);
int		ft_count_zero(int *dices);
void	ft_scan_dices(char *str, int n);
void	ft_request_dices(int *dices);
void	ft_get_dices(int *dices, int jet, int mode, int turn);
void	ft_show_dices(int mode, int *dices, int turn, int jet);

/*		ft_get_solutions.c
 */
void	ft_init_solutions(int *rank, int *solutions, int jet);
void	ft_count_dices(int *dices, int *qds);
void	ft_sol_maxdices(int *qds, int *solutions);
void	ft_sol_min(int *qds, int *solutions, int *values, int *rank);
void	ft_sol_max(int *qds, int *solutions, int *values, int *rank);
void	ft_sol_brelan(int *qds, int *solutions);
void	ft_sol_full(int *d, int *solutions);
void	ft_sol_carre(int *qds, int *solutions);
void	ft_sol_suite(int *qds, int *solutions);
void	ft_sol_yams(int *qds, int *solutions);
void	ft_get_solutions(int *dices, int *sol, int *val, int *rank, int jet);

#endif
