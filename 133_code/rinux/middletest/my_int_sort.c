#include "test.h"


void my_int_sort(int *array, int length){
	qsort(array, sizeof(int), intcomp);
}


