
#include <stdlib.h>

int ft_strlen(char *str){
	int i = 0;
	
	while (str[i] != '\0' && str[i] >= 33)
		i++;
	return (i);
}

int ft_count(char *str){
	int i = 0;
	int words = 0;

	while(str[i] != '\0'){
		if(str[i] >= 33 && str[i - 1] <= 33)
			words++;
		i++;
	}
	return (words);
}

int checkspaces(char *str){
	int i = 0;
	
	while(str[i] != '\0' && str[i] <= 32)
		i++;
	return (i);
}

char    **ft_split(char *str){
	int i = 0;
	int j = 0;
	int k = 0;
	int wordsint = ft_count(str);
	char **strsplit = malloc(sizeof(char *) * (ft_count(str) + 1));
	
	while(i < wordsint){
		k = 0;
		j += checkspaces(str + j);
		strsplit[i] = malloc(sizeof(char) * ft_strlen(str + j) + 1);
		while ((str + j)[k] != '\0' && (str + j)[k] >= 33){
			strsplit[i][k] = (str + j)[k];
			k++;
		}
		strsplit[i][k] = '\0';
		j += k + 1;
		i++;
	}
	strsplit[i] = NULL;
	return(strsplit);
}
