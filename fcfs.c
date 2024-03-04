#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int pid;
    int b_time;
    int w_time;
    int t_time;
} Process;

void print_table(Process p[], int n);
void print_gantt_chart(Process p[], int n);

int main()
{
    Process p[MAX];
    int i, j, n;
    int sum_w_time = 0, sum_t_time;
    printf("Enter total number of process: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("P[%d] : ", i+1);
        scanf("%d", &p[i].b_time);
        p[i].w_time = p[i].t_time = 0;
    }


    p[0].t_time = p[0].b_time;

    for(i=1; i<n; i++) {
        p[i].w_time = p[i-1].w_time + p[i-1].b_time;
        p[i].t_time = p[i].w_time + p[i].b_time;
    }

    for(i=0; i<n; i++) {
            sum_w_time += p[i].w_time;
            sum_t_time += p[i].t_time;
    }

    // print table
    puts(""); // Empty line
    print_table(p, n);
    puts(""); // Empty Line
    printf("Total Waiting Time      : %-2d\n", sum_w_time);
    printf("Average Waiting Time    : %-2.2lf\n", (double)sum_w_time / (double) n);
    printf("Total Turnaround Time   : %-2d\n", sum_t_time);
    printf("Average Turnaround Time : %-2.2lf\n", (double)sum_t_time / (double) n);

    // print Gantt chart
    puts(""); // Empty line
    puts("          GANTT CHART          ");
    puts("          ***********          ");
    print_gantt_chart(p, n);
    return 0;
}


void print_table(Process p[], int n)
{
    int i;

    puts("+*****+*************+*************+*****************+");
    puts("| PID | Burst Time | Waiting Time | Turnaround Time |");
    puts("+*****+************+**************+*****************+");

    for(i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].pid, p[i].b_time, p[i].w_time, p[i].t_time );
        puts("+-----+------------+--------------+-----------------+");
    }

}

void print_gantt_chart(Process p[], int n)
{
    int i, j;
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b_time - 1; j++) printf(" ");
        printf("P%d", p[i].pid);
        for(j=0; j<p[i].b_time - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].b_time; j++) printf("  ");
        if(p[i].t_time > 9) printf("\b");
        printf("%d", p[i].t_time);

    }
    printf("\n");
    getch();
}
