//SRJF
#include <stdlib.h>
#include <stdio.h>
int main(){
	int i, j, n, small, temp, k, total=0;
	int wait[10], finish[10], burst[10], arrive[10], procs[100];
	float avw=0, avt=0;
	printf("\nEnter the number of processes: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		printf("\tEnter the arrival time of process %d : ", i+1);
		scanf("%d", &arrive[i]);
		printf("\tEnter the burst time of process %d : ", i+1);
		scanf("%d", &burst[i]);
		wait[i]=0;
		total+=burst[i];
	}
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(arrive[j]<arrive[i]){
				temp=arrive[i];
				arrive[i]=arrive[j];
				arrive[j]=temp;
				temp=burst[i];
				burst[i]=burst[j];
				burst[j]=temp;
		}
		}
	}
	for(i=0; i<total; i++){
		small=3200;
		for(j=0; j<n; j++){
			if((burst[j]!=0) && (arrive[j]<=i) && (burst[j]<small)){
				small=burst[j];
				k=j;
			}
		}
		burst[k]--;
		procs[i]=k;
	}
	k=0;
	for(i=0; i<total; i++){
		for(j=0; j<n; j++){
			if(procs[i]==j){
				finish[j]=i;
				wait[j]++;
			}
		}
	}
	printf("\n\nProcess \t|Finish Time \t|Waiting Time \t|Turn Around Time\n");
	for(i=0; i<n; i++){
		printf("%d \t\t   %d  \t\t   %d  \t\t   %d\n", i+1,finish[i]+1,((finish[i]+1)-wait[i])-arrive[i], (finish[i]-arrive[i])+1);
		avw=avw+(((finish[i]+1)-wait[i])-arrive[i]);
		avt=avt+(finish[i]-arrive[i]+1);
	}
	printf("\nAverage Waiting Time: %f", avw/n );
	printf("\nAverage Turn Around Time: %f\n", avt/n );
	
	return 0;
}
