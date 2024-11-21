#include <unistd.h>

int ft_atoi(char *str){
	int i = 0;
	int result = 0;
	
	while(str[i] != '\0'){
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result);
}

void ft_putnbr(int nb){
	int nbwrite = 0;
	if (nb >= 10){
		ft_putnbr(nb / 10);
		nbwrite = nb % 10 + '0';
		write(1, &nbwrite, 1);
	}else{
		nbwrite = nb + '0';
		write(1, &nbwrite, 1);
	}
}

int main(int argc, char **argv){
	int i = 1;
	int result = 0;
	if(argc == 2){
		int nb = ft_atoi(argv[1]);
		while (i <= 9){
			result = i * nb;
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(result);
			i++;
			write(1, "\n", 1);
		}
	}else{
		write(1, "\n", 1);
	}
}
