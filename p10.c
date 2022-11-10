#include <stdlib.h>
#include <stdio.h>
int main(){
	int burst_time[10],arrival_time[10],p[10],rt[10],i,j,n,sum_wait=0;
	int sum_turnaround=0,smallest,time, remain;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	remain=n;
	for(i=0; i<n; i++){
		printf("\tEnter the burst time of process %d : ", i+1);
		scanf("%d", &arrival_time[i]);
		printf("\tEnter the burst time of process %d : ", i+1);
		scanf("%d", &burst_time[i]);
		printf("\tPriority: ");
		scanf("%d", &p[i]);
		rt[i]=burst_time[i];
	}
	p[9]=11;
	printf("\n\nProcess \t|Turnaround Time \t|Waiting Time\n");
	for(time=0; remain!=0; time++){
		smallest=9;
		for(i=0;i<n;i++){
			if(arrival_time[i]<=time && p[i]<p[smallest] && rt[i]>0){
				smallest=i;
			}
		}
		rt[smallest]--;
		if(rt[smallest]==0){
			remain--;
			printf("P[%d]\t\t%d\t\t%d\n",smallest+1,time+1-arrival_time[smallest],time+1-arrival_time[smallest]-burst_time[smallest]);
			sum_wait+=time+1-arrival_time[smallest];
			sum_turnaround+=time+1-arrival_time[smallest]-burst_time[smallest];
		}
	}
	printf("\nAverage Waiting Time: %f", sum_wait*1.0/n);
	printf("\nAverage Turn Around Time: %f\n", sum_turnaround*1.0/n);
	
	return 0;
}
