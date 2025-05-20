#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[50], i, k, j, indexBlock[50], n, c, p;

    // Initialize all blocks as free
    for(i = 0; i < 50; i++)
        f[i] = 0;

    do {
        printf("Enter index block: ");
        scanf("%d", &p);

        if(f[p] == 0) {
            f[p] = 1;
            printf("Enter number of blocks for the file: ");
            scanf("%d", &n);
        } else {
            printf("Block already allocated!\n");
            continue;
        }

        printf("Enter the blocks to be indexed:\n");
        for(i = 0; i < n; i++)
            scanf("%d", &indexBlock[i]);

        // Check if any of the blocks are already allocated
        for(i = 0; i < n; i++) {
            if(f[indexBlock[i]] == 1) {
                printf("Block %d is already allocated!\n", indexBlock[i]);
                f[p] = 0; // deallocate index block
                for(j = 0; j < i; j++)
                    f[indexBlock[j]] = 0;
                goto skip;
            }
        }

        // Allocate the blocks
        for(i = 0; i < n; i++)
            f[indexBlock[i]] = 1;

        printf("\nAllocated successfully.\n");
        printf("File indexed. Mapping:\n");
        for(i = 0; i < n; i++)
            printf(" %d -> %d\n", p, indexBlock[i]);

        skip:
        printf("\nEnter 1 to enter more files and 0 to exit: ");
        scanf("%d", &c);

    } while(c == 1);

    return 0;
}

