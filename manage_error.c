/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:44:02 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 14:57:42 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_1_exist_only_1time(int *input)
{
	int i;
	int j;
	int num_of_1;

	i = 0;
	while (i < 4)
	{
		num_of_1 = 0;
		j = 0;
		while (j < 4)
		{
			if (input[(i * 4) + j] == 1)
				++num_of_1;
			++j;
		}
		if (num_of_1 != 1)
			return (0);
		++i;
	}
	return (1);
}

int		is_4_exist_under_1time(int *input)
{
	int i;
	int j;
	int num_of_4;

	i = 0;
	while (i < 4)
	{
		num_of_4 = 0;
		j = 0;
		while (j < 4)
		{
			if (input[(i * 4) + j] == 4)
				++num_of_4;
			++j;
		}
		if (num_of_4 > 1)
			return (0);
		++i;
	}
	return (1);
}

int		is_valid_edge(int *input)
{
	if (input[0] == 1 && input[8] != 1)
		return (0);
	if (input[0] != 1 && input[8] == 1)
		return (0);
	if (input[3] == 1 && input[12] != 1)
		return (0);
	if (input[3] != 1 && input[12] == 1)
		return (0);
	if (input[4] == 1 && input[11] != 1)
		return (0);
	if (input[4] != 1 && input[11] == 1)
		return (0);
	if (input[7] == 1 && input[15] != 1)
		return (0);
	if (input[7] != 1 && input[15] == 1)
		return (0);
	return (1);
}

int		manage_error(int argc, char **argv, int *input)
{
	int i;

	if (argc != 2)
		return (1);
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 != 0 && argv[1][i] != ' ')
			return (1);
		if (i % 2 == 0 && !('1' <= argv[1][i] && argv[1][i] <= '4'))
			return (1);
		++i;
	}
	if (i != 31)
		return (1);
	if (!is_1_exist_only_1time(input) || !is_4_exist_under_1time(input) \
			|| !is_valid_edge(input))
		return (1);
	return (0);
}
