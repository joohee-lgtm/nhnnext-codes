#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int arr[10]={10,22,55,33,44,77,434,213, };
	printf("before: \n");
	print_array(arr,10);
	my_int_sort(arr, 10);
	printf("after:\n");
	print_array(arr,10);
	return 0;
}
