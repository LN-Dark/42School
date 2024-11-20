#include <stdlib.h>
#include <stdio.h>

long intlen(long nbr){
	unsigned int len = 0;
	if(nbr == 0)
		return (1);
	if(nbr < 0)
		len++;
	while (nbr != 0){
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int nbr){
	long nb = nbr;
	long len = intlen(nb);
	char *str = malloc(sizeof(char) * (len + 1));
	
	if (nb < 0){
		str[0] = '-';
		nb *= -1;
	}
	if(nb == 0)
		str[0] = '0';
	str[len] = '\0';
	len--;
	while (nb != 0){
		str[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (str);
}

