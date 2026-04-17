/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:54:27 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/04 14:59:29 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n);

void print_number(int n)
{
    char c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        print_number(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

void run_test(char *s1, char *s2, unsigned int n, int test_num)
{
    int my_result = ft_strncmp(s1, s2, n);
    int orig_result = strncmp(s1, s2, n);

    write(1, "Test ", 5);
    print_number(test_num);
    write(1, ": ft_strncmp = ", 15);
    print_number(my_result);
    write(1, ", strncmp = ", 12);
    print_number(orig_result);
    write(1, "\n", 1);
}

int main(void)
{
    char *s1 = "Om Tare Tuttare Ture Svaha";
    char *s2 = "Tashi Delek";
    char *s3 = "Om Tare Tuttare Ture Svaha";
    char *s4 = "Om Tare Tam Svaha";
    char *s5 = "";

    run_test(s1, s3, 5, 1);  // Expect 0 (same first 5 chars)
    run_test(s1, s2, 3, 2);  // Expect nonzero (first char difference)
    run_test(s2, s1, 3, 3);  // Expect nonzero (reverse order)
    run_test(s1, s3, 50, 4); // Expect 0 (identical strings)
    run_test(s1, s4, 20, 5); // Expect nonzero (s4 is shorter)
    run_test(s1, s4, 18, 6); // Expect 0 (same first 18 chars)
    run_test(s1, s5, 10, 7); // Expect nonzero (s1 vs empty string)
    run_test(s5, s1, 10, 8); // Expect nonzero (empty string vs s1)

    return (0);
}
