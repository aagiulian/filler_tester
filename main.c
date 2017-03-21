/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:35:57 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/21 18:54:34 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfiller.h"

void	print_header(void)
{
	printf("-------------------------------------------\n");
	printf("-----------FILLER ANALYSIS SCRIPT----------\n");
	printf("-------------------------------by agiulian-\n\n");
	printf("RULES :\n");
	printf("        Players should be in ./players/\n");
	printf("        Maps should be in ./maps/\n");
	printf("        VM should be in current directory\n");
	printf("        Maps 00, 01 and 02 will be played\n");
	printf("        If more than 1/2 victories\n");
	printf("        WIN otherwise LOOSE\n");
	printf("        GOOD LUCK\n\n");
}

void	print_result(char *player1, char *player2, int nb, int score)
{
	printf("%-12s VS    %-12s :", player1, player2);
	printf(" [%i/%i] ", score, nb);
	if (score > (nb / 2))
		printf("\x1B[32mWin\x1B[0m\n");
	else
		printf("\x1B[31mLoose\x1B[0m\n");
}

void	fill_players(t_prm *prm)
{
	prm->player_nb = 6;
	if (!(prm->player_lst = (char**)malloc(sizeof(char*) * prm->player_nb \
					+ 1)))
		exit(-1);
	prm->player_lst[0] = "abanlin";
	prm->player_lst[1] = "carli";
	prm->player_lst[2] = "champely";
	prm->player_lst[3] = "grati";
	prm->player_lst[4] = "hcao";
	prm->player_lst[5] = "superjeannot";
	prm->player_lst[6] = NULL;
}

void	config(t_prm *prm, char player_name[21])
{
	prm->entry = malloc(150);
	prm->response = malloc(100);
	prm->nb1 = 0;
	prm->nb2 = 0;
	printf("Enter player name :\n(max 20 char)\n");
	scanf("%s", player_name);
	printf("Do you wish to play as p1 ? (y or n)\n");
	scanf("%s", prm->response);
	if (prm->response[0] == 'y')
	{
		printf("Enter number of games to be played as p1 :\n");
		scanf("%i", &prm->nb1);
	}
	printf("Do you wish to play as p2 ? (y or n)\n");
	scanf("%s", prm->response);
	if (prm->response[0] == 'y')
	{
		printf("Enter number of games to be played as p2 :\n");
		scanf("%i", &prm->nb2);
	}
	printf("\n Let's go %s, may the force be with you !\n\n", player_name);
}

int		main(void)
{
	char	player_name[21];
	t_prm	*prm;

	print_header();
	if (!(prm = malloc(sizeof(t_prm))))
		exit(-1);
	fill_players(prm);
	config(prm, player_name);
	map00(prm, player_name);
	map01(prm, player_name);
	map02(prm, player_name);
	return (0);
}
