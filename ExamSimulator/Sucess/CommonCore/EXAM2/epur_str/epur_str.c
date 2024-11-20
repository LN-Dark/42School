#include <unistd.h>

int ft_strlen(char *str){
	int i = 0;
	while(str[i] != '\0')
		i++;
	return(i);
}

int nextWord(char *str){
	int i = 0;
	while (str[i] != '\0' && str[i] <= 32)
		i++;
	return(i);
}

int main(int argc, char **argv){

	int i = 0;
	if (argc == 2){
		i = nextWord(argv[1]);
		while (argv[1][i] != '\0'){
			while(argv[1][i] != '\0' && argv[1][i] > 32){
				write(1, &argv[1][i], 1);
				i++;
			}
			i += nextWord(argv[1] + i);
			if(i < ft_strlen(argv[1])){
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
