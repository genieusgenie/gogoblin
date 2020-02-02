/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_src_to_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 09:20:02 by jiwlee            #+#    #+#             */
/*   Updated: 2020/02/02 09:34:29 by jiwlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	copy_src_to_input(int *input, char *src)
{
	int src_ind;
	int input_ind;

	src_ind = 0;
	input_ind = 0;
	while (src[src_ind] != '\0')
	{
		if ('1' <= src[src_ind] && src[src_ind] <= '4')
		{
			input[input_ind] = src[src_ind] - '0';
			++input_ind;
		}
		++src_ind;
	}
}
