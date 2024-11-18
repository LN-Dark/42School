
int ver_base(char c, int base)
{
	char *up_base = "0123456789ABCDEF";
	char *down_base = "0123456789abcdef";
	while (base--)
	{
		if(up_base[base] == c || down_base[base] == c)
			return (1);
	}
	return (0);
}

int value(char c)
{
	if(c >= '0' && c <= '9')
	{
		return(c - '0');
	}else if(c >= 'A' && c <= 'F'){
		return (c - 'A' + 10);
	}else if(c >= 'a' && c <= 'f'){
		return (c - 'a' + 10);
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	
	while(str[i] != '\0' && str[i] <= 32)
	{
		i++;
	}
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while(ver_base(str[i], str_base))
	{
		result = result * str_base + value(str[i]);
		i++;
	}
	return (result * sign);
}
