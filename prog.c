#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char ** argv) {

	char * le_data = malloc(32);
	memcpy(le_data, "github appropriate string", 27);
	free(le_data);

	return 0;

}
