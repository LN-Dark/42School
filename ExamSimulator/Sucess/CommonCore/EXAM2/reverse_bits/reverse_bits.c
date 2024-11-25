unsigned char	reverse_bits(unsigned char octet){
	int	i = 7;
	int	j = 1;
	char	res = 0;
	int 	g = 128;
	
	while (i >= 0)
	{
		if (octet & (j << i))
		{
			res = res | (g >> i);
			--i;
		}
		else
			--i;
	}
	return (res);
}
