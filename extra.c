#include <stdlib.h>
#include <stdio.h>
int tim=0;
int main(){
	int v, b[20], i,j, w[20], tw=0, taround[20], tt=0, n;
	float avw, avt;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		printf("Enter the burst time of process %d : ", i);
		scanf("%d", &b[i]);
	}
	for(i=1; i<=n; i++){
		w[i]=tim;
		for(j=1; j<=b[i]; j++){
			tim++;
			if(j==b[i]){
				taround[i]=tim;
			}
		}
	}
	for(i=1; i<=n; i++){
		tw+=w[i];
	}
	for(i=1; i<=n; i++){
		tt+=taround[i];
	}
	avw=(float)tw/n;
	avt=(float)tt/n;
	for(i=1; i<=n; i++){
		printf("\nProcess %d:\tWaiting Time= %d\t\tTurnaround Time= %d", i, w[i], taround[i]);
	}
	printf("\nAverage Waiting Time: %f", avw);
	printf("\nAverage Turnaround Time: %f\n", avt);
	
	return 0;
}
  
