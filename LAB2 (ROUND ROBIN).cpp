#include <stdio.h>
struct Process {
int id, at, bt, ct, wt, tat, remaining_bt;
};
int main() {
int n, i, time = 0, completed = 0, tq;
float totalWT = 0, totalTAT = 0;
struct Process p[20];
printf("Enter the number of processes: ");
scanf("%d", &n);
for (i = 0; i < n; i++) {
p[i].id = i + 1;
printf("Enter Arrival Time for Process %d: ", i + 1);
scanf("%d", &p[i].at);
printf("Enter Burst Time for Process %d: ", i + 1);
scanf("%d", &p[i].bt);
p[i].remaining_bt = p[i].bt; // Initialize remaining burst time
}
printf("Enter Time Quantum: ");
scanf("%d", &tq);
// Sort processes by Arrival Time
for (i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (p[j].at > p[j + 1].at) {
struct Process temp = p[j];
p[j] = p[j + 1];

p[j + 1] = temp;
}
}
}
int queue[20], front = 0, rear = 0; // Queue for process execution
int visited[20] = {0}; // Keep track of visited processes
queue[rear++] = 0; // Start with the first process
visited[0] = 1;
while (completed < n) {
int current = queue[front++];
// Process the current process
if (time < p[current].at) {
time = p[current].at; // Idle time
}
if (p[current].remaining_bt <= tq) {
time += p[current].remaining_bt;
p[current].remaining_bt = 0;
p[current].ct = time; // Completion time
p[current].tat = p[current].ct - p[current].at; // Turnaround Time
p[current].wt = p[current].tat - p[current].bt; // Waiting Time
totalWT += p[current].wt;
totalTAT += p[current].tat;
completed++;
} else {
time += tq;
p[current].remaining_bt -= tq;
}
// Add processes that arrived during execution of current process to the queue
for (i = 0; i < n; i++) {
if (i != current && !visited[i] && p[i].at <= time && p[i].remaining_bt > 0) {
queue[rear++] = i;
visited[i] = 1;
}
}

// Requeue the current process if it is not yet complete
if (p[current].remaining_bt > 0) {
queue[rear++] = current;
}
}
// Display Results
printf("\nPROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION
TIME\tWAITING TIME\tTURNAROUND TIME\n");
for (i = 0; i < n; i++) {
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
}
printf("\nAverage Waiting Time: %.2f", totalWT / n);
printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
return 0;
}
