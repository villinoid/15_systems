#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main() {
	srand(time(NULL));
	int f, status;
	printf("parent forking\nthe children are: ");
	fflush(stdout);
	f = fork();
	if (f){
		printf("%d ",f);
		fflush(stdout);
		f=fork();
	}
	if (f){
		printf("%d\n",f);
		int pid=wait(&status);
		printf("child exited pid: %d\ttime: %d\n",pid,WEXITSTATUS(status));
		printf("parent is done\n");
	}
	else{
		int t=rand()%8+2;
		sleep(t);

		return t;
	}
	return 0;
}