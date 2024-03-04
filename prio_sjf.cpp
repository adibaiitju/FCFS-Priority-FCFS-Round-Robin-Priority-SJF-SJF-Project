#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_tat;
    double avg_wt;
    string ans;
    cout<<"Enter Total Number of Process:";
    cin>>n;

    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]\n";
        cout<<"Burst Time:";
        cin>>bt[i];
        cout<<"Priority:";
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
                else if(pr[j]<=pr[pos])
                {
                    if(bt[j]<bt[pos])
                        pos=j;
                }
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

    avg_wt=(total*.10)/(n*.10);
    total=0;

    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total+=tat[i];
        cout<<"\nP["<<p[i]<<"]\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }

    avg_tat=total/n;
    cout<<"\n\nAverage Waiting Time="<<avg_wt;
    cout<<"\nAverage Turnaround Time="<<avg_tat<<"\n";

    int tm=0;
    ans+="|";
    for(i=0;i<n;i++)
     {

     for(int q=0;q<bt[i];q++){
        ans+=" ";
     }
        tm+=bt[i];
        stringstream myString;
        myString<<" P"<<p[i]<<"("<<tm<<") |";
        string f=myString.str();
        ans+=f;
     }

     cout<<"\n";

     for(i=0;i<ans.size();i++){
        if(ans[i]=='|'){

            cout<<" ";
        }
        else
        cout<<"_";
     }
     cout<<"\n";
     cout<<ans;
     cout<<"\n";

     for(i=0;i<ans.size();i++){
        if(ans[i]=='|'){

            cout<<" ";
        }
        else
        cout<<"_";
     }
    return 0;
}

