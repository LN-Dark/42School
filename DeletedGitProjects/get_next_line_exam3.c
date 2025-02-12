# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif








char *ft_strdup(char *str)
 {
	char *new_str;
	int i;
 
 	i = 0;
 	while(str[i] != '\0')
 		i++;
 	new_str = (char *)malloc(sizeof(char) * (i + 1));
 	if (!new_str)
 		return (NULL);
 	i = -1;
 	while (str[++i] != '\0')
 		new_str[i] = str[i];
 	new_str[i] = '\0';
 	return (new_str);
 }

 char *get_next_line(int fd)
 {
 	static char buffer[BUFFER_SIZE];
 	static int buffer_pos;
 	static int buffer_read;
 	char line[70000];
 	int i;
 
 	i = 0;
 	if (fd < 0 || BUFFER_SIZE <= 0)
 		return (NULL);
 	while (1)
 	{
 		if (buffer_pos >= buffer_read)
 		{
 			buffer_read = read(fd, buffer, BUFFER_SIZE);
 			buffer_pos = 0;
 			if (buffer_read <= 0)
 				break;
 		}
 		line[i++] = buffer[buffer_pos++];
 		if (buffer[buffer_pos - 1] == '\n')
		 	break ;
	}
 	line[i] = '\0';
 	if (i == 0)
 		return (NULL);
 	return (ft_strdup(line));
 }

int main(void)
{
	int fd = open("get_next_line_exam3", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != 0)
		printf("%s\n", line);
}
