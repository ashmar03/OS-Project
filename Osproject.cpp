#include<iostream>
using namespace std;
int main()
{
	int i,j,c,n1,n2,at,bt,wt,tt=0;
	cout<<"Enter total no. of teacher processes: \n";
	cin>>n1;
	int t[n1][2];
	cout<<"Enter The Teacher Processes details in order of arrival: \n\n";
	for(i=0;i<n1;i++)
	{
		cout<<"Enter Arrival time for teacher process "<<(i+1)<<": ";
		cin>>t[i][0];
		cout<<"Enter Burst time for teacher process "<<(i+1)<<": ";
		cin>>t[i][1];
		cout<<"\n";
		if(i>0 && t[i-1][0]>t[i][0])//checks if the entered details are in order of arrival
		{
			cout<<"Please re-enter details the processes in order of arrival: \n\n";
			i=-1;
		}
	}
	cout<<"Enter total no. of student processes: \n";
	cin>>n2;
	cout<<"Enter max wait time for student process: \n";
	cin>>wt;
	int s[n2][2];
	cout<<"Enter The Student Processes details in order of arrival: \n\n";
	for(j=0;j<n2;j++)
	{
		cout<<"Enter Arrival time for student process "<<(j+1)<<": ";
		cin>>s[j][0];
		cout<<"Enter Burst time for student process "<<(j+1)<<": ";
		cin>>s[j][1];
		cout<<"\n";
		if(j>0 && s[j-1][0]>s[j][0])//checks if the entered details are in order of arrival
		{
			cout<<"Please re-enter details the processes in order of arrival: \n\n";
			j=-1;
		}
	}
	cout<<"The Entered details for teacher processes are: \n\n\t\t\tArrival Time\tBurst Time";
	for(i=0;i<n1;i++)
	{
		cout<<"\nTeacher Process "<<(i+1)<<": \t"<<t[i][0]<<"\t\t"<<t[i][1];
	}
	cout<<"\n\nThe Entered details for Student processes are: \n\n\t\t\tArrival Time\tBurst Time";
	for(j=0;j<n2;j++)
	{
		cout<<"\nStudent Process "<<(j+1)<<": \t"<<s[j][0]<<"\t\t"<<s[j][1];
	}
	i=0;
	j=0;
	cout<<"\n\nThe order of execution of processes is: \n";
	cout<<"\t\t\tWaiting Time\tTurnaround Time\n";
	tt=min(s[0][0],t[0][0]);
	while(i<n1 || j<n2)
	{
		if(i<n1 && (t[i][0]<=s[j][0] || t[i][0]<=tt))//checks the process to execute
		{
			if((j<n2 && (tt-s[j][0])>=wt) && tt-t[i][0]<wt)//checks if waiting time of student or teacher process is greater than given max time
			{
				cout<<"Student process "<<(j+1)<<"\t"<<(tt-s[j][0])<<"\t\t"<<(tt-s[j][0]+s[j][1])<<endl;
				tt+=s[j][1];
				j++;
			}
			else if(i<n1)//if no process exceeds max wait time, this will be execute
			{
				cout<<"Teacher process "<<(i+1)<<"\t"<<(tt-t[i][0])<<"\t\t"<<(tt-t[i][0]+t[i][1])<<endl;
				tt+=t[i][1];
				i++;
			}
			else
			continue;
		}
		else if(j<n2)
		{
			cout<<"Student process "<<(j+1)<<"\t"<<(tt-s[j][0])<<"\t\t"<<(tt-s[j][0]+s[j][1])<<endl;
			tt+=s[j][1];
			j++;
		}
		else
		continue;
	}
}
