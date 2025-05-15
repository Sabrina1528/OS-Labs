#include <stdio.h>
#include <limits.h>
struct Process {
int id, at, bt, ct, wt, tat, priority, remaining_bt;
};
int main() {
int n, time = 0, completed = 0;
float totalWT = 0, totalTAT = 0;
struct Process p[20];
// Input the number of processes
printf("Enter the number of processes: ");
scanf("%d", &n);
// Input process details
for (int i = 0; i < n; i++) {
p[i].id = i + 1;
printf("Enter Arrival Time for Process %d: ", i + 1);
scanf("%d", &p[i].at);
printf("Enter Burst Time for Process %d: ", i + 1);
scanf("%d", &p[i].bt);
printf("Enter Priority for Process %d (lower number = higher priority): ", i
+ 1);
scanf("%d", &p[i].priority);
p[i].remaining_bt = p[i].bt; // Initialize remaining burst time
}
// Priority Scheduling Logic (Preemptive)
while (completed < n) {
int minPriority = INT_MAX, current = -1;
// Find the process with the highest priority that has arrived
for (int i = 0; i < n; i++) {
if (p[i].at <= time && p[i].remaining_bt > 0 && p[i].priority < minPriority)
{
minPriority = p[i].priority;
current = i;
}
}

if (current == -1) { // If no process is ready, increment time
time++;
continue;
}
// Execute the selected process for 1 unit of time
p[current].remaining_bt--;
time++;
// If the process is completed
if (p[current].remaining_bt == 0) {
p[current].ct = time; // Completion Time
p[current].tat = p[current].ct - p[current].at; // Turnaround Time
p[current].wt = p[current].tat - p[current].bt; // Waiting Time
totalWT += p[current].wt;
totalTAT += p[current].tat;
completed++;
}
}
// Display Results
printf("\nPROCESS\tARRIVAL TIME\tBURST
TIME\tPRIORITY\tCOMPLETION TIME\tWAITING TIME\tTURNAROUND
TIME\n");
for (int i = 0; i < n; i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
p[i].id, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].wt, p[i].tat);
}
// Print averages
printf("\nAverage Waiting Time: %.2f", totalWT / n);
printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
return 0;
}
