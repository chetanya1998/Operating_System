#include<iostream>
using namespace std;
int main(){
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	cout<<"enter total number of processes(maximum 20)";
	cin>>n;
	cout<<"\nEnter Process burst Time\n";
	for(i=0;i<n;i++){
		cout<<"P["<<i+1<<"]:";
		cin>>bt[i];
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=0;
		
		for(j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}

	}

	cout<<"\nProcess\t\tBurst Time\t\t Waiting Time\t Turnaround Time";
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		cout<<"\nP["<<i+1<<"]"<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i];
	}
	avwt/=i;
	avtat/=i;
	cout<<"\n\n Average Waiting Time:"<<avwt;
	cout<<"\n\n Average Turnaround Time:"<<avtat;
    return 0;
}