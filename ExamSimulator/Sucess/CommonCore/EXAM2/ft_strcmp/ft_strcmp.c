int    ft_strcmp(char *s1, char *s2){
	int i = 0;
	int j = 0;
	while(s1[i] != '\0'){
		if (s1[i] != s2[i]){
			return (s1[i] - s2[i]);	
		}
		i++;
	}
	return (i);
}
