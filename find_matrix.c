/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:30:21 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 15:18:05 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_arr[24][4];
int		check_col(int *input, int col, int ith);
void	update(int (*matrix)[4], int col, int ith);
int		check_matrix(int (*matrix)[4], int *input);
int		print_matrix(int (*matrix)[4]);

void	update(int (*matrix)[4], int col, int ith)
{
	int *column;
	int row;

	column = g_arr[ith];
	row = 0;
	while (row < 4)
	{
		matrix[row][col] = g_arr[ith][row];
		++row;
	}
}

void	find_matrix(int (*matrix)[4], int *input, int col, int *printed)
{
	int		ith;
	char	ch;
	
	if (*printed)
		return ;
	ith = 0;
	while (ith < 24)
	{
		if (check_col(input, col, ith))
		{
			update(matrix, col, ith);
			if (col == 3)
			{
				if (check_matrix(matrix, input))
				{
					print_matrix(matrix);
					*printed = 1;
					return ;
				}
			}
			else{
				find_matrix(matrix, input, col + 1, printed);
			}
		}
		++ith;
	}
}
