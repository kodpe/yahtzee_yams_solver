/*****************************************************************************/
/*                                                                           */
/*  yams ft_get_dices.c                                                      */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

void	ft_init_dices(int *dices)
{
	for (int i = 0; i < 5; i++)
		dices[i] = 0;
}

int	ft_count_zero(int *dices)
{
	int	k;

	k = 0;
	for (int i = 0; i < 5; i++)
		if (dices[i] == 0)
			k++;
	return (k);
}

void	ft_scan_dices(char *str, int n)
{
	printf("\33[2K\r");
	printf("Enter the values of %d dices : ", n);
	if (n == 5)
		scanf("%6[1-6]", str);
	if (n == 4)
		scanf("%5[1-6]", str);
	if (n == 3)
		scanf("%4[1-6]", str);
	if (n == 2)
		scanf("%3[1-6]", str);
	if (n == 1)
		scanf("%2[1-6]", str);
	scanf("%*[^\n]");
	getchar();
}

void	ft_request_dices(int *dices)
{
	char	str[6] = {0};
	int		n;
	int		nbr;

	ft_sort_tab(dices, 5);
	n = ft_count_zero(dices);
	nbr = 0;
	while (nbr != n)
	{
		ft_scan_dices(str, n);
		nbr = 0;
		for (int i = 0; i < n; i++)
		{
			dices[i] = str[i] - 48;
			if (dices[i] < 1 || dices[i] > 6)
				nbr = 0;
			nbr++;
		}
		if (str[n])
			nbr = 0;
		if (nbr != n)
			printf("\33[A");
	}
}

void	ft_get_dices(int *dices, int jet, int mode, int turn)
{
	if (jet == 1)
		ft_init_dices(dices);
	if (mode == 2)
		ft_request_dices(dices);
	else
		ft_rool_zero(dices);
	ft_show_dices(mode, dices, turn, jet);
}

void	ft_show_dices(int mode, int *dices, int turn, int jet)
{
	if (mode > 1)
	{
		if (jet == 1)
		{
			ft_putqchar(' ', 3);
			ft_putstr("\n\n   T");
			ft_putnbr(turn);
		}
		ft_putstr(" ");
		ft_put_tab(dices, 5);
	}	
}
