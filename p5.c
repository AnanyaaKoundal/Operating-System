#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void display(int f1){
	int i, count=0;
	char buffer[512];
	while((count=read(f1, buffer, sizeof(buffer)))>0){
		for(i=0; i<count; i++)
			printf("%c",buffer[i]);
	}
	for(i=0; i<count; i++)
	printf("%c",buffer[i]);
}
void copy(int f1,int f2){
	int count=0;
	char buffer[512];
	while((count=read(f1, buffer, sizeof(buffer)))>0){
		write(f2,buffer,count);
	}
}

void main(int argc, char *argv[]){
	int f1,  new;
	if(argc!=3){
		printf("Two arguments required");
		exit(1);
	}
	f1=open(argv[1],0);
	if(f1==-1){
		printf("Unable to to file %s", argv[1]);
		exit(1);
	}
	new=open(argv[2],0666);
	if(new==-1){
		printf("Unable to to file %s", argv[1]);
		exit(1);
	}
	copy(f1,new);
	close(f1);
	close(new);
	new=open(argv[2],0);
	printf("\nNew File Created:\n");
	display(new);
	close(new);
	exit(0);
}
