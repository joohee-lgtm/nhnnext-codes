#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid;
	printf("Hi~\n");
	pid=fork();
	sleep(1);
	// 1초간 블록 상태
	printf("pid=%d\n",pid);
	printf("bye,%d\n",pid);
	return 0;
}
