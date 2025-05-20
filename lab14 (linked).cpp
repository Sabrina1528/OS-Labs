#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], p, i, j, a, st, len, n, c, k;

    // Initialize all disk blocks to free
    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers that are already allocated:\n");
    for(i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }

    do {
        printf("\nEnter the starting index block and length: ");
        scanf("%d%d", &st, &len);

        k = len;

        for(j = st; j < (st + k); j++) {
            if(f[j] == 0) {
                f[j] = 1;
                printf("%d -> Allocated\n", j);
            } else {
                printf("%d -> File is already allocated\n", j);
                k++; // Extend range to allocate full length
            }
        }

        printf("Do you want to enter another file? (Yes-1 / No-0): ");
        scanf("%d", &c);
    } while(c == 1);

    return 0;
}

