#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	pid_t pid, p;
	p=fork();
	pid=getpid();
	if(p<0){
		fprintf(stderr, "fork failed");
		return 1;
	}
	printf("Fork id is: %d\n",p);
	printf("Process id is: %d\n",pid);
	return 0;
}
