#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<strings.h>

int main()
{
    int process_number,ki,arrival_time[10],burst_time[10],i,x[10],count=0,time,smallest,result[10],k=0,t[90];
    char tem[20], ans[9999];
    char a[9],v[1];
    double end=0,waiting_time=0,turn_around_time=0;

    printf("Enter the number of process\n");
      scanf("%d",&process_number);

    printf("Enter the arrival times\n");
      for(i=0;i<process_number;i++)
        scanf("%d",&arrival_time[i]);

    printf("Enter the burst times\n");
     for(i=0;i<process_number;i++)
        scanf("%d",&burst_time[i]);

    for(i=0;i<process_number;i++)x[i]=burst_time[i];
    burst_time[9]=9999;

    for(time=0;count!=process_number;time++)
    {
        smallest=9;
        for(i=0;i<process_number;i++)
        {
            if(arrival_time[i]<=time && burst_time[i]<burst_time[smallest] && burst_time[i]>0)
            smallest=i;
            t[time]=smallest;
        }
        burst_time[smallest]--;
        if(burst_time[smallest]==0)
        {
            result[k]=smallest;
            k++;
            count++;
            end=time+1;
            waiting_time+=end-arrival_time[smallest]-x[smallest];
            turn_around_time+=end-arrival_time[smallest];
        }

    }
    strcpy(v,"|");
    strcpy(ans,"|");

     for(i=0;i<time;i++)
     {

        int temp=t[i];
        if(t[i]!=t[i+1]){
            strcpy(tem," P");
            ki=t[i]+1;
            strcat(tem,itoa(ki,a,10));
            strcat(tem,"(");
            ki=i+1;
            strcat(tem,itoa(ki,a,10));
            strcat(tem,")");
            strcat(tem," |");
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

     printf("Average Waiting Time= %lf\n",waiting_time/process_number);
     printf("Average Turn Around Time= %lf\n",turn_around_time/process_number);

    return 0;
}

