#include <stdio.h>
#include <conio.h>

int main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25];
    int n, f, pf = 0, next = 1;



    printf("Enter the length of reference string -- ");
    scanf("%d", &n);

    printf("Enter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1;
    }

    printf("\nThe Page Replacement process is --\n");

    for (i = 0; i < n; i++) {
        // Check if the page is already in memory
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1;        // Page hit
                count[j] = next++;  // Update usage time
            }
        }

        // If page fault
        if (flag[i] == 0) {
            if (i < f) {
                m[i] = rs[i];
                count[i] = next++;
            } else {
                // Find least recently used page
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j])
                        min = j;
                }
                m[min] = rs[i];
                count[min] = next++;
            }
            pf++; // Increment page faults
        }

        // Print memory state
        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);

        if (flag[i] == 0)
            printf("PF No. -- %d", pf);

        printf("\n");
    }

    printf("\nThe number of page faults using LRU are %d", pf);
    getch();
}

