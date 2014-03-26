#include <stdio.h>
#include <stdlib.h>

void my_int_sort(int *array, int length);
void print_array(int *array, int length);
void intcomp(const void *num1, const void *num2);
void qsort(void *base, size_t nmemb, size_t size, 
		int (*compar)(const void *, const void *));

void my_int_sort(int *array, int length){
	qsort(array, sizeof(int), intcomp);
}

