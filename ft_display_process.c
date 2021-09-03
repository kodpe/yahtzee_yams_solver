/*****************************************************************************/
/*                                                                           */
/*  yams ft_display_process.c                                                */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_display_header(void)
{
	time_t timestamp;

	timestamp = time(NULL);
	system("clear -x");
	printf("\n>>>>>>>>>>>>>>>>>>>>> YAMS APP <<<<<<<<<<<<<<<<<<<<<\n");
	//system("ls -go *.h *.c");
	printf("\n>>> %s\n", ctime(&timestamp));
}

void	ft_display_ngames(int n, int ngames)
{
	ft_red();
	if (n == ngames)
		ft_green();
	printf(">>> Process %d games ", ngames);
}

void	ft_display_points(int pos, int q)
{
	ft_green();
	for (int i = 0; i < q; i++)
		printf(".");
	ft_red();
	for (int i = pos; i > q; i--)
		printf(".");
	ft_reset_color();
}

void	ft_display_percentage(int n, int ngames)
{
	ft_red();
	if (n == ngames)
		ft_green();
	printf(" %d%%", (n * 100 / ngames));
}

void	ft_display_time(int n, int ngames)
{
	int	sec;
	int	min;

	ft_yellow();
	sec = 1 + ((ngames - n) / 18000) % 60;
	min = ((ngames - n) / 18000) / 60;
	if (min > 0)
		printf(" %dm", min);
	if (sec > 0)
		printf(" %ds", sec);
	ft_reset_color();
}

void	ft_display_process(int n, int ngames)
{
	int	pos;

	pos = 50;
	if (n % (ngames / pos) == 0 || n == 1 || n == ngames)
	{
		printf("\33[2K\r");
		ft_display_ngames(n, ngames);
		ft_display_points(pos, n * pos / ngames);
		ft_display_percentage(n, ngames);
		if (n != ngames)
			ft_display_time(n, ngames);
		fflush(stdout);
		ft_reset_color();
	}
}
