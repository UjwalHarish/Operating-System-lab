#include<stdio.h>

 int main()

{
    int n,bt[30],at[30],bts[30]={0},wait_t[30],turn_ar_t[30],av_wt_t=0,avturn_ar_t=0,i,j;
    printf("Please enter the total number of processes(maximum 30):");  // the maximum process that be used to calculate is specified.
    scanf("%d",&n);

    printf("\nEnter The Process Burst Time");
    for(i=0;i<n;i++)  // burst time for every process will be taken as input
    {
        printf("P[%d]:",i);
        scanf("%d",&bt[i]);
    }
     printf("\nEnter The Arrival Time");
    for(i=0;i<n;i++)  // burst time for every process will be taken as input
    {
        printf("AT[%d]:",i);
        scanf("%d",&at[i]);
    }
    for(i=0;i<n;i++)
    {

        for(j=0;j<=i;j++){
            bts[i] += bt[j];
        }

    }
    for(i=0;i<n;i++){
        printf("%d ",bts[i]);
    }
    int tat[30];
    for(i=0;i<n;i++){
        tat[i] = bts[i] - at[i];
    }
    float tat_avg = 0;
    for(i=0;i<n;i++){
        tat_avg += tat[i];
    }
    tat_avg = tat_avg/n;
    printf("\n%f",tat_avg);
    int awt[30];
    for(i=0;i<n;i++){
        awt[i] = tat[i] - bt[i];
    }
    float awt_avg=0;
    for(i=0;i<n;i++){
        awt_avg+= awt[i];
    }
    awt_avg = awt_avg/n;
    printf("\n%f",awt_avg);


}
