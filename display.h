/*****************************************************************************/
/*                                                                           */
/*  display.h                                                                */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#ifndef DISPLAY_H
# define DISPLAY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "yams.h"

/*		ft_put.c
 */
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putqchar(char c, int q);
void	ft_putnbr(int nb);
void	ft_put_tab(int *tab, int size);
void	ft_putdouble(long double db, int decimals);

/*		ft_errors.c
 */
void	ft_show_commands(void);
int		ft_check_mode(char *av);
int		ft_error_ac(int ac);
int		ft_error_unknown(char *av);
int		ft_error_over(int n);
int		ft_error_less(int n);
int		ft_check_init(char *av);

/*		ft_colors.c
 */
void	ft_red(void);
void	ft_green(void);
void	ft_yellow(void);
void	ft_reset_color(void);
void	ft_put_red(void);
void	ft_put_green(void);
void	ft_put_yellow(void);
void	ft_reset_put_color(void);

/*		ft_display_scoretab.c
 */
void	ft_putline(char start, char mid, char end, int len);
void	ft_put_caption(int mode, char *str, int len);
void	ft_put_total(int *values);
void	ft_put_rank(int rank);
void	ft_put_values(int i, int *values, int *rank, int mode);
void	ft_display_scoretab(int *values, int *rank, int mode);

/*		ft_disp_double.c
 */
void	ft_put_mean_rank(long double rank);
void	ft_put_mean(int i, long double *val, long double *rank);
void	ft_disp_final_score(long double *mean_values);
void	ft_disp_tab(long double *values, long double *rank);

/*		ft_display_process.c
 */
void	ft_display_header(void);
void	ft_display_ngames(int n, int ngames);
void	ft_display_points(int pos, int q);
void	ft_display_percentage(int n, int ngames);
void	ft_display_time(int n, int ngames);
void	ft_display_process(int n, int ngames);

#endif
