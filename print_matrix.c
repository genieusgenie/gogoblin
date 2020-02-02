/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:33:16 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 14:51:10 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int (*matrix)[4])
{
	int		row;
	int		col;
	char	ch;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ch = (char)matrix[row][col] + '0';
			write(1, &ch, 1);
			if (col != 3)
				write(1, " ", 1);
			++col;
		}
		write(1, "\n", 1);
		++row;
	}
}
