#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	printf("\nThe kernel version is :\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\nConfigured, free and used memory is: \n");
	system("cat /proc/meminfo | awk 'NR==1, NR==2 {print}'");
	return 0;
}
