#include <stdio.h>
#include <pthread.h>

#define MAX 50000000

void *func(void* data){
	double n,ret;
	ret=0;
	int i;
	for (i=0; i<MAX ; i++){
		n=(double)1/randome();
		ret+=n;
