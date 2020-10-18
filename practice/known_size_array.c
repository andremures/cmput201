#include <stdio.h>
#include <stdlib.h>

const int BUFFER = 128;

int main(void) {
	
	int size = 4;

	char** str_array = (char**)malloc(sizeof(char*) * size);
	str_array[0] = "54 32 11";
	str_array[1] = "11 11 11";
	str_array[2] = "11 11 11";
	str_array[3] = "11 11 11";

	for(int i = 0; i < size; i++) {
		printf("%s\n", str_array[i]);
	}
	
	free(str_array);

	return 0;
}
