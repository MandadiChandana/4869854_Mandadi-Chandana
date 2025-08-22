#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char* gridChallenge(int n, char** grid) {
    for (int i = 0; i < n; i++) {
        size_t len = strlen(grid[i]);
        qsort(grid[i], len, sizeof(char), compareChar);
    }

    for (int col = 0; col < strlen(grid[0]); col++) {
        for (int row = 1; row < n; row++) {
            if (grid[row][col] < grid[row - 1][col]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        char** grid = malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            grid[i] = malloc(1024 * sizeof(char));
            scanf("%s", grid[i]);
        }

        printf("%s\n", gridChallenge(n, grid));

        for (int i = 0; i < n; i++) free(grid[i]);
        free(grid);
    }

    return 0;
}
