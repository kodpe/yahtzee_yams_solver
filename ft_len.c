/*****************************************************************************/
/*                                                                           */
/*  yams ft_len.c                                                            */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_nbrlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_doublelen(long double db)
{
	int	len;
	int	nbr;

	nbr = db / 1;
	len = 8;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
