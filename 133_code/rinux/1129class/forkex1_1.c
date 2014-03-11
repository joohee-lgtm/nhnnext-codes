#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid;
	pid = getpid();
	printf("Hi,%d~\n",pid);
	pid=fork();
	printf("1.pid=%d\n",pid);
	pid=fork();
	printf("2.pid=%d\n",pid);
	pid=fork();
	printf("3.pid=%d\n",pid);
	sleep(1);
	return 0;
}
