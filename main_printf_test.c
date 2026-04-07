/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ptsitova <ptsitova@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/10 10:46:43 by ptsitova      #+#    #+#                 */
/*   Updated: 2025/11/19 15:21:04 by ptsitova      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static void tests_basic_functionality()
{
	int	result_sys;
	int result_ft;

	printf("\n***tests basic functionality***\n\n");
	printf("printf   : ");
	result_sys = printf("%s%d%c%s%i%c%c%d", "bus ", 305, ' ', "at ", 15, ':', '0', 2);
	printf("\n");
	printf("count    : [%i]\n\n", result_sys);
	write(1, "ft_printf: ", 11);
	result_ft = ft_printf("%s%d%c%s%i%c%c%d", "bus ", 305, ' ', "at ", 15, ':', '0', 2);
	printf("\n");
	printf("count    : [%i]\n\n", result_ft);
	printf("-------------\n\n");
}

static void	tests_plain_text_in_the_beginning_and_end_of_the_string()
{
	int	result;

	printf("***tests plain text in the beginning and the end of the string***\n\n");
	result = printf("printf   : [Just text, %c, %d and %i, %c, %s]\n", 'a', INT_MIN, -4, 'b', "string");
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [Just text, %c, %d and %i, %c, %s]\n", 'a', INT_MIN, -4, 'b', "string");
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
}

static void	tests_pointer_argument()
{
	int		result;
	void	*string = ft_strdup("Hello world");
	long	number = 27;
	void 	*max_ptr = (void *)ULONG_MAX;

	printf("***tests basic pointer argument***\n\n");
	result = printf("printf   : [%p - %s]\n", string, (char *)string);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%p - %s]\n", string, (char *)string);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
	
	printf("***tests pointer argument if it == NULL***\n\n");
	result = printf("printf   : [%p]\n", NULL);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%p]\n", NULL);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
	
	printf("***tests function address passed as a pointer argument***\n\n");
	result = printf("printf   : [%p]\n", &tests_pointer_argument);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%p]\n", &tests_pointer_argument);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
	
	printf("***tests integer address passed as a pointer argument***\n\n");
	result = printf("printf   : [%p]\n", (void *)number);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%p]\n", (void *)number);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
	
	printf("***tests ULONG_MAX value address passed as a pointer argument***\n\n");
	result = printf("printf   : [%p]\n", max_ptr);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%p]\n", max_ptr);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
	free(string);
}

static void	tests_unsigned_decimal_argument()
{
	int	result;

	printf("***tests unsigned decimal argument***\n\n");
	result = printf("printf   : [%u, %u, %u, %u and %u]\n", 2, UINT_MAX, 0, 0005, -1);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%u, %u, %u, %u and %u]\n", 2, UINT_MAX, 0, 0005, -1);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
}

static void	tests_unsigned_hexadecimal_argument()
{
	int	result;

	printf("***tests unsigned hexadecimal argument - lowercase***\n\n");
	result = printf("printf   : [%x, %x, %x, %x and %x]\n", 45876897, UINT_MAX, 0, 0005, -1);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%x, %x, %x, %x and %x]\n", 45876897, UINT_MAX, 0, 0005, -1);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
	
	printf("***tests unsigned hexadecimal argument - UPPERCASE***\n\n");
	result = printf("printf   : [%X, %X, %X, %X and %X]\n", 45876897, UINT_MAX, 0, 0005, -1);
	printf("count    : [%i]\n\n", result);
	result = ft_printf("ft_printf: [%X, %X, %X, %X and %X]\n", 45876897, UINT_MAX, 0, 0005, -1);
	printf("count    : [%i]\n\n", result);
	printf("-------------\n\n");
}

int	main(void)
{

	ft_printf("ft_printf without newline");
	write(1, "write with newline\n", 19);
	
	printf("printf without newline");
	write(1, "write with newline\n", 19);

	tests_basic_functionality();
	tests_plain_text_in_the_beginning_and_end_of_the_string();
	tests_pointer_argument();
	tests_unsigned_decimal_argument();
	tests_unsigned_hexadecimal_argument();
	return (0);
}
