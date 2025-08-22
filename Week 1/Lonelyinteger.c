#include <stdio.h>
#include <stdlib.h>

int findUnique(int size, int* numbers) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= numbers[i];
    }
    return result;
}

int main() {
    int count;
    scanf("%d", &count);

    int* values = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        scanf("%d", &values[i]);
    }

    int unique = findUnique(count, values);
    printf("%d\n", unique);

    free(values);
    return 0;
}
