//FCFS
#include <stdlib.h>
#include <stdio.h>
int tim=0;
int main(){
	int v, b[20], i,j, w[20], tw=0, taround[20], tt=0, n;
	float avw, avt;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("Enter the burst time of process %d : ", i+1);
		scanf("%d", &b[i]);
	}
	for(i=0; i<n; i++){
		w[i]=tim;
		for(j=1; j<=b[i]; j++){
			tim++;
			if(j==b[i]){
				taround[i]=tim;
			}
		}
	}
	for(i=0; i<n; i++){
		tw+=w[i];
		tt+=taround[i];
	}
	avw=(float)tw/n;
	avt=(float)tt/n;
	printf("\nProcess  \t|Waiting Time  \t|Turnaround");
	for(i=0; i<n; i++){
		printf("\n%d\t\t   %d\t\t   %d", i+1, w[i], taround[i]);
	}
	printf("\nAverage Waiting Time: %f", avw);
	printf("\nAverage Turnaround Time: %f\n", avt);
	
	return 0;
}
