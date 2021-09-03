/*****************************************************************************/
/*                                                                           */
/*  yams tools.c                                                             */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

/* display fuctions */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putqchar(char c, int q)
{
	while (q-- > 0)
		ft_putchar(c);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_put_tab(int *tab, int size)
{
	ft_putstr("|");
	ft_put_green();
	ft_putnbr(tab[0]);
	for (int i = 1; i < size; i++)
	{
		ft_putstr(" ");
		ft_putnbr(tab[i]);
	}
	ft_reset_put_color();
	ft_putstr("|");
}

void	ft_putdouble(long double db, int decimals)
{
	int	nbr;

	if (db < 0)
	{
		ft_putchar('-');
		db = -db;
	}
	nbr = (int)(db / 1);
	ft_putnbr(nbr);
	ft_putchar('.');
	for (int i = 0; i < decimals; i++)
	{
		db *= 10;	
		nbr = (int)(db / 1);
		nbr %= 10;
		ft_putnbr(nbr);
	}
}
