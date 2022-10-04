#include <stdlib.h>
#include <stdio.h>
int tim=0;
int main(){
	int i, j, n, time, remain, flag=0, time_quantum;
	int wait_time=0, turnaround_time=0, at[10], bt[10], rt[10];
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	remain=n;
	for(i=1; i<=n; i++){
		printf("Process %d :", i);
		printf("\tEnter the arrival time of process %d : ", i);
		scanf("%d", &at[i]);
		printf("\t\tEnter the burst time of process %d : ", i);
		scanf("%d", &bt[i]);
		rt[i]=bt[i];
	}
	printf("Enter the time quantum : ");
	scanf("%d", &time_quantum);
	printf("\n\nProcess \t|Waiting Time \t|Turn Around Time\n");
	for(time=0, i=1; remain!=0;){
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
			printf("%d \t\t  %d  \t\t\t %d\n", i,time-at[i]-bt[i], time-at[i]);
			wait_time+=time-at[i]-bt[i];
			turnaround_time+=time-at[i];
			flag=0;
		}
		if(i==n)
			i=1;
		else if(at[i+1]<=time)
			i++;
		else
			i=1;
	}
	printf("\nAverage Waiting Time: %f", wait_time*1.0/n);
	printf("\nAverage Turn Around Time: %f\n", turnaround_time*1.0/n);
	
	return 0;
}
