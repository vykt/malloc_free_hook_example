#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

//magic
#include <dlfcn.h>


static void * (*real_malloc)(size_t size) = NULL;
static void (*real_free)(void *) = NULL;


void * malloc_list[1024] = {0};
size_t malloc_size_list[1024] = {0};
int next = 0;


void * malloc(size_t size) {

	
	malloc_size_list[next] = size;
	malloc_list[next] = real_malloc(size);
	next = next + 1;

	return malloc_list[next - 1];
}


void free(void * heap_ptr) {
	
	//find match
	for (int i = 0; i < next; ++i) {
		if (malloc_list[i] == heap_ptr) {
			//print contents
			for (int j = 0; j < malloc_size_list[i]; ++j) {
				putchar((int) *((int *) (heap_ptr+j)));
			}
			putchar('\n');
			break;
		}
	}

	//puts(heap_ptr);
	return real_free(heap_ptr);
}


__attribute__((constructor)) static void setup(void) {

	real_malloc = dlsym(RTLD_NEXT, "malloc");
	if (real_malloc==NULL) printf("malloc()  dlsym failed.\n");
	real_free = dlsym(RTLD_NEXT, "free");
	if (real_free==NULL) printf("free() dlsym failed.\n");
}
