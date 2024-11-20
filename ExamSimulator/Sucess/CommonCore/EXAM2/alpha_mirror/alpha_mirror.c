#include <unistd.h>

int main(int argc, char **argv){
	int i = 0;
	int count = 0;
	char c;
	char *ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *abc = "abcdefghijklmnopqrstuvwxyz";
	if(argc == 2){
		while(argv[1][i] != '\0'){
			if((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z')){
				if(argv[1][i] >= 'A' && argv[1][i] <= 'Z'){
					count = 0;
					while(ABC[count] != argv[1][i]){
						count++;
					}
					c = 'Z' - count;
					write(1, &c, 1);
				}else if(argv[1][i] >= 'a' && argv[1][i] <= 'z'){
					count = 0;
					while(abc[count] != argv[1][i]){
						count++;
					}
					c = 'z' - count;
					write(1, &c, 1);
				}
			}else{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
