#include <unistd.h>
#include <stdlib.h>

int nextwordindex(char *str){
	int i = 0;
	
	while(str[i] != '\0' && str[i] <= 32)
		i++;
	return (i);
}

int ft_strlen(char *str){
	int i = 0;
	while (str[i] != '\0'){
		i++;
	}
	return (i);
}

int main(int argc, char **argv){

	if(argc > 1){
		int j = nextwordindex(argv[1]);
		int start = nextwordindex(argv[1]);
		int end = nextwordindex(argv[1]);
		int writed = 0; 
		
		while (argv[1][j] != '\0' && argv[1][j] >= 33){
			end++;
			j++;
		}
		while(argv[1][j] != '\0'){
			while (argv[1][j] != '\0' && argv[1][j] >= 33){
				write(1, &argv[1][j], 1);
				writed = 1;
				j++;
			}
			j += nextwordindex(argv[1] + j);
			if (writed > 0)
				write(1, " ", 1);
		}
		while (start < end){
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
