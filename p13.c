#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

void input(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void display(int a[],int n)
{
	int i;
	printf("\n\n");
	for(i=0;i<n;i++)
		printf("\t%d ",a[i]);
}
void sort(int a[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void reverse_sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(a[j]<a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void first_fit(int process[],int np,int holes[],int nm)
{
	int i,j,in_fr,ex_fr,flag[30]={0};
	in_fr=ex_fr=0;
	for(i=0;i<np;i++){
		for(j=0;j<nm;j++){
			if(flag[j]==0 && holes[j]>=process[i]) 
			{
				flag[j]=1;
				in_fr=in_fr+holes[j]-process[i];
				break;
			}
		}
		if(j==nm)
			printf("\n\nInsufficient space for process %d ",i);
	}
	for(i=0;i<nm;i++){
		if(flag[i]==0)
		ex_fr=ex_fr+holes[i];
	}
	printf("\n\nProcess:");
	display(process,np);
	printf("\n\nMemory Holes:");
	display(holes,nm);
	printf("\n\nTotal Internal Fragmentation: %d ",in_fr);
	printf("\n\nTotal External Fragmentation: %d ",ex_fr);
}
void best_fit(int process[],int np,int holes[],int nm)
{
	int i,j,in_fr,ex_fr,temp[30],flag[30]={0};
	in_fr=ex_fr=0;
	for(i=0;i<nm;i++)
		temp[i]=holes[i];
	sort(temp,nm);
	for(i=0;i<np;i++){
		for(j=0;j<nm;j++){
			if(flag[j]==0 && temp[j]>=process[i]){
				flag[j]=1;
				in_fr=in_fr+temp[j]-process[i];
				break;
			}
		}
		if(j==nm)
		printf("\n\nInsufficient space for process %d ",i);
	}
	for(i=0;i<nm;i++){
		if(flag[i]==0)
			ex_fr=ex_fr+temp[i];
	}
	printf("\n\nProcess:");
	display(process,np);
	printf("\n\nMemory Holes:");
	display(temp,nm);
	printf("\n\nTotal Internal Fragmentation: %d ",in_fr);
	printf("\n\nTotal External Fragmentation: %d ",ex_fr);
}

void worst_fit(int process[],int np,int holes[],int nm)
{
	int i,j,in_fr,ex_fr,temp[30],flag[30]={0};
	in_fr=ex_fr=0;
	for(i=0;i<nm;i++)
		temp[i]=holes[i];
	reverse_sort(temp,nm);
	for(i=0;i<np;i++){
		for(j=0;j<nm;j++){
			if(flag[j]==0 && temp[j]>=process[i]){
				flag[j]=1;
				in_fr=in_fr+temp[j]-process[i];
				break;
			}
		}
	if(j==nm) 
		printf("\n\nInsufficient space for process %d ",i);
	}
	for(i=0;i<nm;i++){
		if(flag[i]==0)
			ex_fr=ex_fr+temp[i];
	}
	printf("\n\nProcess:");
	display(process,np);
	printf("\n\nMemory Holes:");
	display(temp,nm);
	printf("\n\nTotal Internal Fragmentation: %d ",in_fr);
	printf("\n\nTotal External Fragmentation: %d ",ex_fr);
}

void menu(){
	printf("\n\n\tMEMORY MANAGEMENT");
	printf("\n\n\t1.Fisrt Fit");
	printf("\n\n\t2.Best Fit");
	printf("\n\n\t3.Worst Fit");
	printf("\n\n\t4.Exit");
}

void main()
{
	int ch,np,nm,process[30],holes[30];
	printf("\nEnter number of process:");
	scanf("%d",&np);
	printf("Enter sizes of process:");
	input(process,np);
	printf("\nEnter number of memory holes:");
	scanf("%d",&nm);
	printf("Enter sizes of memory holes:");
	input(holes,nm);
	while(1)
	{
		menu();
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\tFirst Fit:\n");
			first_fit(process,np,holes,nm);
			break;
			case 2:
			printf("\tBest Fit:\n");
			best_fit(process,np,holes,nm);
			break;
			case 3:
			printf("\tWorst Fit:\n");
			worst_fit(process,np,holes,nm);
			break;
			case 4:
			exit(0);
			default:
			printf("\n\nInvalid Choice!!");
		}
	}
}
