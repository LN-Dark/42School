#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	int n = 0;
	int a;
	int b;
	
	if(argc == 3){
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		n = a;
		while(n > 0){
			if(a % n == 0 && b % n == 0){
				printf("%d", n);
				break;
			}
			n--;
		}	
	}
	printf("\n");
	return (0);
}
