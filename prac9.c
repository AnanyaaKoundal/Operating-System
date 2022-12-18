//Non pre emptive priority based scheduling
#include <stdlib.h>
#include <stdio.h>
int main(){
	int burst[20],p[20],wait[20],turn[20],pr[20],i,j,n, total=0,pos, temp;
	float avg_wt,avg_tat;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\tEnter the burst time of process %d : ", i+1);
		scanf("%d", &burst[i]);
		printf("\tEnter the priority of process %d : ", i+1);
		scanf("%d", &pr[i]);
		p[i]=i+1;
	}
	for(i=0; i<n; i++){
		pos=i;
		for(j=i+1; j<n; j++){
			if(pr[j]<pr[pos])
				pos=j;
		}
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
		temp=burst[i];
		burst[i]=burst[pos];
		burst[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wait[0]=0;
	for(i=1; i<n; i++){
		wait[i]=0;
		for(j=0; j<i; j++)
			wait[i]+=burst[j];
		total+=wait[i];
	}
	float avw=(float)total/n;
	total=0;
	printf("\n\nProcess \t|Burst Time \t|Waiting Time \t|Turn Around Time\n");
	for(i=0; i<n; i++){
		turn[i]=burst[i]+wait[i];
		total+=turn[i];
		printf("%d \t\t   %d  \t\t   %d  \t\t   %d\n", p[i],burst[i],wait[i], turn[i]);
	}
	float avt=(float)total/n;
	printf("\nAverage Waiting Time: %f", avw );
	printf("\nAverage Turn Around Time: %f\n", avt);
	
	return 0;
}
