/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfiller.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:58:04 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/21 18:51:15 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFILLER_H
# define SFILLER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_prm
{
	int			nb1;
	int			nb2;
	char		*response;
	char		*system;
	char		**player_lst;
	int			player_nb;
	int			fd;
	char		*entry;
	int			p1;
	int			p2;
	char		buf[4097];
}				t_prm;

void			map00(t_prm *prm, char player[21]);
void			map00p1(t_prm *prm, char player[21]);
void			map00p2(t_prm *prm, char player[21]);
void			map01(t_prm *prm, char player[21]);
void			map01p1(t_prm *prm, char player[21]);
void			map01p2(t_prm *prm, char player[21]);
void			map02(t_prm *prm, char player[21]);
void			map02p1(t_prm *prm, char player[21]);
void			map02p2(t_prm *prm, char player[21]);
void			print_result(char *player1, char *player2, int nb, int score);

#endif
