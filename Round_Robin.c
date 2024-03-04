#include<stdio.h>
int t[900];
int main()
{

  int count,j,n,time,remain,flag=0,time_quantum,time_temp,i,ki;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
  char tem[20], ans[9999];
  char a[9],v[1];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);
    scanf("%d",&at[count]);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  time_temp=0;
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      time_temp+=rt[count];
      rt[count]=0;
      flag=1;
      t[time_temp]=count+1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
      time_temp+=time_quantum;
      t[time_temp]=count+1;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;

  }
  printf("\nGannt Chart\n");

    strcpy(v,"|");
    strcpy(ans,"|");

     for(i=0;i<=time;i++)
     {

        int temp=t[i];
        if(t[i]!=0){
            strcpy(tem,"P");
            ki=t[i];
            strcat(tem,itoa(ki,a,10));
            strcat(tem,"(");
            ki=i;
            strcat(tem,itoa(ki,a,10));
            strcat(tem,")");
            strcat(tem,"|");
            strcat(ans,tem);
        }
        else
            strcat(ans," ");
     }
     printf("\n");
     for(i=0;i<strlen(ans);i++){
         if(ans[i]==v[0])
            printf(" ");
         else
            printf("_");
     }
     printf("\n");
     printf("%s",ans);
     printf("\n");
     for(i=0;i<strlen(ans);i++){
         if(ans[i]==v[0])
            printf(" ");
         else
            printf("_");
     }
     printf("\n");
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n);
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);

  return 0;
}
