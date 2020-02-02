/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:09:58 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 15:17:41 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		g_arr[24][4] = {
	{1, 2, 3, 4}, {4, 3, 2, 1}, {4, 1, 2, 3}, {4, 2, 1, 3},
	{3, 1, 2, 4}, {3, 2, 1, 4}, {4, 1, 3, 2}, {4, 2, 3, 1},
	{4, 3, 1, 2}, {1, 3, 2, 4}, {2, 1, 3, 4}, {2, 3, 1, 4},
	{1, 4, 3, 2}, {2, 4, 3, 1}, {3, 4, 2, 1}, {1, 2, 4, 3},
	{1, 3, 4, 2}, {2, 3, 4, 1}, {1, 4, 2, 3}, {2, 1, 4, 3},
	{2, 4, 1, 3}, {3, 1, 4, 2}, {3, 2, 4, 1}, {3, 4, 1, 2}
};

void	copy_src_to_input(int *input, char *src);
void	reset_matrix(int (*matrix)[4]);
void	find_matrix(int (*matrix)[4], int *input, int col, int *printed);
int		manage_error(int argc, char **argv, int *input);

int		main(int argc, char **argv)
{
	int input[16];
	int matrix[4][4];
	int printed;

	copy_src_to_input(input, argv[1]);
	if (manage_error(argc, argv, input))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	reset_matrix(matrix);
	printed = 0;
	find_matrix(matrix, input, 0, &printed);
	return (0);
}
