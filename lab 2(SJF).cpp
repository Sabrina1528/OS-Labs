#include &lt;stdio.h&gt;
#include &lt;stdbool.h&gt;
struct Process {
int id, at, bt, ct, wt, tat; // Process attributes
bool completed; // To mark if the process is completed
};
void sortByArrival(struct Process p[], int n) {
int i, j;
for (i = 0; i &lt; n - 1; i++) {
for (j = 0; j &lt; n - i - 1; j++) {
if (p[j].at &gt; p[j + 1].at) {
struct Process temp = p[j];
p[j] = p[j + 1];
p[j + 1] = temp;
}
}
}
}
int main() {
int n, i, completedCount = 0, currentTime = 0;

float totalWT = 0, totalTAT = 0;
struct Process p[20];
printf(&quot;Enter the number of processes: &quot;);
scanf(&quot;%d&quot;, &amp;n);
for (i = 0; i &lt; n; i++) {
p[i].id = i + 1;
printf(&quot;Enter Arrival Time for Process %d: &quot;, i + 1);
scanf(&quot;%d&quot;, &amp;p[i].at);
printf(&quot;Enter Execution Time (Burst Time) for Process %d: &quot;, i + 1);
scanf(&quot;%d&quot;, &amp;p[i].bt);
p[i].completed = false; // Mark as incomplete
}
// Sort processes by Arrival Time
sortByArrival(p, n);
while (completedCount &lt; n) {
int shortestIndex = -1;
int minBurstTime = 9999;
// Find the shortest process that has arrived
for (i = 0; i &lt; n; i++) {
if (!p[i].completed &amp;&amp; p[i].at &lt;= currentTime &amp;&amp; p[i].bt &lt; minBurstTime)
{
minBurstTime = p[i].bt;
shortestIndex = i;
}
}
if (shortestIndex != -1) {
// Process the shortest job
currentTime += p[shortestIndex].bt;
p[shortestIndex].ct = currentTime; // Completion Time
p[shortestIndex].tat = p[shortestIndex].ct - p[shortestIndex].at; //
Turnaround Time
p[shortestIndex].wt = p[shortestIndex].tat - p[shortestIndex].bt; //
Waiting Time
p[shortestIndex].completed = true;
totalWT += p[shortestIndex].wt;
totalTAT += p[shortestIndex].tat;
completedCount++;

} else {
// If no process is ready, increment the current time
currentTime++;
}
}
// Display Results
printf(&quot;\nPROCESS\tARRIVAL TIME\tEXECUTION TIME\tCOMPLETION
TIME\tWAITING TIME\tTURNAROUND TIME\n&quot;);
for (i = 0; i &lt; n; i++) {
printf(&quot;P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n&quot;,
p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
}
printf(&quot;\nAverage Waiting Time: %.2f&quot;, totalWT / n);
printf(&quot;\nAverage Turnaround Time: %.2f\n&quot;, totalTAT / n);
return 0;
}
