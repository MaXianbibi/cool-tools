/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:13:28 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/04 22:54:54 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union
{
	struct
	{
		unsigned char	a;
		unsigned char	b;
		unsigned char	c;
		unsigned char	d;
	} octets;
	unsigned int		value;
}						IPAddress;

void	printIP(IPAddress ip)
{
	printf("%u.%u.%u.%u\n", ip.octets.a, ip.octets.b, ip.octets.c, ip.octets.d);
}

IPAddress	convert_string_to_ip(char *str)
{
	char		*split[100] = {0};
	int			i;
	char		*cpy;
	char		*token;


	i = 0;
	cpy = strdup(str);
	token = strtok(cpy, ".");
	while (token)
	{
		split[i] = token;
		token = strtok(NULL, ".");
		i++;
	}
	i = 0;
	IPAddress ip1 = {.octets.a = atoi(split[0]), .octets.b = atoi(split[1]),
		.octets.c = atoi(split[2]), .octets.d = atoi(split[3])};
	free(cpy);
	return (ip1);
}

void	print_list(unsigned int mask, unsigned int ip1)
{
	unsigned int	mf;

	mf = 0;
	printf("voici une list des ip local disponible : \n");
	while (mf < 0xFFFFFFFF)
	{
		if ((mf & mask) == (mask & ip1))
		{
			IPAddress tmp = {.value = mf};
			printIP(tmp);
		}
		mf++;
	}
}

int	main(void)
{
	unsigned int imask = convert_string_to_ip("255.255.255.240").value;
	unsigned int ip1 = convert_string_to_ip("133.240.25.62").value;

	
	unsigned int ip2 = convert_string_to_ip("0.0.0.0").value;

	if ((ip1 & imask) ==
		(ip2 & imask))
		printf("Same réseau \n");
	else
		print_list(imask, ip1);
}