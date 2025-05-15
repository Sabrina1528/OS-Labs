#include &lt;stdio.h&gt;
struct Process {
int id, at, bt, ct, wt, tat;
};
void swap(struct Process *a, struct Process *b) {
struct Process temp = *a;
*a = *b;
*b = temp;
}
int main() {
int n, i, j, currentTime = 0;
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
}
// Sort processes by Arrival Time
for (i = 0; i &lt; n - 1; i++) {
for (j = 0; j &lt; n - i - 1; j++) {

if (p[j].at &gt; p[j + 1].at) {
swap(&amp;p[j], &amp;p[j + 1]);
}
}
}
// Calculate Completion Time, Turnaround Time, and Waiting Time
for (i = 0; i &lt; n; i++) {
if (currentTime &lt; p[i].at) {
currentTime = p[i].at; // Idle time if process arrives later
}
p[i].ct = currentTime + p[i].bt; // Completion Time
currentTime = p[i].ct;
p[i].tat = p[i].ct - p[i].at; // Turnaround Time = CT - AT
p[i].wt = p[i].tat - p[i].bt; // Waiting Time = TAT - BT
totalWT += p[i].wt;
totalTAT += p[i].tat;
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
