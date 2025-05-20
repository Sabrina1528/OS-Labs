#include <stdio.h>
int main() {
int n, r, i, j, k;
int alloc[10][10], max[10][10], avail[10];
int finish[10], need[10][10], dead[10];
int flag = 0, c = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter number of resources: ");
scanf("%d", &r);
printf("Enter allocation matrix:\n");
for(i = 0; i < n; i++)
for(j = 0; j < r; j++)
scanf("%d", &alloc[i][j]);
printf("Enter maximum matrix:\n");
for(i = 0; i < n; i++)
for(j = 0; j < r; j++)
scanf("%d", &max[i][j]);
printf("Enter available resources:\n");
for(i = 0; i < r; i++)
scanf("%d", &avail[i]);
for(i = 0; i < n; i++)
for(j = 0; j < r; j++)
need[i][j] = max[i][j] - alloc[i][j];
for(i = 0; i < n; i++)
finish[i] = 0;
for(k = 0; k < n; k++) {
for(i = 0; i < n; i++) {
if(finish[i] == 0) {
c = 0;
for(j = 0; j < r; j++) {
if(need[i][j] <= avail[j])
c++;
}
if(c == r) {
for(j = 0; j < r; j++)
avail[j] += alloc[i][j];
finish[i] = 1;
flag = 1;
}
}
}
}
flag = 0;
j = 0;
for(i = 0; i < n; i++) {
if(finish[i] == 0) {
dead[j] = i;
j++;
flag = 1;
}
}
if(flag == 1) {
printf("\n\nSystem is in Deadlock and the Deadlocked processes are:\n");
for(i = 0; i < j; i++)
printf("P%d\t", dead[i]);
printf("\n");
} else {
printf("\nNo Deadlock detected. System is in safe state.\n");
}
return 0;
}
