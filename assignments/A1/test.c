#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	printf("PART ONE\n");
	printf("argv[0]: %s\n", argv[0]);
	printf("argv[1]: %s\n", argv[1]);
	printf("%d\n", argc);
	
	printf("PART TWO\n");
	if (argc != 2){
		printf("wrong number of argument\n");
	} else if (strcmp(argv[1], "r") == 0) {
		printf("argument 'r'\n");
	} else {
		printf("all good\n");
	}

	return 0;

}
