#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[50], i, st, j, len, c;

    // Initialize all blocks as free (0)
    for(i = 0; i < 50; i++)
        f[i] = 0;

    do {
        printf("\nEnter the starting block & length of file: ");
        scanf("%d%d", &st, &len);

        // Check if blocks are available
        for(j = st; j < (st + len); j++) {
            if(f[j] == 0) {
                f[j] = 1;
                printf("\n%d -> Allocated", j);
            } else {
                printf("\nBlock %d is already allocated!", j);
                break;
            }
        }

        if(j == (st + len))
            printf("\nThe file is allocated to disk successfully.");

        printf("\nDo you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);

    } while(c == 1);

    return 0;
}

