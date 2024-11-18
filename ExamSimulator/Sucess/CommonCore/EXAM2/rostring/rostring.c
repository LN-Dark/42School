#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int start = -1;
	int end = -1;
	int space = 1;
	int writed = 0;
	char *str;

	if(argc > 1)
	{
		while (argv[1][i] != '\0')
		i++;
		str = malloc(sizeof(char) * i + 1);
		while (j <= i){
			str[j] = '\0';
			j++;
		}
		j = 0;
		i = 0;
		while(argv[1][i] < 33){
			i++;
		}
		start = i;
		while (argv[1][i] >= 33 && argv[1][i] < 127 && argv[1][i] != '\0'){
			i++;
		}
		end = i;
		while (argv[1][i] != '\0'){
			while (argv[1][i] <= 32 && argv[1][i] != '\0'){
				i++;
				space = 0;
			}
			if (space == 0 && argv[1][i] != '\0'){
				str[j] = ' ';
				space = 1;
				j++;
			}
			if(argv[1][i] != '\0'){
				str[j] = argv[1][i];
				writed++;
				i++;
				j++;
			}
		}
		j = 0;
		if (str[j] == ' ')
			j++;
		while (str[j] != '\0'){
			write(1, &str[j], 1);
			j++;
		}
		free(str);
		if (writed > 0)
			write(1, " ", 1);
		while (start < end){
			write(1, &argv[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}
