// Write a C program to simulate disk scheduling algorithms
// a)  FCFS

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,head;
printf("First come first serve\n");
printf("Enter the number of request(n):");
scanf("%d",&n);
int i,rs[n];
printf("Enter request sequence one by one\n");
for( i=0;i<n;i++){
scanf("%d",&rs[i]);
}
printf("Enter initial head position(p):");
scanf("%d",&head);
int sum=0;
sum=abs(head-rs[0]);

for(int j=1;j<n;j++){
    sum=sum+abs(rs[j]-rs[j-1]);
}

printf("Total seek operation:%d",sum);
return 0;
}
// Write a C program to simulate disk scheduling algorithms
// c)SCAN
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head;
    char direction;
    int sum = 0;

    printf("SCAN\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);

    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("Enter initial head position (p):");
    scanf("%d", &head);

    printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

    if (direction == 'l')
    {
        sum = head + rs[n - 2];
        printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
        sum = abs(rs[n - 1] - head) + abs(rs[n - 1] - rs[1]);
        printf("Total Seek Time: %d\n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
    return 0;
}
// Write a C program to simulate disk scheduling algorithms
//b)SSTF
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Shortest Seek Time First\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);

    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter initial head position (p):");
    scanf("%d", &head);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int sum = 0;
    int current = head;

    for (int i = 0; i < n; i++) {
        int minDiff = 1e9;
        int index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int diff = abs(current - rs[j]);
                if (diff < minDiff) {
                    minDiff = diff;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        sum += minDiff;
        current = rs[index];
    }

    printf("Total Seek Time: %d\n", sum);

    return 0;
}
// Write a C program to simulate disk scheduling algorithms
// c)LOOK
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head;
    char direction;
    int sum = 0;

    printf("SCAN\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);

    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("Enter initial head position (p):");
    scanf("%d", &head);

    printf("Enter the direction(l or r)");
    scanf(" %c", &direction);

    if (direction == 'l')
    {
        sum = abs(head-rs[1]) + abs(rs[1]-rs[n - 2]);
        printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
        sum = abs(rs[n - 2] - head) + abs(rs[n - 2] - rs[1]);
        printf("Total Seek Time: %d\n", sum);
    }

    else
    {
        printf("invalid input try l or r");
    }
    return 0;
}
// Write a C program to simulate disk scheduling algorithms
//C scan
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head;
    char direction;
    int sum = 0;
    int i,back,forward;

    printf("C-SCAN\n");
    printf("Enter the number of requests (n):");
    scanf("%d", &n);

    int rs[n];
    printf("Enter request sequence one by one (in ascending)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
    }

    printf("Enter initial head position (p):");
    scanf("%d", &head);

    printf("Enter the direction(l or r)");
    scanf(" %c", &direction);



    if (direction == 'l')
    { for(i=n;i>=0;i--){
        if(rs[i]>head){
        forward=i;
    }
      }
      sum=head+abs(rs[n-1]-rs[forward]);
      printf("Total Seek Time: %d\n", sum);
    }

    else if (direction == 'r')
    {
        for(i=1;i<=n;i++){
        if(rs[i]<head){
         back=i;
                    }
       }
         sum=abs(rs[n-1]-head)+rs[back];
         printf("Total Seek Time: %d\n", sum);
    }

    else
    {

        printf("invalid input try l or r");
    }
    return 0;
}
