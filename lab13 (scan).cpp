#include <stdio.h>
#include <stdlib.h>
int main() {
 int t[20], n, head, i, j, temp, pos, total = 0;
 int atr[20], p = 0, max = 199; // assuming disk size is 0 to 199
 float avg;
 printf("Enter the number of track requests: ");
 scanf("%d", &n);
 printf("Enter the track requests:\n");
 for (i = 0; i < n; i++) {
 scanf("%d", &t[i]);
 }
 printf("Enter the initial head position: ");
 scanf("%d", &head);
 // Add head to track list
 t[n] = head;
 n++;
 // Sort the track requests including the head
 for (i = 0; i < n - 1; i++) {
 for (j = 0; j < n - i - 1; j++) {
 if (t[j] > t[j + 1]) {
 temp = t[j];
 t[j] = t[j + 1];
 t[j + 1] = temp;
 }
 }
 }
 // Find the position of head after sorting
 for (i = 0; i < n; i++) {
 if (t[i] == head) {
 pos = i;
 break;
 }
 }
 // Traverse right from head to end
 for (i = pos; i < n; i++) {
 atr[p++] = t[i];
 }
 // Simulate jump to beginning
 atr[p++] = max;
 atr[p++] = 0;
 // Then traverse from start to before head
 for (i = 0; i < pos; i++) {
 atr[p++] = t[i];
 }
 // Calculate total head movements
 for (i = 0; i < p - 1; i++) {
 total += abs(atr[i + 1] - atr[i]);
 }
 avg = (float)total / (n - 1); // average over actual requests
 printf("\nC-SCAN Order of Service:\n");
 for (i = 0; i < p; i++) {
 printf("%d ", atr[i]);
 }
 printf("\n\nTotal head movement: %d", total);
 printf("\nAverage head movement: %.2f\n", avg);
 return 0;
}
