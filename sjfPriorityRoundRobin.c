#include <stdio.h>

// Function to calculate the turnaround time and waiting time using SJF (Non-preemptive) algorithm
void sjf_nonpreemptive(int processes[], int burst_time[], int n) {
    int waiting_time[n], turnaround_time[n], completion_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Sorting the processes based on burst time in ascending order using selection sort
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[min_idx])
                min_idx = j;
        }
        // Swapping the processes and burst time
        int temp = burst_time[i];
        burst_time[i] = burst_time[min_idx];
        burst_time[min_idx] = temp;

        temp = processes[i];
        processes[i] = processes[min_idx];
        processes[min_idx] = temp;
    }

    // Calculating completion time, waiting time, and turnaround time for each process
    for (int i = 0; i < n; i++) {
        if (i == 0)
            completion_time[i] = burst_time[i];
        else
            completion_time[i] = completion_time[i - 1] + burst_time[i];

        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Printing the process details and average waiting time and turnaround time
    printf("\nSJF (Non-preemptive) Scheduling Algorithm:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

// Function to calculate the turnaround time and waiting time using Priority (Non-preemptive) algorithm
void priority_nonpreemptive(int processes[], int burst_time[], int priority[], int n) {
    int waiting_time[n], turnaround_time[n], completion_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Sorting the processes based on priority in ascending order using selection sort
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (priority[j] < priority[min_idx])
                min_idx = j;
        }
        // Swapping the processes, burst time, and priority
        int temp = burst_time[i];
        burst_time[i] = burst_time[min_idx];
        burst_time[min_idx] = temp;

        temp = priority[i];
        priority[i] = priority[min_idx];
        priority[min_idx] = temp;

        temp = processes[i];
        processes[i] = processes[min_idx];
        processes[min_idx] = temp;
    }

    // Calculating completion time,
// Calculating completion time, waiting time, and turnaround time for each process
    for (int i = 0; i < n; i++) {
        if (i == 0)
            completion_time[i] = burst_time[i];
        else
            completion_time[i] = completion_time[i - 1] + burst_time[i];

        turnaround_time[i] = completion_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Printing the process details and average waiting time and turnaround time
    printf("\nPriority (Non-preemptive) Scheduling Algorithm:\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

// Function to calculate the turnaround time and waiting time using Round Robin algorithm
void round_robin(int processes[], int burst_time[], int n, int quantum) {
    int remaining_time[n], waiting_time[n], turnaround_time[n];
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Copying burst time into remaining time array
    for (int i = 0; i < n; i++)
        remaining_time[i] = burst_time[i];

    int time = 0; // Current time
    int flag = 0; // Flag to check if any process is remaining

    // Calculating waiting time and turnaround time for each process using Round Robin
    while (1) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                flag = 1;

                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                }
            }
        }

        if (flag == 0)
            break;
    }

    // Calculating turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Printing the process details and average waiting time and turnaround time
    printf("\nRound Robin Scheduling Algorithm (Quantum = %d):\n", quantum);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n, choice,quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_time[n];
    int priority[n];

    printf("\nEnter the burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        processes[i] = i + 1;
    }

    printf("\nSelect the scheduling algorithm:\n");
    printf("1. SJF (Non-preemptive)\n");
    printf("2. Priority (Non-preemptive)\n");
    printf("3. Round Robin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sjf_nonpreemptive(processes, burst_time, n);
            break;
        case 2:
            priority_nonpreemptive(processes, burst_time, priority, n);
            break;
        case 3:
            printf("Enter the time quantum for Round Robin: ");
            scanf("%d", &quantum);
            round_robin(processes, burst_time, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
