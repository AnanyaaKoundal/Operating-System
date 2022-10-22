#include <stdlib.h>
#include <stdio.h>
int main(){
	int arrive[10], burst[20],rt[20],wait[20],turn[20], pr[20],i,j,n;
	int time, sum_wait=0, sum_turn=0, smallest, remain;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	remain=n;
	for(i=0; i<n; i++){
		printf("\tEProcess %d : \n", i+1);
		printf("\tEnter the arrive time : ");
		scanf("%d", &arrive[i]);
		printf("\tEnter the burst time : ");
		scanf("%d", &burst[i]);
		printf("\tEnter the priority : ");
		scanf("%d", &pr[i]);
		rt[i]=burst[i];
	}
	pr[9]=11;
	printf("\n\nProcess \t|Waiting Time \t|Turn Around Time\n");
	for(time=0;remain!=0;time++)
	{
		smallest=9;
		for(i=0;i<n;i++){
			if(arrive[i]<=time && pr[i]<pr[smallest] && rt[i]>0){
				smallest=i;
			}
		}
		rt[smallest]--;
		if(rt[smallest]==0)
		{
			remain--;
			printf("%d \t\t   %d  \t\t   %d\n", smallest+1,time+1-arrive[smallest]-burst[smallest], time+1-arrive[smallest]);
			sum_turn+=time+1-arrive[smallest];
			sum_wait+=time+1-arrive[smallest]-burst[smallest];
		}
	}
	printf("\nAverage Waiting Time: %f",  sum_wait*1.0/n);
	printf("\nAverage Turn Around Time: %f\n",sum_turn*1.0/n );
	
	return 0;
}
