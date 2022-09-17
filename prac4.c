#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char *argv[3]){
	int i;;
	struct stat buffer;
	for(i=1; i<argc; i++){
		printf("Given file name=%s\n",argv[i]);
		if(stat(argv[i],&buffer)<0){
			printf("Error in file started");
		}else{
			printf("Owner: %d\ngid=%d\n", buffer.st_uid, buffer.st_gid);
			printf("Access Permission=%d\n", buffer.st_mode);
			printf("Access Time=%ld\n", (time(&(buffer.st_atime))));
		}
	}
	return 0;
}
