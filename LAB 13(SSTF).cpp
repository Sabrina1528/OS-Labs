#include <stdio.h>
#include <stdlib.h>
int main() {
int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;
printf("Enter the number of Requests: ");
scanf("%d", &n);
printf("Enter the Request sequence:\n");
for (i = 0; i < n; i++)
scanf("%d", &RQ[i]);
printf("Enter initial head position: ");
scanf("%d", &initial);
// SSTF Disk Scheduling Logic
while (count != n) {
int min = 1000, d, index = -1;
for (i = 0; i < n; i++) {
d = abs(RQ[i] - initial);
if (RQ[i] != -1 && min > d) { // check if not already serviced
min = d;
index = i;
}
}
TotalHeadMovement += min;
initial = RQ[index];
RQ[index] = -1; // mark as serviced
count++;
}
printf("Total head movement is %d\n", TotalHeadMovement);
return 0;
}
