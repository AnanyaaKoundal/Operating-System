#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
float avg_wt,avg_tat;
cout<<"\nEnter Total Number of Process:";
cin>>n;
cout<<"\nEnter Burst Time and Priority:\n";
for(i=0;i<n;i++)
{
cout<<"\nProcess "<<i+1<<"-> ";
cout<<"Burst Time: ";
cin>>bt[i];
cout<<"Priority: ";
cin>>pr[i];
p[i]=i+1; 
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(pr[j]<pr[pos])
pos=j;
}
temp=pr[i];
pr[i]=pr[pos];
pr[pos]=temp;
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0; 
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}
avg_wt=(float)total/n; 
total=0;
cout<<"\nProcess\t Burst Time \tWaiting Time\tTurn Around Time";
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
cout<<"\n  P:"<<p[i]<<"\t\t  "<<bt[i]<<"\t\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i];
}
avg_tat=(float)total/n; 
cout<<"\n\nAverage Waiting Time: "<<avg_wt;
cout<<"\nAverage Turnaround Time: "<<avg_tat<<endl;
return 0;
}
