/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conceptual_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:58:15 by gcampbel          #+#    #+#             */
/*   Updated: 2024/03/27 18:19:51 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	fun_with_statics(void)
{
	static int	x = 0;

	printf("The current value of 'x' is %d.\n", x);
	printf("The number of times it has been called is %d.\n", (x + 1));
	x++;
}

int	main(void)
{
	fun_with_statics();
	fun_with_statics();
	fun_with_statics();
	fun_with_statics();
	fun_with_statics();
	return (0);

}