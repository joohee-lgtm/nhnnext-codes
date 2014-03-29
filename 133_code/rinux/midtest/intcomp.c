#include "test.h"

int intcomp(const void *num1, const void *num2){
	int n1, n2;
	n1 = *(int*)num1;
	n2 = *(int*)num2;
	return n1-n2;
}
