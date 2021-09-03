/*****************************************************************************/
/*                                                                           */
/*  yams ft_colors.c                                                         */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_red(void)
{
	printf("\e[0;31m");
}

void	ft_green(void)
{
	printf("\e[0;92m");
}

void	ft_yellow(void)
{
	printf("\e[1;93m");
}

void	ft_reset_color(void)
{
	printf("\e[0m");
}

void	ft_put_red(void)
{
	ft_putstr("\033[0;31m");
}

void	ft_put_green(void)
{
	ft_putstr("\033[0;92m");
}

void	ft_put_yellow(void)
{
	ft_putstr("\033[0;33m");
}

void	ft_reset_put_color(void)
{
	ft_putstr("\033[0;37m");
}
