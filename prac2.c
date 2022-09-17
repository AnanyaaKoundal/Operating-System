#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	printf("\nThe kernel version is :\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\nThe CPU info is: \n");
	system("cat /proc/cpuinfo");
	return 0;
}
