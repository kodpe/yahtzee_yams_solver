/*****************************************************************************/
/*                                                                           */
/*  yams tmp.c                                                               */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/

#include "yams.h"

int	ft_have_reroll(int *rank)
{
	for (int i = 0; i < 18; i++)
		if (rank[i] == 0)
			return (1);
	for (int i = 36; i < 54; i++)
		if (rank[i] == 0)
			return (1);
	return (0);
}

void	ft_show_solutions(int mode, int *solutions, int *rank)
{
	if (mode > 1)
	{
		ft_putstr("\n");
		ft_display_scoretab(solutions, rank, -1);
	}
}

int	ft_minmax(int x, int s)
{
	if (x == 9 || x == 10)
		return (s);
	if (x == 27 || x == 28)
		return (s);
	if (x == 45 || x == 46)
		return (s);
	if (s == 1)
		return (0);
	if (s == 0)
		return (1);
	return (-1);
}

void	ft_put_index(int *tab, int i, char *caption)
{
		ft_putstr("  ");
		ft_putstr(caption);
		ft_putstr(" [");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putnbr(tab[i]);
		ft_putstr("\n");
}

void	ft_comb(int *comb, int *solutions, int mode)
{
	comb[0] = solutions[11];
	comb[1] = solutions[12];
	comb[2] = solutions[13];
	comb[3] = solutions[14];
	comb[4] = solutions[15];

	comb[5] = solutions[29];
	comb[6] = solutions[30];
	comb[7] = solutions[31];
	comb[8] = solutions[32];
	comb[9] = solutions[33];

	comb[10] = solutions[47];
	comb[11] = solutions[48];
	comb[12] = solutions[49];
	comb[13] = solutions[50];
	comb[14] = solutions[51];

	if (mode == 4) // if (mode > 1)
	{
		ft_putstr("\n  Libre\n");
		for (int i = 0; i <= 4; i++)
			ft_put_index(comb, i, "hey");

		ft_putstr("\n  Sec\n");
		for (int i = 5; i <= 9; i++)
			ft_put_index(comb, i, "hey");

		ft_putstr("\n  Descente\n");
		for (int i = 10; i <= 14; i++)
			ft_put_index(comb, i, "hey");
	}
}

void	ft_do_game(int *values, int *rank, int mode)
{
	int	dices[5];
	int	solutions[54];
	int	x;

	for (int turn = 1; turn <= 39; turn++)
	{
		for (int jet = 1; jet <= 3; jet++)
		{
			values[54] += 1; //dice roll count
			ft_get_dices(dices, jet, mode, turn);
			ft_get_solutions(dices, solutions, values, rank, jet);
			ft_show_solutions(mode, solutions, rank);

			/* ft get relance if jet < 3
			   if (ft_have_reroll(rank) == 1 && jet < 3)
			   ft_get_relances(dices, values, rank);
			 */
			int	comb[15] = {0};
			ft_comb(comb, solutions, mode);

			/// ---------------- CHOIX -----------------
			/////////////// x = plus gros score dans solutions
			x = 0;
			for (int s = 53; s > 0; s--)
				if (solutions[s] > solutions[x])
					x = s;

			////////// conditions d'arrêt précoce si relance possible
			if (solutions[x] > 0) 
				break ; // si on a au moins un score de 1 qui nest pas minmax
			//// --------------------------------------------------///

			if (ft_have_reroll(rank) == 0) // si on ne peut pas relancer
				break ;
			ft_init_dices(dices); //reset 0 all dices for reroll all dices 
		}
		ft_up_turn(values, solutions, rank, x, mode, turn);
	}
}
// choisir une solution
// remplir une case ou relancer les dés
//if (relance) quels dés relancer ? combien ?
// remplir une case ou relancer les dés

/*

   TYPES DE RELANCES

   RELANCES VERS LA SUITE COMPLICADO

   '>>' = relance

   > RACE YAMS

   - Y (Yams)         5i          > ok!  

   - C (Carré)        4i + u      >> u

   - F (Full)         3i + 2i     >> 2i 

   - B (Brelan)       3i + 2u     >> 2u

   - D (Double paire) 2i + 2i + u >> 2i + u OR 2i + u // val choice

   - P (Paire)        2i + 3u     >> 3u 

   - R (Rien)         5u          >> 4u OR 5u // val choice


   > RACE FULL : on cherche jamais le full
   > RACE SUITE : pour l'instant on ne cherche pas à faire des suites
   > RACE VAL


   Carré de 1 sec / 4
   > Choisir quand prendre une solution sèche ? ou relancer ?
   > si la solution sèche est une combinaison on la prend toujours 
   > meme brelan de 1 ?






 */
