//Round Robin
#include <stdlib.h>
#include <stdio.h>
int tim=0;
int main(){
	int i, j, n, time, remain, flag=0, time_quantum;
	int wait_time=0, taround_time=0, arrive[10], burst[10], rt[10];
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	remain=n;
	for(i=0; i<n; i++){
		printf("Process %d :", i+1);
		printf("\tEnter the arrival time of process %d : ", i+1);
		scanf("%d", &arrive[i]);
		printf("\t\tEnter the burst time of process %d : ", i+1);
		scanf("%d", &burst[i]);
		rt[i]=burst[i];
	}
	printf("Enter the time quantum : ");
	scanf("%d", &time_quantum);
	printf("\n\nProcess \t|Waiting Time \t|Turn Around Time\n");
	for(time=0, i=0; remain!=0;){
		if(rt[i]<=time_quantum && rt[i]>0){
			time+=rt[i];
			rt[i]=0;
			flag=1;
		}else if(rt[i]>0){
			rt[i]-=time_quantum;
			time+=time_quantum;
		}
		if(rt[i]==0 && flag==1){
			remain--;
			printf("%d \t\t  %d  \t\t%d\n", i+1,time-arrive[i]-burst[i], time-arrive[i]);
			wait_time+=time-arrive[i]-burst[i];
			taround_time+=time-arrive[i];
			flag=0;
		}
		if(i==n-1)
			i=0;
		else if(arrive[i+1]<=time)
			i++;
		else
			i=0;
	}
	printf("\nAverage Waiting Time: %f", wait_time*1.0/n);
	printf("\nAverage Turn Around Time: %f\n", taround_time*1.0/n);
	
	return 0;
}
