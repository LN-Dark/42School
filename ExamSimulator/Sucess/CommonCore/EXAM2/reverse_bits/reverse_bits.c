unsigned char	reverse_bits(unsigned char octet){
	unsigned int	i;
	unsigned char	res = 0;

	i = 8;
	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}
