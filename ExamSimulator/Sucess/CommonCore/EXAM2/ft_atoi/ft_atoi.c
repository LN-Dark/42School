#include <stdio.h> 
int	ft_atoi(const char *str){
	int res = 0;
	int sign = 1;
	int i = 0;
	
	while(str[i] != '\0' && str[i] <= 32){
		i++;
	}
	if(str[i] == '-' || str[i] == '+'){
		if(str[i] == '-'){
			sign *= -1; 
		}
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9'){
		res *= 10;
		res += str[i] - 48;
		i++; 
	}
	return(res * sign);
}

