#include <stdio.h>
#include <stdlib.h>

void my_int_sort(int *array, int length);   
void print_array(int *array, int length);
void intcomp(const void *num1, const void *num2);


void print_array(int *array, int length){
	int i;
	for (i=0; i< length; i++){
		printf("%d\t",array[i]);
	}
	printf("\n");
}
