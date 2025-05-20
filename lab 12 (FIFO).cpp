#include <stdio.h>
#include <conio.h>

int main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

   

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1;  // Initialize all frames to -1 (empty)

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) // Page hit
                break;
        }

        if (k == f) {  // Page not found, i.e., Page Fault
            m[count++] = rs[i];
            pf++;
        }

        // Display current state of memory
        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);

        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");

        if (count == f)  // Reset counter for FIFO
            count = 0;
    }

    printf("\nTotal number of Page Faults using FIFO: %d", pf);

    getch();
}

